# Wifi Shield Programming Tutorial

**The Wifi shield and these docs are still in beta, if you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new).**

##Overview
The OpenBCI Wifi Shield can be programmed over the air or through a direct connection to the serial port on the wifi shield itself. Over the air is the preferred way to update your WiFi Shield. For the wired programming, you can use the USB dongle that comes with the Cyton as a pass through or you can use a standard [FTDI UART to USB Breakout board](http://docs.openbci.com/Hardware/12-Wifi_Programming_Tutorial#wifi-shield-programming-tutorial-program-openbci-wifi-with-ftdi-boards).

## Program OpenBCI WiFi Over The Air

**CRITICAL: REMOVE THE WIFI SHIELD FROM CYTON OR GANGLION. KEEP BOARD ISOLATED DURING UPDATE**

Download the latest stable released binary from the [Github page](https://github.com/OpenBCI/OpenBCI_WIFI/releases/latest). Save to downloads folder.

### Mac

Go to http://OpenBCI-2F0E.local/update where `2F0E` is your devices unique identifier. You may use the _windows_ ip based instructions.

### Windows/Linux

Get the ip address of your wifi shield and visit http://192.168.0.1/update.

### Uploading The Firmware

Be sure that the WiFi Shield is not **physically** connected to either a Ganglion or Cyton.

Select choose file and navigate to your Downloads folder where the recently downloaded hex file is, select the hex file and press ok. Then hit the `upload` button, the shield will accept the firmware and reboot.

## Compile source code Program OpenBCI Wifi with Arduino

**You will need:**

* Computer (Windows or Mac or Other)
* OpenBCI [Wifi Shield firmware](https://github.com/OpenBCI/OpenBCI_WIFI)
* [Arduino IDE Version 1.8.2](http://www.arduino.cc/en/main/software)
* Custom [ESP8266 libraries with SPISlave](https://github.com/esp8266/Arduino)

**Steps:**

1. Download and install the [Arduino IDE Version 1.8.2](http://www.arduino.cc/en/main/software).

   On Windows be sure to download the file marked `Windows Installer`.

   On Mac download the `MAC OS X` version, unzip the app and move it into Applications folder.

2. Follow the instructions for downloading the [Arduino ESP8266 core from Boards Manager](https://github.com/esp8266/Arduino). **NOTE** because `SPISlave.h` is newly added to the official SDK, be sure to use 2.4.0 or newer!

## Compile Source Code with make

While developing this firmware, we found it much better to use [makeESPArduino](https://github.com/plerup/makeEspArduino) which is a command line tool for building and compiling the firmware without having to use the Arduino IDE! Use the `makeESPWifiDefault.mk` file in the [WiFi's githuv repo](https://github.com/OpenBCI/OpenBCI_WIFI)

## Program OpenBCI Wifi with FTDI Boards

There are many, many FTDI chip breakouts and cables out there that you can use. Here are a couple examples of popular devices.

### FTDI Friend
![FTDI Friend](../assets/images/FTDI_Friend.jpg)
![FTDI Friend Back](../assets/images/FTDI_FriendBack.jpg)

Another example would be the [FTDI Friend](http://www.adafruit.com/products/284) from Adafruit. I cut the trace on the RTS and 5V pads as well. These are the correct settings for uploading to ESP8266 using FTDI Friend. These breakouts are awesome and how the board was developed.

### FTDI Basic Breakout
![FTDI BasicFront](../assets/images/FTDI_BASICfront.jpg)
![FTDI BasicBack](../assets/images/FTDI_BASICback.jpg)

Sparkfun makes an FTDI breakout as well, and they come in a couple of flavors. 5V and 3V. By now, you know that you want the [3V Version](https://www.sparkfun.com/products/9873). [pic coming soon] Also, if you have a version of this board with a voltage selection on the back, make sure that it has the 3.3V pads connected and the 5V pads cut!  

### OpenBCI Cyton Dongle

The OpenBCI Dongle can be used to upload firmware to ESP8266. [See the section](http://docs.openbci.com/Hardware/06-Cyton_Radios_Programming_Tutorial#cyton-radios-programming-tutorial-uploading-device-firmware-to-cyton-board-upload-pass-thru-radio-firmware-version-2xx-fall-2016) on how to [pass through the code](http://docs.openbci.com/Hardware/06-Cyton_Radios_Programming_Tutorial#cyton-radios-programming-tutorial-uploading-device-firmware-to-cyton-board-program-device-radio-with-openbci-dongle) in the [Cyton Radio Programming Guide](http://docs.openbci.com/Hardware/06-Cyton_Radios_Programming_Tutorial).

## Wired upload

### Getting the board in boot-loading mode

Wether you are using `makeESPArduino` or the Arduino IDE, the steps to get the board into boot-loading are as follows.

Remove your Wifi Shield from the Cyton/Ganglion board.

![Wifi alone](../assets/images/wifi_programming_alone.jpg)

First, plug in battery to the wifi shield

![Battery to wifi shield](../assets/images/wifi_programming_power.jpg)

Second power the Wifi shield

![Battery to wifi shield](../assets/images/wifi_programming_power_in.JPG)

Then press and hold the `RESET` button.

![Wifi programming hold reset](../assets/images/wifi_programming_hold_reset.jpg)

Then press and hold the `PROG` button.

![Wifi programming hold prog](../assets/images/wifi_programming_hold_prog.jpg)

Release the `RESET` button

![Wifi programming release reset](../assets/images/wifi_programming_release_reset.jpg)

And finally release the `PROG` button

![Wifi programming release reset](../assets/images/wifi_programming_release_prog.jpg)

Now the board is ready to get hit with some new firmware!

Hook up the FTDI friend to the Wifi Shield, don't power the Wifi shield through the FTDI friend, it will not supply enough power!

|FTDI_Friend|Wifi Shield|
|-----------|-----------|
|GND|GND|
|RX|TX|
|TX|RX|

![Wifi to FTDI friend](../assets/images/wifi_programming_ftdi_friend_hooked_up.jpg)

Now upload using either the Arduino IDE or a custom make solution.

## Sending Data to WiFi Shield

### Overview

The WiFi Shield acts a SPI slave device to the Cyton or Ganglion. The max speed the ESP8266 can seem to handle is 10MHz. A [SPISlave example](https://github.com/esp8266/Arduino/blob/master/libraries/SPISlave/examples/SPISlave_Test/SPISlave_Test.ino) we based our [Wifi](https://github.com/OpenBCI/OpenBCI_WIFI/blob/master/examples/DefaultBoard/DefaultBoard.ino) code on. To interact with this SPI slave library, (you wanted to use this WiFi Shield for some other reason...) you should look at the [SPI Master example](https://github.com/esp8266/Arduino/blob/master/libraries/SPISlave/examples/SPISlave_Master/SPISlave_Master.ino) because the commands to get data vs read a status register are strictly defined and must be followed. The first constraint the Arduino ESP8266 SPI slave places on us is to always send 32 bytes per message. This library says that each packet must be 32 bytes, so that's where we begin....

### Byte Stream Format
The first byte to send is the control byte. For streaming data, that goes on the TCP socket, send `0xCX` (where `X` is `0-F` in hex) as the control byte. In the `OpenBCI_32bit_Library` code base:

~~~
/*  
 * @description Writes channel data and axisData array to serial port in
 *  the correct stream packet format.
 */
void OpenBCI_32bit_Library::sendChannelDataWifi(void)  {

    wifiStoreByte(OPENBCI_EOP_STND_ACCEL); // 0xC0 1 byte

    wifiStoreByte(sampleCounter); // 1 byte

    ADS_writeChannelDataWifi(); // 24 bytes

    accelWriteAxisDataWifi(); // 6 bytes

    wifiFlushBuffer(); // Flushes the buffer to the SPISlave ESP8266 device!

    sampleCounter++;

}
~~~  

This code writes 32 bytes of data in the correct format and therefore as soon as it arrives at the WiFi Shield. The WiFi Shield will convert the 32 byte packet to the standard 33 byte [binary format](http://docs.openbci.com/Hardware/03-Cyton_Data_Format#cyton-data-format-binary-format) by moving the control byte `0xCn`, where `n` is `0-F` (hex), to the stop position and add add `0xA0` to the start position. This allows for a seamless integration with the tried and tested parsing systems already built for the Cyton.
**Important** if you want to only send `20` bytes of data per packet, you still must send this `32` bytes with the proper start and stop bytes.
