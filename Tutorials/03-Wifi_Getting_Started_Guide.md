# Wifi Getting Started Guide

**If you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new) or please fix it with a Pull Request on [Github](https://github.com/OpenBCI/Docs).**

## Overview

Congrats on getting an OpenBCI WiFi Shield produced in partnership with [Push The World](www.pushtheworldllc.com).

Before we jump into setting up your WiFi Shield, here are some helpful links:

 * [Learn to update your WiFi Shield](http://docs.openbci.com/Hardware/12-Wifi_Programming_Tutorial) to the [latest firmware](https://github.com/OpenBCI/OpenBCI_32bit_Library/releases/tag/v3.0.0-rc4).
 * Learn about the physical hardware on the WiFi Shield checkout the [OpenBCI Wifi Hardware docs](http://docs.openbci.com/Hardware/11-Wifi)
 * Lookup the commands for the HTTP rest server on the WiFi Shield at the [swaggerhub.io](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0)
 * Checkout the firmware that powers the WiFi Shield at [on Github](http://github.com/OpenBCI/OpenBCI_WIFI)

Always make sure you have the [latest firmware](https://github.com/OpenBCI/OpenBCI_WIFI/releases/latest) loaded on your WiFi Shield. Additionally, you will need to update your [Cyton (at least version v3.0.0-rc6 or newer)](https://github.com/OpenBCI/OpenBCI_32bit_Library/releases/tag/v3.0.0-rc6) to the latest firmware and/or [Ganglion (at least v2.0.0-rc1 or newer)](https://github.com/OpenBCI/OpenBCI_Ganglion_Library/releases/tag/v2.0.0-rc1).

This guide will walk you through setting up your WiFi Shield, connecting it to your computer, and then connecting it to yourself. The first tutorial is for the Cyton and the second is for the Ganglion.

## Cyton

You only need one battery when using the Cyton with the WiFi Shield. The Cyton takes power from the WiFi Shield. When the Cyton is powered by the WiFi Shield, you'll find the power switch on the Cyton becomes useless.

![OpenBCI Wifi Contents](../assets/images/wifi_what_you_need.jpg)

### What you need

 1. OpenBCI WiFi Shield
 2. OpenBCI Cyton Board **IMPORTANT: Must have at least [v3.0.0 Cyton firmware](https://github.com/OpenBCI/OpenBCI_32bit_Library/releases/tag/v3.0.0) or newer!**
 3. One LiPo battery or 6V AA battery pack & (x4) AA batteries (batteries not included)

### Important Concepts and Tutorials

Please read and be comfortable with the following tutorials

 1. [Updating the WiFi Shield Firmware](http://docs.openbci.com/Hardware/12-Wifi_Programming_Tutorial)
 2. [Flashing Cyton Firmware](http://docs.openbci.com/Hardware/05-Cyton_Board_Programming_Tutorial) docs.

### General Overview

In general the steps are:

 1. Power off WiFi Shield and Cyton
 2. Seat WiFi Shield on Cyton
 3. Put `EXT PWR` switch on Shield to `ON`
 4. Plug battery into WiFi Shield only
 5. Main power switch on WiFi Shield to `ON`

### Seating the Wifi Shield

First line up the big header.

![Line up the big header](../assets/images/wifi_seating_1.jpg)

Then line up the front analog pins.

![Line up the analog pins](../assets/images/wifi_seating_2.jpg)

Finally once all the pins are lined up, you can press straight down to fully seat the wifi shield onto it's new Cyton home :)

![Press down to seat](../assets/images/wifi_seating_3.jpg)

### Removing the Wifi Shield

![Wifi remove even fingers](../assets/images/wifi_removing_1.jpg)

Either wiggle the board slowly off

![Wifi wiggle 1](../assets/images/wifi_removing_2.jpg)

Slowly...

![Wifi wiggle 2](../assets/images/wifi_removing_3.jpg)

Or pull the shield straight off to avoid bending the pins.

![Wifi off](../assets/images/wifi_removing_4.jpg)

### Powering the Shield

Install 4 AA batteries in your battery pack or charge up your LiPo battery. The Wifi shield has a 4-5x larger power draw then the Bluetooth communication system so we recommend using LiPo battery packs. You can keep the `EXT PWR` switch `ON` to passthrough power to the Cyton, more on this in the section below titled _Powering the Shield_.

**IMPORTANT! Keep the dip switch labeled `EXT PWR` to `ON` when using Cyton.**

The Wifi Shield and the Cyton board use only one battery by means of the JST connector on the Wifi shield. Passing through power to the Cyton requries having the `EXT PWR` switch in the `ON` position.

![Wifi Power](../assets/images/wifi_battery_connection.jpg)

The pass through LED on the wifi shield will show the classic _pleasant_ blue LED when powered up!

![Wifi Pass Through Power](../assets/images/wifi_pass_through_power.jpg)

Make sure that the external power switch is set to `ON` to send power through to the Cyton board.

![Wifi External Power](../assets/images/wifi_what_you_need.jpg)

The Cyton is not able to supply enough current to power the power-hungry wifi shield, so we put a bigger voltage regulator on the shield to power both the Wifi chip and pass the Cyton components.

## Ganglion

### What you need

 1. OpenBCI WiFi Shield
 2. OpenBCI Ganglion Board **IMPORTANT: Must have at least v2.0.0 Ganglion firmware or newer!**
 3. 2 batteries, 3.7V or 4.2V LiPo or 6V AA battery will work (batteries not included)

![OpenBCI Wifi Contents](../assets/images/wifi_ganglion_what_you_need.jpg)

### Important Concepts and Tutorials

Please read and be comfortable with the following tutorials

1. [Updating the WiFi Shield Firmware](http://docs.openbci.com/Hardware/12-Wifi_Programming_Tutorial)
2. [Flashing Ganglion Firmware](http://docs.openbci.com/Hardware/09-Ganglion_Programming_Tutorial) docs.

### General Overview

In general the steps are:

 1. Power off WiFi Shield and Ganglion
 2. Seat WiFi Shield on Ganglion
 3. Put `EXT PWR` switch on Shield to `OFF`
 4. Plug battery into WiFi Shield
 5. Plug battery into Ganglion
 6. Main Power to switch on WiFi Shield to `ON` (it's okay if Shield LED's flash)
 5. Main power to switch on Ganglion to `ON`

### Seating the Wifi Shield

To connect the Wifi shield to the Ganglion, first line up the big header pins on the Wifi shield to the Ganglion's female headers, like in the picture below:

![Line up the big header](../assets/images/wifi_ganglion_seating_1.jpg)

Then line up the two four pin headers.

![Line up the other pins](../assets/images/wifi_ganglion_seating_2.jpg)

Finally once all the pins are lined up, you can press straight down to fully seat the wifi shield onto it's new Ganglion home :)

![Press down to seat](../assets/images/wifi_ganglion_seating_3.jpg)

### Removing the Wifi Shield

![Wifi remove even fingers](../assets/images/wifi_ganglion_removing_1.jpg)

Wiggle the board slowly off

![Wifi wiggle](../assets/images/wifi_ganglion_removing_2.jpg)

Or pull the shield straight off to avoid bending the pins.

![Wifi off](../assets/images/wifi_removing_3.jpg)

### Powering the Shield

**IMPORTANT! Keep the dip switch labeled `EXT PWR` to `OFF` when using Ganglion.** As of today, the Wifi shield cannot pass through power to the Ganglion, therefore you must use two batteries.

**Always turn the Wifi on before the Ganglion.** Your Ganglion cannot be powered from the Wifi shield, but the Ganglion can send reset signals to Wifi shield to reset it via software. Therefore you will need two sets of batteries (battery packs or LiPo) in order to use the Ganglion and Wifi shield together.

![Battery Connection](../assets/images/wifi_ganglion_power.jpg)

Install 4 AA batteries into your two battery packs or charge up your LiPo batteries. The Wifi shield has a 10x larger power draw then the Ganglion communication system so we recommend using LiPo to power the Wifi Shield! Please review _Powering The Shield_ below to properly power the system.

![Wifi Power](../assets/images/wifi_battery_connection.jpg)

When the Ganglion is on, the pass through LED on the Wifi shield will show the classic _pleasant_ blue LED when powered up!

![Wifi Pass Through Power](../assets/images/wifi_ganglion_power_2.jpg)

Verify that the external power switch is set to `OFF` to **NOT** power through to the Ganglion board.

![Wifi External Power](../assets/images/wifi_ganglion_pass_through_power.jpg)

The Ganglion is not able to supply enough current to power the power-hungry wifi shield, so we put a bigger voltage regulator on the shield. In the future, the wifi shield will be able to power the Ganglion too.

## Get the WiFi Shield On Your Wireless Network

The WiFi Shield must be on the same wireless network as your computer, smart phone, or other internet connected device you wish to talk to the device with. When the WiFi Shield can't join a known network, the Shield turns into a WiFi hotspot, and will have a name such as "OpenBCI-A4AD" where the last four digits are hexadecimal and are unique to your WiFi shield. Use any wireless device to connect to launch a captive touch portal from the the WiFi Shield hotspot.

The WiFi shield does not work for Enterprise level security. Use your cellphone as a hot spot or set up your own wifi network. Push The World is planning a WiFi direct connection as another alternative for researchers and those on enterprise networks.

### Example

A WiFi network is called _MeerketManor_, it's password protected, and the iPhone is connected to _MeerketManor_.

![iPhone Connected to MeerketManor](../assets/images/wifi_join_network_1.PNG)

There is a known issue where it may take several times to bring up the captive touch portal, Push The World is actively seeking a better solution, in the meantime, be patient and try multiple times to connect to the board. Power cycling the board may useful.

![iPhone Connecting to `OpenBCI-A4AD`](../assets/images/wifi_join_network_2.PNG)

After a couple seconds a captive touch portal will appear on the computer, phone or tablet. Click _Configure WiFi_.

![Captive touch portal first screen](../assets/images/wifi_captive_touch_first_screen.PNG)

On the next screen, see that _MeerketManor_ is listed as a possible network for the WiFi Shield to join. Select _MeerketManor_ and enter the password for the network and press _save_.

![Captive touch portal second screen](../assets/images/wifi_captive_touch_second_screen.PNG)

The credentials saved page will show. If a mistake was made in the password, no worries, Try to rejoin the WiFi Shield network and repeat the process. If the _MeerketManor_ password was entered correct, then the WiFi Shield will join _MeerketManor_ after a quick reboot and every time the network is within range the WiFi shield is not connected to any board.

![Captive touch portal final screen](../assets/images/wifi_captive_touch_final_screen_shot.PNG)

The OpenBCI is now fully qualified port 80 http server that is fully defined on with an industry standard swagger.io format. Click for [full http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0).

## Connecting with the OpenBCI GUI

[Download the latest version](http://openbci.com/index.php/downloads) of the OpenBCI GUI

### Installing OpenBCI GUI

On Mac, drag and drop the application to /Applications

On Windows, move the application to Program Files. Always run as administrator.

### Streaming Data On Cyton

Select Cyton from the first drop down
![selecting cyton from drop down](../assets/images/wifi_)

Select "Wifi (from WiFi Shield)" as the transfer protocol
![selecting wifi from the transfer protocol](../assets/images/wifi_)

Select the desired WiFi Shield from the dropdown list and configure any other settings
![selecting wifi shield](../assets/images/wifi_)

Press connect and start streaming!
![cyton wifi page](../assets/images/wifi_)

If you are unable to connect to the board

1. Verify the EXT PWR switch is in the ON position.
2. Verify you do not have a battery in the Cyton
3. Verify the latest firmware on the Cyton
4. Verify the latest firmware on the WiFi Shield

### Streaming Data On Ganglion

Select Ganglion from the first drop down
![selecting ganglion from drop down](../assets/images/wifi_)

Select "Wifi (from WiFi Shield)" as the transfer protocol
![selecting wifi from the transfer protocol](../assets/images/wifi_)

Select the desired WiFi Shield from the dropdown list and configure output settings
![selecting wifi shield](../assets/images/wifi_)

Press connect and start streaming!
![ganglion wifi page](../assets/images/wifi_)

If you are unable to connect to the board

1. Always turn the WiFi Shield on and then immediately turn the Ganglion on.
2. Verify the EXT PWR switch is in the OFF position.
3. Verify you are using one battery for the Ganglion and one battery for the WiFi Shield.
4. Verify the latest firmware on the Ganglion
5. Verify the latest firmware on the WiFi Shield
