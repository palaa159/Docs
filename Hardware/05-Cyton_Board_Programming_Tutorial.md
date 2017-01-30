#Cyton Board Programming Tutorial

##Overview
The OpenBCI Cyton boards have powerful microcontrollers on them which ship with the latest OpenBCI firmware to interface with the on-board ADS1299, Accelerometer, and SD card. This tutorial explains how to program the firmware using the OpenBCI Dongle and you PC. If we come out with a firmware upgrade, or if your or someone comes up with a custom program that you want to implement, you should use the following method. We made major changes to the Cyton firmware in 2016. This tutorial covers the v2, as well as v1. If you have already mucked about in the code using the v1 firmware, and want to upgrade, check out the [Notes](http://docs.openbci.com/Hardware/05-Cyton_Board_Programming_Tutorial#cyton-board-programming-tutorial-notes-on-updating-and-using-v200-cyton-firmware) at the end of this doc. Happy Hacking!


## Firmware Version 2.x.x (Fall 2016)
**You will need:**

* Computer running [Arduino v1.8.0](https://www.arduino.cc/en/Main/Software) or later
* OpenBCI Dongle connected to USB port
* OpenBCI Cyton Board with battery power

![OpenBCI Dongle](../assets/images/dongleConnection.png)

***Note***: Always plug the Dongle into the PC before powering the Board because the Host (RFduino on the Dongle) must be powered before the Device (RFduino on the Board).

* install the Arduino IDE which can be found here:

	[https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

**Note for Windows users** While installing Arduino 1.8, if the installer instructs you to uninstall 1.5.8, move the Arduino folder containing 1.5.8 from `Program Files` to your desktop or another folder. Rename this folder to `Arduino_1.5.8`. Open the `Change or remove program` app in control panel and uninstall the Arduino application. There will be a popup indicating that the files do not exist and asking if you want to remove the program from the files list, select yes. Then install 1.8.0 as normal. Navigate to back to your `Program Files` folder and locate the Arduino folder. Rename this folder to `Arduino_1.8.0`. Now drag and drop the `Arduino_1.5.8` back into `Program Files` folder.  

* Download the [OpenBCI_32bit_Library Firmware](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/master) repo from our github.

* Unzip the folder, and if it is named `OpenBCI_32bit_Library-master`, rename it to just `OpenBCI_32bit_Library`.

* Now move the `OpenBCI_32bit_Library` folder from your downloads into:

  On Mac:
`Documents/Arduino/libraries`  
  On Windows:
`C:\Users\username\Documents\Arduino\libraries`

	If there is no `libraries` folder in the sketch folder, create one.

* Download the [OpenBCI_32bit_SD](https://github.com/OpenBCI/OpenBCI_32bit_SD/archive/master.zip) repo from our github.

* Unzip the folder.

* Now move the folder called `OBCI32_SD` and everything it contains to:

  On Mac: `/Documents/Arduino/libraries`  
  On Windows: `C:\Users\username\Documents\Arduino\libraries`


* Before you can upload code correctly to the PIC32 with Arduino, you need to add the chipKIT-core board files to your Arduino IDE. The folks at chipKIT have put together instructions on how to [Auto Install via URL from within Arduino](http://chipkit.net/wiki/index.php?title=ChipKIT_core#1.29_Auto_install_via_URL_from_within_Arduino_IDE_.28latest_version_chipKIT-core_v1.3.1.29). Follow the process in the previous link, and you will be able to select the OpenBCI board from the Tools >> Board >> dropdown menu!

![board_dropdown](../assets/images/OBCI32_Board_Dropdown.png)

* In the Arduino IDE go to `File-->Examples-->OpenBCI_32bit_Library-->DefaultBoard` which will launch the Host firmware. **NOTE You must upload ONLY the `DefaultBoard` Sketch!**

* Make sure that the slide switch on the OpenBCI Dongle is switched to the GPIO6 selection. If it's on the other side, it will try to program the Dongle-mounted RFduino! Now is a good time to plug your Dongle in and power down the Board.

![serial_port](../assets/images/PortSelect.png)

* Select the correct serial port for your OpenBCI Dongle.

	* On Macs, this will be named **/dev/tty.usbserial-DN00nnnn** where the nnnn is a combination of numbers and letters specific to your openBCI Dongle.

	* On Windows, the serial port will be listed as a numbered COM port.

	* On Linux, it will be different.

* When you are happy with the code, you will have to put the 32bit board into bootloader mode. We don't have a way to remotely reset the chipKIT compatible IC, so you have to do it manually with the proceedure that follows:

![reset_program](../assets/images/RST_PROG.png)

  1. Power OFF the OpenBCI Board.
  2. Press down both RST and PROG buttons at the same time.
  3. Power ON the OpenBCI Board.
  4. Release the RST button while still holding down the PROG button.
  5. Release the PROG button.

![Upload32](../assets/images/Upload32.png)

* Verify that you see the blue LED on the 32bit board blinking pleasantly.

* Press the upload button on the Arduino IDE.

That's it! You will see some blinky lights on the Dongle, and after a short while, the Arduino IDE will tell you that it's done. Happy Hacking!

## Firmware Version 1.x.x (2014 - Fall 2016)

**You will need:**

* Computer running [Arduino v1.8.0](https://www.arduino.cc/en/Main/Software) or later
* OpenBCI Dongle connected to USB port
* OpenBCI Cyton Board with battery power

![OpenBCI Dongle](../assets/images/dongleConnection.png)

***Note***: Always plug the Dongle into the PC before powering the Board because the Host (RFduino on the Dongle) must be powered before the Device (RFduino on the Board).

First, install the Arduino IDE which can be found here:  

[https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

**Note for Windows users** While installing Arduino 1.8, if the installer instructs you to uninstall 1.5.8, move the Arduino folder containing 1.5.8 from `Program Files (x86)` to your downloads folder. Rename this folder to `Arduino_1.5.8`. Open the `Change or remove program` app in control panel and uninstall the Arduino application. There will be a popup indicating that the files do not exist and asking if you want to remove the program from the files list, select yes. Then install 1.8.0 as normal. Navigate to back to your `Program Files (x86)` folder and locate the Arduino folder. Rename this folder to `Arduino_1.8.0`. Now drag and drop the `Arduino_1.5.8` back into `Program Files (x86)` folder.  

You can find the previous OpenBCI firmware and libraries on our github repository.

	https://github.com/OpenBCI/OpenBCI_32bit

	https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/maint/1.0.0

* OpenBCI_32bit
	* This is the firmware that runs on the OpenBCI 32bit Board
* OBCI_SD
	* Supports writing raw data to on-board SD card
* OpenBCI_32_Daisy
	* The OpenBCI 32bit Library

You will need to install the folders 'OpenBCI_32_Daisy' and 'OBCI_SD' from our Libraries repository into your Documents/Arduino/libraries folder. If there is no 'libraries' folder in the sketch folder, create one. Move the folder called 'OpenBCI_32bit' into your Documents/Arduino folder.

Before you can upload code correctly to the PIC32 with Arduino, you need to add the chipKIT-core board files to your Arduino IDE. The folks at chipKIT have put together instructions on how to [Auto Install via URL from within Arduino](http://chipkit.net/wiki/index.php?title=ChipKIT_core#1.29_Auto_install_via_URL_from_within_Arduino_IDE_.28latest_version_chipKIT-core_v1.3.1.29). Follow the process in the previous link, and you will be able to select the OpenBCI board from the Tools >> Board >> dropdown menu!

![board_dropdown](../assets/images/OBCI32_Board_Dropdown.png)

Open the OpenBCI_32bit sketch from the File -> Sketchbook dropdown. Then select OpenBCI 32 from the Board drop-down menu.

Make sure that the slide switch on the OpenBCI Dongle is switched to the GPIO6 selection. If it's on the other side, it will try to program the Dongle-mounted RFduino! Now is a good time to plug your Dongle in and power down the Board.

![serial_port](../assets/images/PortSelect.png)

Select the correct serial port for your OpenBCI Dongle.

* On Macs, this will be named **/dev/tty.usbserial-DN00nnnn** where the nnnn is a combination of numbers and letters specific to your openBCI Dongle.

* On Windows, the serial port will be listed as a numbered COM port.

* On Linux, it will be different.

When you are happy with the code, you will have to put the 32bit board into bootloader mode. We don't have a way to remotely reset the chipKIT compatible IC, so you have to do it manually.

![reset_program](../assets/images/RST_PROG.png)

* Power OFF the OpenBCI Board.
* Press down both RST and PROG buttons at the same time.
* Power ON the OpenBCI Board.
* Release the RST button while still holding down the PROG button.
* Release the PROG button.

![Upload32](../assets/images/Upload32.png)

Now you should see the blue LED on the 32bit board blinking pleasantly. Press the upload button on the Arduino IDE. That's it! You will see some blinky lights on the Dongle, and after a short while, the Arduino IDE will tell you that it's done. Happy Hacking!


##8bit Upload How-To
###NOTE: The 8bit Hardware is no longer in production
**You will need:**

* Computer running Arduino IDE
* OpenBCI Dongle connected to USB port
* OpenBCI 8bit Board with battery power

![OpenBCI Dongle](../assets/images/dongleConnection.png)

Make sure that the slide switch on the OpenBCI Dongle is switched to the GPIO6 selection. That way the DTR reset signal will get passed over-air to the ATmega328. If it's on the other side, it will try to program the Dongle-mounted RFduino!  
You can find the latest firmware and libraries on our github repository

https://github.com/OpenBCI/OpenBCI_8bit

You will need to install these files from our repository into your Documents/arduino/libraries folder

* SdFat
    * Supports writing raw data to on-board SD card
* OpenBCI_8
    * The OpenBCI 8bit Library


![ArduinoIDE](../assets/images/Arduino_IDE.png)

Move the file OpenBCI_8bit_SD.ino into your Documents/arduino folder, and start up the Arduino IDE. you should then see the sketch in your Sketch folder.

![selectBoardUno](../assets/images/BoardSelect.png)

Select Arduino UNO from the Board drop-down menu.

![selectSerialPort](../assets/images/SerialPortSelect.png)

Select the correct serial port for your OpenBCI Dongle.

* On Macs, this will be named **/dev/tty.usbserial-DN00nnnn** where the nnnn is a combination of numbers and letters specific to your openBCI Dongle.

* On Windows, the serial port will be listed as a COM port.

* On Linux, it will be different.

![Upload](../assets/images/Upload.png)

When you are happy with the code, simply press upload to program the OpenBCI 8bit target. That's it! You will see some blinky lights on the Dongle, and after a short while, the Arduino IDE will tell you that it's done.

## Troubleshooting

If you're having an issue with `Board_Defs.h` and you're uploading using Linux, you must move ALL files located in: <br/> `/Arduino/hardware/chipkit-core/pic32/variants/openbci/` to `/Arduino/hardware/chipkit-core/pic32/cores/pic32/`<br/> This should fix any issues you're having compiling.


If the upload fails with `No Target Found`:

1. Unplug the Dongle and Device.
2. Plug the Dongle into your computer.
3. Plug the Device into your computer.
4. Put the device into bootloader mode.
5. Try upload again.

If the upload fails with `Program Flash Failed` it's due to the Arduino IDE not being able to read from the serial port fast enough possibly do to resource starvation or overall computer power. We recommend taking the following actions:

* Keep the Board and Dongle physically close to each other during the upload.
* Keep the Arduino IDE open, front and center and don't use any other programs during the upload.
* Close all open programs such as (Google Chrome, MS Word, etc...) and only have the Arduino 1.6.5 IDE open during upload.
* Restart your computer and don't open any other programs other than the Arduino IDE used for programming.
* If all else fails, find a friend with a more powerful computer and do the uploading from their computer.

In extreme conditions, if you have tried all five of the above methods and still can't upload, then you can try to change the Device's polling time. The Poll Time can be adjusted using the OpenBCI Radio Config Utility software (*Tutorial coming soon!*)   


## Notes On Updating and Using v2.0.0 Cyton Firmware

### Overview
The OpenBCI Cyton boards were updated with new firmware across all three main microcontrollers, the Pic 32 ([`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino)) and both RFduinos on the Dongle ([`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino)) and the Board ([`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino)). This tutorial does not explain how to program the firmware using the OpenBCI Dongle and `PC`; you will want to refer to the tutorials [Cyton Board Programming Tutorial](http://docs.openbci.com/Hardware/05-Cyton_Board_Programming_Tutorial) and [Cyton Radios Programming Tutorial](http://docs.openbci.com/Hardware/06-Cyton_Radios_Programming_Tutorial). If you have spent a lot of time writing custom Arduino code to run on the OpenBCI, then you will find this tutorial helpful in upgrading to get the new stability and features of the 2.0.0 firmware.

### Sending data packets from the Pic32 to the PC
At 250Hz, we are at the upper limit of the physical hardware. The [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) RFduino must send data packets as soon as it get's them from the [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) because of the slow serial baud rate between [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) and [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) (`115200 baud`, a faster baud rate messes up the radio on the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino)). On the other hand, over the air programming must be able to combine multiple radio packets together into one page and write at one time, therefore, over the air programming must wait to see if it received all data over the serial port before sending. These two requirements led to the original firmware being stateful, where the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) and [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) would be in either `streaming` or `not streaming` mode. This led to problems and could result in the `PC` not being able to contact the `Cyton ` because the radios were stuck in streaming mode and the reset button on the `Cyton ` is not tied to the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) so one would have to power cycle the entire `Cyton`.

### An Example
Let's say you want to send custom data from the `Cyton` to the `PC`. In order to do that simply wrap the data with the correct start byte, `0x41`, and stop byte, `0xCX` (where `X` is `0-F` in hex). In the `OpenBCI_32bit_Library` code base: 
 
~~~
/*  
 * @description Writes channel data and axisData array to serial port in
 *  the correct stream packet format.
 *
 *  Adds stop byte OPENBCI_EOP_STND_ACCEL. See OpenBCI_32bit_Library_Definitions.h
 */
void OpenBCI_32bit_Library::sendChannelDataWithAccel(void)  {

    Serial0.write('A'); // 0x41 1 byte

    Serial0.write(sampleCounter); // 1 byte

    ADS_writeChannelData(); // 24 bytes

    accelWriteAxisData(); // 6 bytes

    Serial0.write(OPENBCI_EOP_STND_ACCEL); // 0xC0 1 byte

    sampleCounter++;

}
~~~  

This code writes 33 bytes of data from the [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) to the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) in the correct format and therefore as soon as it arrives at the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) it will be sent to the [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) and to the `PC`. New to firmware version 2 is the ability to have different stop bytes, in the original firmware, one could only send stop bytes of `0xC0` however now, we can send `0xCn` where `n` is `0-F` (hex).  
**Important** if you want to only send `20` bytes of data per packet, you still must send this `33` bytes with the proper start and stop bytes. Sending data too fast will result in a buffer overflow on the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) and cause the system to restart and send an error message to the [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) and `PC`.

### Sending one byte of data every 10ms or 100Hz
Here is an example taken from the file called `BoardWithCustomData.ino` from the `examples` folder in the `OpenBCI_32bit_Library` repo.

```
void sendLEDStatus() {
  // Must have header byte
  Serial0.write('A'); // 0x41 1 byte
  // Write the LED state
  Serial0.write(LEDState); // 1 byte
  // Fill the rest with fake data
  for (int i = 0; i < 30; i++) {
    Serial0.write(0x00);
  }
  // Send a stop byte with an `B` or `1011` in the last nibble to indicate a
  //  different packet type.
  Serial0.write(0xCB); // 1 byte
}
```
As you can see above, we only really want to send 1 byte, but if we want to do it fast, at this 100Hz rate, we must wrap it in the start byte and stop byte to tell the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) to send the packet as soon as it get's the stop byte.

### Adopting the new Pic32 code paradigm
We drastically reduced the complexity of the `.ino` files in order to make custom device programming more approachable for new programmers but also add a suite of features to give great power to great programmers. We have created an environment to drive contribution to the main project in the form of examples. If you want to contribute code the main library for others to use, now you can simply do a pull request. Joel was able to adapt his [pulse sensor code](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithPulseSensor/BoardWithPulseSensor.ino) to the new firmware in about 20 minutes! Now anyone who downloads the firmware, will get the pulse sensor code versus having to dig through all the `OpenBCI` repos to find an example of [how to use a pulse sensor](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithPulseSensor/BoardWithPulseSensor.ino), [have external triggers](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWith2ButtonExternalTriggers/BoardWith2ButtonExternalTriggers.ino), [read an analog input](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithAnalogSensor/BoardWithAnalogSensor.ino), etc...

Please dig through the [`examples`](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/master/examples) folder on the [`OpenBCI_32bit_Library`](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/master) for a deep dive into all the possibilities with the new code. Remember if you have new code you want to share, please do!! [Make a pull request](https://help.github.com/articles/creating-a-pull-request/)!
