# Wifi Getting Started Guide

**If you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new) or fix and make a Pull Request on [Github](https://github.com/OpenBCI/Docs).**

##Overview

Congrats on getting an OpenBCI WiFi Shield produced in partnership with [Push The World](www.pushtheworldllc.com).

Before we jump into setting up your WiFi Shield, here are some helpful links:

 * [Learn to update your WiFi Shield](http://docs.openbci.com/Hardware/11-Wifi_Programming_Tutorial) to the [latest firmware](// TODO: Add link for latest firmware).
 * Learn about the physical hardware on the WiFi Shield checkout the [OpenBCI Wifi Hardware docs](http://docs.openbci.com/Hardware/11-Wifi)
 * Lookup the commands for the HTTP rest server on the WiFi Shield at the [swaggerhub.io](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.2.1)
 * Checkout the firmware that powers the WiFi Shield at [on Github](http://github.com/OpenBCI/OpenBCI_WIFI)

Always make sure you have the [latest firmware](// TODO: Add link for latest firmware.) loaded on your WiFi Shield. Additionally, you will need to update your Ganglion (at least v2.0.0 or newer) and/or Cyton (at least version v3.0.0 or newer) to the latest firmware.

This guide will walk you through setting up your WiFi Shield, connecting it to your computer, and then connecting it to yourself. The first tutorial is for the Ganglion and the second is for the Cyton.

## Powering Your WiFi Shield

A LiPo battery is highly recommended for powering the WiFi Shield.

### Cyton

You only need one battery when using the Cyton with the WiFi Shield. In fact, the Cyton takes power from the WiFi Shield. When the Cyton is powered by the WiFi Shield, you'll find the power switch on the Cyton becomes useless! Don't worry, that's intended. More about powering the Cyton and WiFi Shield can be found in the [OpenBCI Wifi Hardware docs](http://docs.openbci.com/Hardware/11-Wifi).

![OpenBCI Wifi Contents](../assets/images/wifi_what_you_need.jpg)

1. OpenBCI WiFi Shield
2. OpenBCI Cyton Board **IMPORTANT: Must have at least v3.0.0 Cyton firmware or newer!**
3. One LiPo battery or 6V AA battery pack & (x4) AA batteries (batteries not included)

* [Powering the WiFi Shield](//Todo: add link) with Cyton docs.
* [Attaching the WiFi Shield](//Todo: add link) to the Cyton docs.
* [Removing the WiFi Shield](//Todo: add link) from the Cyton docs.
* [Flashing Cyton Firmware](http://docs.openbci.com/Hardware/005-Cyton_Board_Programming_Tutorial) docs.

### Ganglion

You need two batteries in total when using WiFi with the Ganglion. One to power the WiFi Shield and one to power the Ganglion. The WiFi Shield will pull about 10x the amount of power as the Ganglion! The rational behind the two batteries is in the [OpenBCI Wifi Hardware docs](http://docs.openbci.com/Hardware/11-Wifi) and will be addressed in an upcoming hardware revision.

![OpenBCI Wifi Contents](../assets/images/wifi_ganglion_what_you_need.jpg)

 1. OpenBCI WiFi Shield
 2. OpenBCI Ganglion Board **IMPORTANT: Must have at least v2.0.0 Ganglion firmware or newer!**
 3. 2 batteries, 3.7V or 4.2V LiPo or 6V AA battery will work (batteries not included)

![Wifi External Power](../assets/images/wifi_ganglion_pass_through_power.jpg)

**IMPORTANT! Keep the dip switch labeled `EXT PWR` to `OFF` when using Ganglion.**

If you are stuck checkout:

 * [Powering the WiFi Shield](//Todo: add link) with Ganglion docs.
 * [Attaching the WiFi Shield](//Todo: add link) to the Ganglion docs.
 * [Removing the WiFi Shield](//Todo: add link) from the Ganglion docs.
 * [Flashing Ganglion Firmware](http://docs.openbci.com/Hardware/09-Ganglion_Programming_Tutorial) docs.

## Get Wifi Shield On Your Wireless Network

The WiFi Shield must connect to the same wireless network as your chosen wireless device. The WiFi Shield will not know what wireless network to join. When the WiFi Shield can't join a network, the Shield turns into a WiFi hotspot, and will have a name such as "OpenBCI-A4AD" where the last four digits are hexadecimal and are unique to your WiFi shield. Use any wireless device to connect to the the WiFi Shield hotspot.

The WiFi shield does not work for Enterprise level security. Use your cellphone hot spot or set up your own wifi network.

### Example:

[Powering new OpenBCI Wifi Shield](//TODO:ADD LINK) will cause the WiFi Shield to try to join the last known network. If the last network is not available, the WiFi Shield will become a WiFi router that any computer, phone or any internet connected device can join just like any other wireless network. The OpenBCI Wifi Shield will have a unique name such as `OpenBCI-A4AD` (the last four numbers are unique to my device, write this number down, it's helpful, no worries if you don't, there are ton's of way to find the boards name).

A WiFi network at is called `MeerketManor`, it's password protected, and the iPhone is connected to `MeerketManor`.

![iPhone Connected to `MeerketManor`](../assets/images/wifi_join_network_1.PNG)

There is a known issue where it may take several times to bring up the captive touch portal, we are actively seeking a better solution, in the meantime, be patient and try multiple times to connect to the board. Power cycling the board may useful.

![iPhone Connecting to `OpenBCI-A4AD`](../assets/images/wifi_join_network_2.PNG)

After a couple seconds a captive touch portal will appear on the computer, phone or tablet. Click _Configure wifi_.

![Captive touch portal first screen](../assets/images/wifi_captive_touch_first_screen.PNG)

On the next screen, see that `MeerketManor` is listed as a possible network for the Wifi Shield to join. Select `MeerketManor` and enter the password for the network and press `connect`.

![Captive touch portal second screen](../assets/images/wifi_captive_touch_second_screen.PNG)

The credentials saved page will show. If a mistake was made in the password, no worries, Try to rejoin the WiFi Shield network and repeat the process. If the `MeerketManor` password was entered correct, then the Wifi Shield will join `MeerketManor` after a quick reboot and everytime the network is within range the WiFi shield is not connected to any board.

The OpenBCI is now fully qualified port 80 http server that is fully defined on with an industry standard swagger.io format. Click for [full http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.2.1).

## Connecting with the OpenBCI GUI

[Download the latest version](TODO: ADD LINK) of the OpenBCI GUI

### Install the latest OpenBCI GUI

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
