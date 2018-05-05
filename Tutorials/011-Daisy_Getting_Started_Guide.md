# Daisy Getting Started Guide

This guide will walk you through getting 16-channel input on your Cyton+Daisy Module

## I. SET UP YOUR CYTON BOARD

Refer to the Cyton Tutorial page:
[Cyton Getting Started Guide](http://docs.openbci.com/Tutorials/01-Cyton_Getting%20Started_Guide).

Follow the guide through the end of Step V. CONNECT YOURSELF TO OPENBCI 

## II. WHAT YOU NEED

1. OpenBCI Daisy Module
2. Y-Splitter Cable
3. Electrode cables with female header termination on one end



#### 1. [OpenBCI Daisy Module](https://shop.openbci.com/collections/frontpage/products/cyton-daisy-biosensing-boards-16-channel?variant=38959256526)
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Daisy%20Front%20Image.jpg?raw=true" width="60%">

#### 2. Y-Splitter Cable

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Daisy%20Y-Splitter%20Image.jpg?raw=true" width="60%">
	 
#### 3. Electrode Cables with female header termination on one end

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Daisy%20Female%20Header%20Termination%20Image.jpg?raw=true" width="60%">

## III. ASSEMBLY

### 1) Add the Daisy extension onto the Cyton Board 
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Cyton%2BDaisy%20Front%20Image.JPG?raw=true" width="60%">

### 2) Connect Y-Splitter Cable
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Cyton%2BDaisy%2BY-Splitter.JPG?raw=true" width="60%">

The Y-Splitter connects the bottom SRB pin of the Daisy Board to the bottom SRB pin of the Cyton Board

### 3) Connect the bottom BIAS pin of the Cyton to your reference point

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Cyton_Daisy_BIAS.jpg?raw=true" width="60%">

### 4) Connect Cyton and Daisy bottom pins N1P through N8P to leads

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/MarkIV/Cyton_Daisy_Setup.JPG?raw=true" width="80%">

Use the 16 of the color coded cables that came with your Ultracortex MarkIV headset.

Connect Cyton bottom pins N1P through N8P to the cables, shown above. Then, connect the remaining 8 cables to Daisy bottom pins N1P through N8P. Color order does not matter. 

Refer to the Ultracortex Mark IV [tutorial](http://docs.openbci.com/Headware/01-Ultracortex-Mark-IV) to learn how to connect the male terminations of the color coded cables to the electrodes on the headset.

If you did not purchase a headset, you can use 16 of our [Gold Cup Electrodes](https://shop.openbci.com/collections/frontpage/products/openbci-gold-cup-electrodes?variant=9056028163), [Snap Electrode Cables](https://shop.openbci.com/collections/frontpage/products/emg-ecg-snap-electrode-cables?variant=32372786958), or [Header Pin to Touch Proof Electrode Adapter](https://shop.openbci.com/collections/frontpage/products/touch-proof-electrode-cable-adapter?variant=31007211715).

If you purchased a Wifi Shield, attach it to the Cyton board, then attach the Daisy module on top of the Wifi Shield, shown below.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Cyton_Daisy_Wifi.JPG?raw=true" width="60%">
The leads are connected to the pins in the same way as if you did not have the Wifi Shield. See Section III. Assembly above.


