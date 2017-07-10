# Wifi Getting Started Guide

**The Wifi shield and these docs are still in beta, if you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new).**

##Overview

This guide will walk you through setting up your Wifi Shield, connecting it to your computer, and then connecting it to yourself. The first tutorial is for the Ganglion and the second is for the Cyton. Please review this guide in its entirety before starting. Have fun!

For more information on the Wifi Hardware, visit the [OpenBCI Wifi](http://docs.openbci.com/Hardware/11-Wifi) page in the Hardware section. To update the shield to the latest firmware please visit the [OpenBCI Wifi Programming Tutorial](http://docs.openbci.com/Hardware/11-Wifi_Programming_Tutorial) also in the Hardware section. Make sure to have the latest firmware for the wifi shield!

## Ganglion
### What You Need

![OpenBCI Wifi Contents](../assets/images/wifi_ganglion_what_you_need.jpg)

 1. OpenBCI Wifi Shield
 2. OpenBCI Ganglion Board **IMPORTANT: Must have at least v2.x.x Ganglion firmware or newer!**
 3. 2x LiPo battery or 6V AA battery pack & (x4) AA batteries (batteries not included)
 4. A computer connected to the internet

#### 1. OpenBCI Wifi Shield

![OpenBCI Wifi Shield](../assets/images/wifi_head_shot.jpg)

The battery connector on the back of the Wifi shield can accept 3V to 6V DC power input. The top push button, `RESET`, is a reset button that will power cycle the ESP8266 chip. Don't press the `RESET` button when a Ganglion is attached, if you want to power cycle the Wifi shield, send a `;` command to the Ganglion to trigger a power on reset of the Wifi shield. Further, you can flip the power switch on and then off on the Ganglion which will trigger a power on reset of the Wifi shield. The bottom button, `PROG`, is use for programming the wifi shield over serial UART. Be sure to always have your `EXT PWR` switch in the `OFF` position with the Ganglion!

#### 2. OpenBCI Ganglion Board

![Ganglion](../assets/images/wifi_ganglion_headshot.jpg)

Please be sure to have at least v2.x.x Ganglion firmware running on your board! If you have firmware v1.0.0 please see the [programming tutorial](http://docs.openbci.com/Hardware/09-Ganglion_Programming_Tutorial) to learn how to upgrade your firmware.

#### 3. 2x  6V AA Battery Pack & 4 AA Batteries or LiPo Battery

![Battery Connection](../assets/images/wifi_ganglion_power.jpg)

Install 4 AA batteries into your two battery packs or charge up your LiPo batteries. The Wifi shield has a 4-5x larger power draw then the Bluetooth communication system so we recommend using LiPo to power the Wifi Shield! Please review _Powering The Shield_ below to properly power the system.

### Seating the Wifi Shield

Make sure the batteries are disconnected from both the Ganglion and the Wifi shield.

To connect the Wifi shield to the Ganglion, first line up the big header pins on the Wifi shield to the Ganglion's female headers, like in the picture below:

![Line up the big header](../assets/images/wifi_ganglion_seating_1.jpg)

Then line up the two four pin headers.

![Line up the other pins](../assets/images/wifi_ganglion_seating_2.jpg)

Finally once all the pins are lined up, you can press straight down to fully seat the wifi shield onto it's new Ganglion home :)

![Press down to seat](../assets/images/wifi_ganglion_seating_3.jpg)

### Removing the Wifi Shield

Remove power to your Ganglion and/or Wifi shield.

![Wifi remove even fingers](../assets/images/wifi_ganglion_removing_1.jpg)

Wiggle the board slowly off

![Wifi wiggle](../assets/images/wifi_ganglion_removing_2.jpg)

Or pull the shield straight off to avoid bending the pins.

![Wifi off](../assets/images/wifi_removing_3.jpg)

### Powering the Shield

**IMPORTANT! Keep the dip switch labeled `EXT PWR` to `OFF` when using Ganglion.** As of today, the Wifi shield cannot pass through power to the Ganglion, therefore you must use two batteries.
**Always turn the Wifi on before the Ganglion.** Your Ganglion cannot be powered from the Wifi shield, but the Ganglion can send reset signals to Wifi shield to reset it via software. Therefore you will need two sets of batteries (battery packs or LiPo) in order to use the Ganglion and Wifi shield together.

![Wifi Power](../assets/images/wifi_battery_connection.jpg)

When the Ganglion is on, the pass through LED on the Wifi shield will show the classic _pleasant_ blue LED when powered up!

![Wifi Pass Through Power](../assets/images/wifi_ganglion_power_2.jpg)

Verify that the external power switch is set to `OFF` to **NOT** power through to the Ganglion board.

![Wifi External Power](../assets/images/wifi_ganglion_pass_through_power.jpg)

The Ganglion is not able to supply enough current to power the power-hungry wifi shield, so we put a bigger voltage regulator on the shield. In the future, the wifi shield will be able to power the Ganglion too.

## Cyton
### What You Need

![OpenBCI Wifi Contents](../assets/images/wifi_what_you_need.jpg)

 1. OpenBCI Wifi Shield
 2. OpenBCI Cyton Board **IMPORTANT: Must have at least v3.x.x Cyton firmware or newer!**
 3. LiPo battery or 6V AA battery pack & (x4) AA batteries (batteries not included)
 4. A computer connected to the internet

#### 1. OpenBCI Wifi Shield

![OpenBCI Wifi Shield](../assets/images/wifi_head_shot.jpg)

The battery connector on the back of the Wifi shield can accept 3V to 6V DC power input. The top push button, `RESET`, is a reset button that will power cycle the ESP8266 chip. Don't press the `RESET` button when a Cyton is attached, if you want to power cycle the Wifi shield, send a `;` command to the Cyton to trigger a power on reset of the Wifi shield. Further, if the Wifi shield is pass through power to the Cyton, you can flip the power switch on and then off on the Wifi shield to cut and then restore power to the entire system. The bottom button, `PROG`, is use for programming the wifi shield over serial UART. Don't supply external power to a Cyton when programming the Wifi shield.


#### 2. OpenBCI Cyton Board

![Cyton](../assets/images/wifi_cyton.jpg)

If you have firmware v1.0.0 please see the [Upgrade Guide](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/dev-3.0.0/UPGRADE_GUIDE.md) because you need to upgrade your [bluetooth radio firmware](https://github.com/OpenBCI/OpenBCI_Radios) because the new 3.0.0 code runs of the stability introduced in 2.0.0.

#### 3. Your 6V AA Battery Pack & 4 AA Batteries or LiPo Battery

![Battery Connection](../assets/images/wifi_battery_connection.jpg)

Install 4 AA batteries in your battery pack or charge up your LiPo battery. The Wifi shield has a 4-5x larger power draw then the Bluetooth communication system so we recommend using LiPo battery packs. You can keep the `EXT PWR` switch `ON` to passthrough power to the Cyton, more on this in the section below titled _Powering the Shield_.

### Seating the Wifi Shield

Remove power to your Cyton and/or Wifi shield.

First line up the big header.

![Line up the big header](../assets/images/wifi_seating_1.jpg)

Then line up the front analog pins.

![Line up the analog pins](../assets/images/wifi_seating_2.jpg)

Finally once all the pins are lined up, you can press straight down to fully seat the wifi shield onto it's new Cyton home :)

![Press down to seat](../assets/images/wifi_seating_3.jpg)

### Removing the Wifi Shield

Remove power to your Cyton and/or Wifi shield.

![Wifi remove even fingers](../assets/images/wifi_removing_1.jpg)

Either wiggle the board slowly off

![Wifi wiggle 1](../assets/images/wifi_removing_2.jpg)

Slowly...

![Wifi wiggle 2](../assets/images/wifi_removing_3.jpg)

Or pull the shield straight off to avoid bending the pins.

![Wifi off](../assets/images/wifi_removing_4.jpg)

### Powering the Shield

**IMPORTANT! Keep the dip switch labeled `EXT PWR` to `ON` when using Cyton.**

The Wifi Shield and the Cyton board use only one battery by means of the JST connector on the Wifi shield. Passing through power to the Cyton requries having the `EXT PWR` switch in the `ON` position.

![Wifi Power](../assets/images/wifi_battery_connection.jpg)

The pass through LED on the wifi shield will show the classic _pleasant_ blue LED when powered up!

![Wifi Pass Through Power](../assets/images/wifi_pass_through_power.jpg)

Make sure that the external power switch is set to `ON` to send power through to the Cyton board.

![Wifi External Power](../assets/images/wifi_what_you_need.jpg)

The Cyton is not able to supply enough current to power the power-hungry wifi shield, so we put a bigger voltage regulator on the shield to power both the Wifi chip and pass the Cyton components.

## Sending Data to Wifi Shield

### Overview

The Wifi Shield acts a SPI slave device to the Cyton or Ganglion. The max speed the ESP8266 can seem to handle is 10MHz. A [SPISlave example](https://github.com/esp8266/Arduino/blob/master/libraries/SPISlave/examples/SPISlave_Test/SPISlave_Test.ino) we based our [Wifi](https://github.com/OpenBCI/OpenBCI_WIFI/blob/master/examples/ESP8266HuzzahSSDP/ESP8266HuzzahSSDP.ino) code on. To interact with this SPI slave library, (you wanted to use this wifi shield for some other reason...) you should look at the [SPI Master example](https://github.com/esp8266/Arduino/blob/master/libraries/SPISlave/examples/SPISlave_Master/SPISlave_Master.ino) because the commands to get data vs read a status register are strictly defined and must be followed. The first constraint the Arduino ESP8266 SPI slave places on us is to always send 32 bytes per message. This library says that each packet must be 32 bytes, so that's where we begin....

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

This code writes 32 bytes of data in the correct format and therefore as soon as it arrives at the Wifi shield. The Wifi shield will convert the 32 byte packet to the standard 33 byte [binary format](http://docs.openbci.com/Hardware/03-Cyton_Data_Format#cyton-data-format-binary-format) by moving the control byte `0xCn`, where `n` is `0-F` (hex), to the stop position and add add `0xA0` to the start position. This allows for a seamless integration with the tried and tested parsing systems already built for the Cyton.
**Important** if you want to only send `20` bytes of data per packet, you still must send this `32` bytes with the proper start and stop bytes.
