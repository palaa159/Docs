### OpenBCI V3 Data Format

This discussion of the OpenBCI data format only applies to OpenBCI V3 (2014). For OpenBCI V3, the OpenBCI board contains either a Atmel or ChipKIT microcontroller that can be programmed through the Arduino IDE and Microchip's MPIDE, respectively. The OpenBCI board also contains an RFDuino acting as a subordinate "Device". The OpenBCI system also includes a USB dongle for the PC, which acts as the RFDuino "Host". The format of the OpenBCI data as seen on the PC is defined by a combination of the Arduino code on the OpenBCI board and of the RFDuino code running on the Host. So, if you don't like the data format defined here, feel free to change the code for yourself!

### Proprietary ("RFDuino") vs Standard Bluetooth

OpenBCI uses RFDuino modules for its Bluetooth wireless connection. To achieve the highest data rates, OpenBCI supplies a RFDuino USB dongle that connects to the computer. When using this USB dongle, higher data rates can be achieved versus using a standard bluetooth connection. So, using the dongle, you can receive all 8 channels of EEG data. It is this format that is defined below.

If you prefer to use a standard bluetooth connection (to a mobile phone, for instance), that software and data format has not yet been defined.

### Serial Setup

The RFDuino USB dongle (the RFDuino "Host") is configured to appear to the computer as if it is a standard serial port running at a rate of 115200 baud using the typical 8-N-1 serial setup.

### Startup

When you first connect your PC application to the serial port for the RFDuino dongle, it reaches through over the Bluetooth link to the remote OpenBCI board and restarts the board. After a second or two, you will see the OpenBCI board generate a bunch of lines of ASCII text to describe how the OpenBCI board has been configured. If you are writing client software for the PC, your software must tolerate an unpredictable amount of this initial text.

### Initiating Binary Transfer

Once the OpenBCI has completed this startup, it waits for commands. In other words, it sends no data until it is told to start sending data. To begin data transfer, transmit a single ASCII b. Once the b is received by the Arduino, it might issues a text string in response and then it will begin the continuous transfer of OpenBCI data in binary format.

### Binary Format

The data is sent in packets (or frames, depending upon your preferred word). Each packet contains a header followed by a sample counter, followed by one 3 byte sample for each of the 8 EEG channels, followed by one 2 byte sample for each of the three axes of the accelerometer, followed by a footer. The accelerometer data are optional, and don't need to be sent with every packet if used. This allows for user defined auxiliary data to be sent in the last six bytes before the footer. Here are details on the format.

**Header** 
 
* Byte 0: 0xA0  
* Byte 1: Packet counter

**EEG Data**  
Note: values are 24-bit unsigned int, MSB first

* Bytes 2-4: Data value for EEG channel 1  
* Bytes 5-7: Data value for EEG channel 2  
* Bytes 8-10: Data value for EEG channel 3  
* Bytes 11-13: Data value for EEG channel 4  
* Bytes 14-16: Data value for EEG channel 5  
* Bytes 17-19: Data value for EEG channel 6  
* Bytes 20-22: Data value for EEG channel 6  
* Bytes 23-25: Data value for EEG channel 8  

**Accelerometer Data**  
Note: values are 16-bit int, MSB first

* Bytes 26-27: Data value for accelerometer channel X  
* Bytes 28-29: Data value for accelerometer channel Y  
* Bytes 30-31: Data value for accelerometer channel Z  

**Footer**  

* Byte 32: 0xC0

### 24-Bit Data Values

For the EEG data values, you will note that we are transferring the data as a 24-bit unsigned integer, which is a bit unusual. We are using this number format because it is the native format used by the ADS1299 EEG chip that is at the core of the OpenBCI board. To convert this unusual number format into a more standard 32-bit signed integer, you can steal some dieas from the example Processing (aka, Java) code below:

    int interpret24bitAsInt32(byte[] byteArray) {     
     int newInt = (  
         ((0xFF & byteArray[0]) << 16) |  
         ((0xFF & byteArray[1]) << 8) |   
         (0xFF & byteArray[2])  
       );  
     if ((newInt & 0x00800000) > 0) {  
       newInt |= 0xFF000000;  
     } else {  
       newInt &= 0x00FFFFFF;  
     }  
    return newInt;  
    }  

### Interpreting the EEG Data

Once you receive and parse the data packets, it is important to know how to interpret the data so that the EEG values are useful in a quantitative way. The two critical pieces of information are (1) the sample rate and (2) the scale factor.

For the sample rate, we set the default rate to 250 Hz. Faster rates are supported by the ADS1299 EEG chip at the heart of the OpenBCI board, but the RFDuino wireless link might not be able to keep up with faster sample rates. If you give it a try, let us know how it worked!

For the scale factor, this is the multiplier that you use to convert the EEG values from “counts” (the int32 number that you parse from the binary stream) into scientific units like “volts”. By default, our Arduino sketch running on the OpenBCI board sets the ADS1299 chip to its maximum gain (24x), which results in a scale factor of 0.02235 microVolts per count. Because the gain is user-configurable (24x, 12x, 8x, 6x, 4x, 2x, 1x), the scale factor could be different, if one makes the correct alteration to the Arduino sketch. If the gain is changed, the equation that you should use for determining the scale factor is:

`Scale Factor (Volts/count) = 4.5 Volts / gain / (2^23 - 1);`

Note that 2^23 might be an unexpected term in this equation considering that the ADS1299 is a 24-bit device. This equation is from the ADS1299 datasheet, specifically it is from the text surrounding Table 7. This scale factor has also been confirmed experimentally using known calibration signals.