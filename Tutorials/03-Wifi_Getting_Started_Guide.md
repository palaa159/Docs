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

## Connecting to the Wifi Shield

Be sure that your WiFi Shield is on your local network. Please continue reading if your OpenBCI Wifi Shield is on the same wifi network as your computer.

The steps for connecting to the Wifi Shield and streaming over TCP:

1. Get Wifi Shield On Your Wireless Network
2. Find IP Address of Wifi Shield
3. Open a TCP Socket on Host Computer
4. Send `POST` `/tcp` http request with open socket IP/Port number, can include options for output formate (i.e. JSON or RAW output), along with latency.
5. Send `POST` `/command` http requests for control or for just streaming use GET `/stream/start` or GET `/stream/stop`
6. Send `POST` `/latency` http requests for tuning, if packets are dropped because older router or poor connection.

The steps for connecting to the Wifi Shield and streaming over MQTT:

1. Get Wifi Shield On Your Wireless Network
2. Find IP Address of Wifi Shield
3. Open a TCP Socket on Host Computer
4. Send `POST` `/mqtt` http request with broker address with optional username and password
5. Send `POST` `/command` http requests for control

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

## Get IP Address of Wifi Shield

Use [Simple Service Discovery Protocol](https://en.wikipedia.org/wiki/Simple_Service_Discovery_Protocol) (SSDP) to find the device on your local network. Use a tool in your favorite language [Python](http://brisa.garage.maemo.org/doc/html/upnp/ssdp.html) | [Node.js](https://github.com/diversario/node-ssdp) | [C](https://developer.gnome.org/gssdp/stable/).

The [Node.js SDK](https://github.com/aj-ptw/OpenBCI_NodeJS/blob/wifi/examples/getStreamingWifi/getStreamingWifi.js) which will implement SSDP for you.

Use a graphical user interface [Mac - Lan Scan](https://itunes.apple.com/us/app/lanscan/id472226235?mt=12)

We are still hashing out the best ways to discover the Wifi shield on the networks (home vs. enterprise and beyond) so [please contribute ides if you have any on this github issue](https://github.com/OpenBCI/OpenBCI_WIFI/issues/8) and we can add it in! [Wifi Direct Feature Request (researcher frequently requested feature)](https://github.com/OpenBCI/OpenBCI_WIFI/issues/9)

## Open a TCP Socket on Host Computer

In order to get low latency high-reliability wireless data transmission we will open a TCP socket on your host Computer. The Wifi Shield will stream data to this socket. **IMPORTANT** The data comes over this socket raw and is defined in the docs for [Binary Data Format](http://docs.openbci.com/Hardware/03-Cyton_Data_Format#cyton-data-format-binary-format).

If you want the data in another format, please comment on [this issue](https://github.com/OpenBCI/OpenBCI_WIFI/issues/11), thinking protocols like `JSON`.

## OpenBCI HTTP Rest Server

### Send `/tcp` http request for TCP configuration

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

### Send `/mqtt` http request for MQTT configuration

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

### Send `/command` http requests for control

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server. To change the sample rate of the Cyton, please use the `~` command as defined in the Cyton SDK docs.

### Send `/latency` http requests for tuning

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

The time in micro seconds (us) between packet sends. The higher the OpenBCI sample rate, the higher the latency needed. Default is 1000us, minimum stable is 50us. For upper limit sample rates such as 4kHz/8kHz/16kHz, latency around 20ms seems to really stabilize the system.  
