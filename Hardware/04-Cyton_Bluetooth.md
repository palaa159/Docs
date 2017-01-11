# Cyton Bluetooth

This discussion of the OpenBCI Bluetooth specifics applies to OpenBCI Cyton V3 (2014) Hardware. For OpenBCI V3, the Cyton board contains either a Atmel or ChipKIT microcontroller that can be programmed through the Arduino IDE. The Cyton board also contains an RFDuino. There is not currenty firmware support for BLE connection to tablets or phones with Bluetooth 4.n capability. As that changes this doc will be updated.

### RFDuino In A Nutshell

OpenBCI Cyton uses RFDuino modules for its Bluetooth wireless connection. RFduinos are built on the Nordic nRF51822 SoC Radio IC. To achieve the highest data rates, OpenBCI supplies a RFDuino USB dongle that connects to the computer. When using this USB dongle, both radios use the RFduinoGZLL library, which is based on Nordic's proprietary high speed Gazelle stack. This is the default configuration of the RFduino firmware, and allows for general serial communication between the PC and the Cyton board, while also supporting OpenBCI streaming data mode, and over-air programming of the Arduino compatible chipKIT or Atmega.

If you want to get the Cyton Board to communicate to an Android or iOS phone or tablet with Bluetooth 4.n (LE), the RFduinoBLE library must be used. This can present a problem, in that when using BLE it is not possible to upload new firmware to the target chipKIT or ATmega uC. To facilitate firmware development, we have provided a switch on the OpenBCI board to select between PC (RFduinoGZLL) and BLE (RFduinoBLE). In the BLE position, the switch activates a pull-up on GPIO-4 of the RFduino module. The idea here is that the firmware would take note of GPIO-4 during the setup routine, begin either the BLE or GZLL stack, and run the appropriate code.

**NOTE: this is not implemeted yet! The current Radio Firmware only uses RFduinoGZLL library** 

### RFduino Firmware Update

Please see the [Radios](http://docs.openbci.com/Hardware/06-Cyton_Radios_Programming_Tutorial) page for notes on changing the firmware on our RFduino modules.

### Cyton BLE Data Format

**Cyton BLE Data Format is undefined**. For those interested in defining it, there are some issues that must be taken into account. 

First, the maximum number of bytes per BLE radio packet is 20. This limits the number of channels of raw data that can be sent without down-sampling or compression.

Second, the data rate is limited. When using RFduinoGZLL, data rates of 130kB/S are theoretically possible. Our OpenBCI Boards sample biosignals at 250SPS and thier serial connection runs at 115200 baud. When using RFduinoBLE, implemnting serial baud rates higher than 9600 is possible, but may lead to issues. The BLE data rate is also alot slower. (We'll post our findings here when we get adequate benchmark results).

### Android Example

So far, we have one example in Android that connects to the Cyton Board and creates a .csv file to hold the incoming data. This has only been tested with dummy data.
[Android <> OpenBCI Prototype](https://github.com/yasser304/OpenBCI-AndroidApp)

### iOS Example

Undefined
