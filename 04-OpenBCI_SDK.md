# OpenBCI SDK
The OpenBCI boards communicate using an ASCII command protocol. This Doc covers command use for the OpenBCI 8bit and 32bit boards. Some of the commands are board specific, where noted. 

## OpenBCI 8bit Command Protocol Overview

OpenBCI boards have two powerful microcontrollers on board, and come pre-programmed with the firmware. The RFduino radio link uses the Nordic Gazelle stack and library. The Board mounted RFduino is configured as a DEVICE. The microcontroller (ATmega328P or PIC32MX250F128B) has been programmed with firmware that interfaces between the ADS1299 (Analog Front End), LIS3DH (Accelerometer) and RFduino (Radio module). The user, or PC, controls the board by sending ASCII character commands over wireless serial connection. You should have received a Dongle with the OpenBCI 8bit board. The Dongle has an RFduino running Gazelle configured as a HOST, and interfaces your computer as a Virtual Com Port (FTDI). (See the Radios portion for more info on the RFduino link).
On startup, the OpenBCI board sends the following text over the radio:

	OpenBCI V3 8bit Board
	Setting ADS1299 Channel Values
	ADS1299 Device ID: 0x3E
	LIS3DH Device ID: 0x33
	$$$

Device ID info is useful for general board health confirmation. The $$$ is clear indication to the controlling PC that the message is complete and the OpenBCI board is ready to receive commands.

## Command Set
###Turn Channels OFF
**1 2 3 4 5 6 7 8**  
These ASCII characters turn the respective channels [1-8] off. The channel will read 0.00 during streamData mode. These commands work in and out of streamData mode.

###Turn Channels ON  
**! @ # $ % ^ &  * **  
These ASCII characters turn the respective channels [1-8] on. The channel will contain ADC values during streamData mode. These commands work in and out of streamData mode.

###Test Signal Control Commands  
**0 - = p [ ]**  
Turn **all** available channels on and connect to internal test signal. These are useful for self test and calibration. For example, you can measure the internal noise by connecting to internal GND. **Note: Not all of the internal test connections are implemented here **
 
* **0**  Connect to internal GND (VDD - VSS)  
* **-**  Connect to test signal 1xAmplitude, slow pulse  
* **=**  Connect to test signal 1xAmplitude, fast pulse  
* **p**  Connect to DC signal  
* **[**  Connect to test signal 2xAmplitude, slow pulse  
* **]**  Connect to test signal 2xAmplitude, fast pulse  


###Channel Setting Commands   
** x (CHANNEL, POWER_DOWN, GAIN_SET, INPUT_TYPE_SET, BIAS_SET, SRB2_SET, SRB1_SET) X **  
Channel Settings commands have six parameters for each ADS channel. To access Channel Settings, first send **x**. Now the OpenBCI board is expecting the next 7 bytes to be channel settings specific commands. The first byte is the channel number. (If you have the Daisy Module, you can select up to 16 channels to set). The following six ASCII characters are accepted as parameters. Lastly, sending **X** will latch the settings to the ADS channel. It is required that you allow a time delay (>10mS)when sending the commands and parameters in order for the radios to pass the characters through with the correct OpenBCI protocol.

**CHANNEL**

* **1 2 3 4 5 6 7 8**  for single board channel select
* **Q W E R T Y U I**  for selecting channels on the Daisy Module

**POWER_DOWN**
 
* 0 = ON (default)
* 1 = OFF    

**GAIN_SET** 

* 0 = Gain 1
* 1 = Gain 2
* 2 = Gain 4
* 3 = Gain 6
* 4 = Gain 8
* 5 = Gain 12
* 6 = Gain 24	(default)


**INPUT_TYPE_SET**  
Select the ADC channel input source  


