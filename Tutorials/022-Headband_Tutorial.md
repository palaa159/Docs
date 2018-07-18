# OpenBCI EEG Headband Kit

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Front.JPG?raw=true" width="50%">

##### Now [available](https://shop.openbci.com/collections/frontpage/products/openbci-eeg-headband-kit?variant=8120393760782) in our shop!

When combined with our [Ganglion](https://shop.openbci.com/collections/frontpage/products/pre-order-ganglion-board?variant=13461804483) or [Cyton](https://shop.openbci.com/collections/frontpage/products/cyton-biosensing-board-8-channel?variant=38958638542) boards, the OpenBCI EEG Headband Kit is a low-cost tool for obtaining research-grade EEG data.

This tutorial will guide you through setting up your EEG system with either board!

#### Each kit includes:
1. Two Ear-clip electrodes (left example)
2. Three lead wires for flat EEG Snap Electrodes (right example)
3. Two standard lead wires (middle example)
4. One full-length-velcro headband
5. Replacement flat ear electrodes, replacement flat snap electrodes, and replacement 2 mm spikey electrodes


<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Electrodes.png?raw=true" width="50%">

All electrode wires end in a female header termination compatible with OpenBCI biosensing boards.
#### 10-20 Internationally Accepted EEG Node Placement
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/10-20%20Placement.jpg?raw=true" width="50%">

The headband allows three frontal cortex measurements (F7, AF7, Fp1, Fpz, Fp2, AF8, F8) via the 3 lead wires with flat EEG electrodes. The two leads with spikey electrodes will allow measurement at the FT7/FT8, T7/T8, TP7/TP8, P7/P8, PO7/PO8, O1/O2, and Oz nodes, depending where you insert the spikey electrodes. In total, this kit comes with FIVE electrode leads, with option to add more! If you want to add additional electrodes to the headband, please email support@openbci.com.


## Headband-Ganglion Tutorial

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Ganglion_Front.JPG?raw=true" width="50%">

The Ganglion board supports four channels of EEG/EMG/EEG input and can stream data over [bluetooth](http://docs.openbci.com/Hardware/08-Ganglion_Data_Format) or [wifi](http://docs.openbci.com/Tutorials/03-Wifi_Getting_Started_Guide). In this tutorial we will show you how to obtain two frontal lobe measurements and two temporal lobe measurements using the four channels of the Ganglion and stream the data over bluetooth!

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion.JPG?raw=true" width="50%">

#### Battery

All OpenBCI boards ship with a free 2-pin standard JST compatible 4-AA battery holder. For the best user experience, we recommend purchasing the LiPo battery and charger linked below.

1. [Lithium ion battery](https://www.adafruit.com/product/1578) and 
2. [USB charger](https://www.adafruit.com/product/1304)

We recommend for its long battery life, compact size, and compatibility with all OpenBCI boards.

#### Hardware

Your Ganglion may have shipped with orange protective cellophane over switches sw1 - sw4. Once you've peeled the protective layer off, and flipped the switches to **down** position, they should look like the image below. Because we are using the Ganglion to obtain EEG, this step is IMPORTANT. 
 
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion_Switch.JPG?raw=true" width="50%">

See the [Ganglion Hardware page](http://docs.openbci.com/Hardware/07-Ganglion#openbci-ganglion-openbci-ganglion-board-inverting-input-select-switches) for a detailed explanation of why we flip the four channel switches to **down**.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion_Headband_Pins.JPG?raw=true" width="50%">

1. Connect one earclip electrode to the top D_G (driven ground) pin.
2. Connect the second earclip electrode to the top REF pin.
3. Connect the female terminations of the two flat snap electrodes and two spikey electrodes to top pins 1-4, shown above.
The order can be left to user preference.

#### OpenBCI Software

Now that you've finished with the hardware set-up, the next step is to set up the GUI! Follow the GUI [tutorial](http://docs.openbci.com/Tutorials/02-Ganglion_Getting%20Started_Guide#ganglion-getting-started-guide-downloadinstallrun-the-openbci-gui) to prepare your computer to communicate with your Ganglion.

Once you've downloaded the GUI zip file per tutorial instructions, fire up the GUI like shown in the video below!
 
<iframe width="840" height="540" src="https://www.youtube.com/embed/NAM6eOA4a8Y" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

Notice the sharp peak-trough-peak wave behavior in the upper left time series window of the GUI. The first peak corresponds with the initiation of an eye blink, the trough immediately after shows a dip in alpha brain waves that syncs to the eye's closing for a fraction of a second! The peak immediately **after** the trough corresponds to the brain signals to the eyelid to reopen, thus concluding the blink cycle.

The band power window in the lower right of the GUI shows the relative strengths of the user's alpha, beta, gamma, delta, and theta brain waves. The GUI and Ganglion work together to separate and categorize brain waves based on characteristics like frequency and amplitude. 

In the screenshot below, you'll see this analysis utilized in another built-in function, the Focus Widget! When the alpha waves are (relatively) high and beta waves are low, the GUI translates this to a focused state.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI_Ganglion.png?raw=true"width="70%">

The Ganglion Signal window in the lower left of the GUI is one of the many other useful displays. For most bioelectrical measurements, you want the skin-electrode contact surface impedance to be low. Two of the four channels show lower impedance (these happen to be the flat snap electrodes that are touching the skin over the frontal cortex). This connection must be good, hence the green light to the left of the impedance value. If the impedance light in the GUI is red, you can improve the connection by making sure the electrodes are secured against the skin and making good contact. You may find it helpful to add a little [electrode paste](https://shop.openbci.com/collections/frontpage/products/ten20-conductive-paste-2oz-jars?variant=31373533198) to boost conductivity of the Ag-AgCl coating on the electrodes.


## Headband-Cyton Tutorial

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Cyton_Front.JPG?raw=true"width="50%">

The Cyton board supports eight channels of EEG/EMG/EEG input and can stream data over [bluetooth](http://docs.openbci.com/Hardware/03-Cyton_Data_Format) or [wifi](http://docs.openbci.com/Tutorials/03-Wifi_Getting_Started_Guide). In this tutorial we will show you how to obtain three frontal lobe measurements and two temporal lobe measurements using five of the eight channels and stream the data over bluetooth!

#### Battery

All OpenBCI boards ship with a free 2-pin standard JST compatible 4-AA battery holder. For the best user experience, we recommend purchasing the LiPo battery and charger linked below.

1. [Lithium ion battery](https://www.adafruit.com/product/1578) and 
2. [USB charger](https://www.adafruit.com/product/1304)

#### Hardware

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Cyton_Headband_Pins.JPG?raw=true"width="50%">

As shown above:

1. Connect one earclip electrode to the bottom BIAS pin
2. Connect the second earclip electrode to the bottom SRB pin
3. Connect the female terminations of the three flat snap electrodes to bottom pins 1-3
4. Connect the female terminations of the two spikey electrodes to bottom pins 4-5

Note, the order of electrodes on pins 1-5 can be left to user preference.

#### OpenBCI Software

Now that you've finished with the hardware set-up, the next step is to set up the GUI! Follow the GUI [tutorial](http://docs.openbci.com/Tutorials/01-Cyton_Getting%20Started_Guide#cyton-getting-started-guide-ii-downloadinstallrun-the-openbci-gui) to prepare your computer to communicate with your Cyton.

Once you've installed the GUI by following the tutorial, fire it up like shown in the video below!

<iframe width="840" height="540" src="https://www.youtube.com/embed/XktF8OhHH4A" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI_Cyton_B.png?raw=true"width="70%">

The screenshot above shows an example of your live-streamed brain data might look like. Toggle around with the vertical scale, filter, frequency range to see the effect on the raw data.

For more details on the various GUI functions, scroll up to the OpenBCI Software section of the Headband-Ganglion Tutorial above and also check out the cool features section of the GUI [page](http://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-cool-gui-features).

<!-- This is a video that looks like a gif.
<video autoplay="" loop="" muted="" playsinline="" width="400" height="300">
    <source src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI%20Cyton.mp4?raw=true" type="video/mp4" />
    Your browser does not support HTML5 videos.
</video>

 This is a regular video with controls.
<video controls muted="" playsinline="" width="800" height="600">
    <source src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI%20Cyton.mp4?raw=true" type="video/mp4" />
    Your browser does not support HTML5 videos.
</video>-->

As always, don't hesitate to email us at support@openbci.com for assistance!

Happy hacking!
