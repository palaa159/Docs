# OpenBCI Wifi

**The Wifi shield and these docs are still in beta, if you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new).**

The OpenBCI Wifi Shield was designed in partnership with [Push The World](www.pushtheworld.us). The OpenBCI Wifi PCB was designed with KiCAD, an Open Source PCB capture software. You can find a link to download KiCAD in our [OpenBCI design files repository](https://github.com/OpenBCI/OpenBCI_Wifi_Shield) where you will find design files and component library files to load into KiCAD and edit, if you like, along with the full BOM for this maiden production run.

## About the WiFi Shield

### Wifi Board Specs

* Power with 3.3V to 6V DC battery ONLY
* Current Draw: 150mA connected and streaming data
* [ESP8266](http://www.esp8266.com) Wifi module (Arduino Compatible)
* Board Dimensions 2.41" x 2.41" (octagon has 1" edges)
* JST Power input
* Switch to stop power to external board

### Wifi Board Circuit Schematic

![Wifi Schematic](../assets/images/wifi_schematic.png)

### Wifi Board PCB Layer Images  

Top Layer  
![Wifi Top Layer](../assets/images/wifi_top.png)  
Bottom Layer  
![Wifi Bottom Layer](../assets/images/wifi_bottom.png)  

### Buttons

The top push button, `RESET`, is a reset button that will power cycle the ESP8266 chip. Don't press the `RESET` button when a Ganglion is attached, if you want to power cycle the WiFi Shield, send a `;` command to the Ganglion or Cyton to trigger a power on reset of the WiFi Shield. The bottom button, `PROG`, is use for programming the WiFi Shield over serial UART and is hooked up to GPIO 0.

#### Ganglion Note
You can flip the power switch on and then off on the Ganglion which will trigger a power on reset of the WiFi Shield. Be sure to always have your `EXT PWR` switch in the `OFF` position with the Ganglion!

## Interfacing with Ganglion

![Battery Connection](../assets/images/wifi_ganglion_power.jpg)

Install 4 AA batteries into your two battery packs or charge up your LiPo batteries. The Wifi shield has a 10x larger power draw then the Ganglion communication system so we recommend using LiPo to power the Wifi Shield! Please review _Powering The Shield_ below to properly power the system.

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

## Interfacing with the Cyton

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