* 0        ADSINPUT_NORMAL     	(default)  
* 1        ADSINPUT_SHORTED          
* 2        ADSINPUT_BIAS_MEAS  
* 3        ADSINPUT_MVDD  
* 4        ADSINPUT_TEMP  
* 5        ADSINPUT_TESTSIG  
* 6        ADSINPUT_BIAS_DRP  
* 7        ADSINPUT_BIAS_DRN  
  
**BIAS_SET**  
Select to include the channel input in BIAS generation. 
 
* 0 = Remove form BIAS
* 1 = Include in BIAS  (default)  
  
**SRB2_SET**  
Select to connect this channel's P input to the SRB2 pin. This closes a switch between P input and SRB2 for the given channel, and allows the P input also remain connected to the ADC.  

* 0 = Disconnect this input from SRB2
* 1 = Connect this input to SRB2  (default)  
  
**SRB1_SET**  
Select to connect all channels' N inputs to SRB1. This effects all pins, and disconnects all N inputs from the ADC.  

* 0 = Disconnect all N inputs from SRB1 (default)
* 1 = Connect all N inputs to SRB1  
 
**EXAMPLE**

User sends **x  3  0  2  0  0  0  0  X** 

'x' enters Channel Settings mode. Channel 3 is set up to be powered up, with gain of 2, normal input, removed from BIAS generation, removed from SRB2, removed from SRB1. The final 'X' latches the settings to the ADS1299 channel settings register.

###Default Channel Settings
**d** To set all channels to default  
**D** To get a report of the default settings send.

When you query the default settings, expect to get 6 ASCII characters followed by **$$$**  *Note: Users can change the default channel settings in the initialization function inside the OpenBCI library. Requires re-programming the board*

###LeadOff Impedance Commands  
**z (CHANNEL, PCHAN, NCHAN) Z**  
This works simmilar to the Channel Settings commands. Care must be taken to delay between sending characters. Impedance settings have two parameters for each ADS channel. Impedance is measurable by applying a small AC signal to the given channel. 

* 0 = Test Signal Not Applied (default)
* 1 = Test Signal Applied  

**EXAMPLE**

User sends **z  4  1  0  Z**

'z' enters Impedance Settings mode. Channel 4 is set up to measure impedance on the P input. The final 'Z' latches the settings to the internal impedance registers.

###SD card Commands  
**A S F G H J K L**  
Send to initiate SD card data logging for specified time  
 
* A    =      5MIN  
* S    =      15MIN  
* F    =      30MIN  
* G    =      1HR  
* H    =      2HR  
* J    =      4HR  
* K    =      12HR  
* L    =      24HR  

**j**  
Stop logging data and close SD file  

###Stream Data Commands  
**b**  
Start streaming data 

**s**  
Stop Streaming data  

Please refer to the 

###Miscellaneous  
**?**  
Query register settings  
Read and report all register settings for the ADS1299 and the LIS3DH. Expect to get a verbose serial output from the OpenBCI Board, followed by **$$$**  


##16 Channel Commands
Curretnly, the Daisy Module is functional only on the 32bit board. The Daisy Module adds 8 more input channels. These are the commands specific to controlling the ADS1299 on the Daisy Module.

###Turn Channels OFF
**q w e r t y u i**  
These ASCII characters turn the respective channels [9-16] off. The channel will read 0.00 during streamData mode. These commands work in and out of streamData mode.

###Turn Channels ON  
**Q W E R T Y U I**  
These ASCII characters turn the respective channels [9-16] on. The channel will contain ADC values during streamData mode. These commands work in and out of streamData mode.

###Select maximum channel number

**c**

Use 8 channels only. If the Daisy Module is attached, it will be unattached, and access to only channels 1-8 are available.

**C**

Use 16 channels. 

*Note: On reset, the OpenBCI 32bit board will 'sniff' for the Daisy Module, and if it is present, it will default to 16 channel capability.*

###Unused ASCII Characters
These are curretnly unused characters accross the OpenBCI platforms:

**9 ( ) _ { } o O f g h k l ; : ' " v V n N M , < . > /**
