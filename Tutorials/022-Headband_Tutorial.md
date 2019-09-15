# OpenBCI EEG Headband Kit Guide

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Front.JPG?raw=true" width="50%">

##### Now [available](https://shop.openbci.com/collections/frontpage/products/openbci-eeg-headband-kit?variant=8120393760782) in our shop!

When combined with our [Ganglion](https://shop.openbci.com/collections/frontpage/products/pre-order-ganglion-board?variant=13461804483) or [Cyton](https://shop.openbci.com/collections/frontpage/products/cyton-biosensing-board-8-channel?variant=38958638542) boards, the OpenBCI EEG Headband Kit is a low-cost tool for obtaining research-grade EEG data.

This tutorial will guide you through setting up your EEG system with either board! Please read this tutorial in its entirety (ALL Ganglion and Cyton sections, even if you don't have both boards) before setting up the system. 

#### Each kit includes:
1. Two Ear-clip electrodes (left example)
2. Three lead wires for flat EEG Snap Electrodes (right example)
3. Five standard lead wires, i.e. wire clip cables (middle example)
4. One full-length-velcro headband
5. Replacement flat ear electrodes, replacement flat snap electrodes, and replacement 2 mm spikey electrodes


<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Electrodes.png?raw=true" width="50%">

All electrode wires end in a female header termination compatible with OpenBCI biosensing boards.

#### 10-20 Internationally Accepted EEG Node Placement
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/10-20%20Placement.jpg?raw=true" width="50%">

The headband allows three frontal cortex measurements (F7, AF7, Fp1, Fpz, Fp2, AF8, F8) via the 3 lead wires with flat EEG electrodes. The five leads with spikey electrodes will allow measurement at the FT7/FT8, T7/T8, TP7/TP8, P7/P8, PO7/PO8, O1/O2, and Oz nodes, depending where you insert the spikey electrodes. In total, this kit comes with EIGHT electrode leads.

To attach the spikey electrodes to the standard lead wires: 
1. Place spikey electrode spikes down on a table or hard surface.
2. Insert electrode into desired headband location.
3. Insert exposed metal into the groove of the electrode.
4. Gently press down on the plastic part of the electrode wire to __snap__ the electrode into place.

To remove spikey electrodes from the lead wires:
1. Using your thumb, press on the electrode while slightly bending the electrode holder. 
2. If that doesn't work, try using precision pliers. Carefully clamp the plastic end of the lead wire. _Using excessive force may break the plastic around the end of the lead wire._
3. Carefully bend the electrode holder with pliers while pressing the electrode and it should pop out. 

## Headband-Ganglion Tutorial

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Ganglion_Front.JPG?raw=true" width="50%">

The Ganglion board supports four channels of EEG/EMG/EEG input and can stream data over [bluetooth](http://docs.openbci.com/Hardware/08-Ganglion_Data_Format) or [wifi](http://docs.openbci.com/Tutorials/03-Wifi_Getting_Started_Guide). In this tutorial we will show you how to obtain two frontal lobe measurements and two temporal lobe measurements using the four channels of the Ganglion and stream the data over bluetooth!

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion.JPG?raw=true" width="50%">

#### Battery

All OpenBCI boards ship with a free 2-pin standard JST compatible 4-AA battery holder. For the best user experience, we recommend purchasing the LiPo battery and charger linked below.

1. [Lithium ion battery](https://www.adafruit.com/product/1578) and 
2. [USB charger](https://www.adafruit.com/product/1304)

We recommend this battery for its long battery life, compact size, and compatibility with all OpenBCI boards.

#### Hardware

Your Ganglion may have shipped with orange protective cellophane over switches sw1 - sw4. Once you've peeled the protective layer off, and flipped the switches to **down** position, they should look like the image below. Because we are using the Ganglion to obtain EEG, this step is IMPORTANT. 
 
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion_Switch.JPG?raw=true" width="50%">

See the [Ganglion Hardware page](http://docs.openbci.com/Hardware/07-Ganglion#openbci-ganglion-openbci-ganglion-board-inverting-input-select-switches) for a detailed explanation of why we flip the four channel switches to **down**.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Ganglion_Headband_Pins.JPG?raw=true" width="50%">

**Steps**
1. Connect one earclip electrode to the top D_G (driven ground) pin, as shown above.
2. Connect the second earclip electrode to the top REF pin, as shown above. 
3. Connect the female terminations of the two flat snap electrodes and two spikey electrodes to top pins 1-4, shown above. (The order of pin connections is up to user preference.)
4. Place the velcro headband between the clip end of a colored cable and a spikey electrode, making sure to align with the hole in the headband, then snap the spikey electrode into the clip
5. Place the velcro headband between the flap snap electrode and the snap end of a colored cable, making sure to align with the hole in the headband, then snap the electrode into place.

**Assembling the Headband**

The placement of nodes on the headband is best represented in the following image:
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/EEG%20Nodes_Updated_Ganglion.png?raw=true" width="50%">

In this diagram, the red circles represent areas where flat electrodes can be placed, and the blue circles represent areas where spiky electrodes can be placed. This placement is ultimately up to you, and the areas that you wish to record. However, a general suggestion for standard electrode placement is outlined in yellow.

To attach the electrodes to the headband:
1. Place the wire head on the rough side of the velcro
2. Place the electrode on the soft side of the velcro
3. Snap the two pieces together, with the velcro in between, to secure them.

The spikey electrodes are particularly difficult to insert. To attach them to the headband:
1. Loop the metal wire part of the connector around the neck of the electrode
2. Press down the plastic part to snap it into place around the neck of the electrode

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Spikey%20Electrode%202.jpeg?raw=true" width="30%">
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Spikey%20Electrode%201.jpeg?raw=true" width="30%">

Note that removal of electrodes takes place in the reverse order of these steps.

#### OpenBCI Software

Now that you've finished with the hardware set-up, the next step is to set up the GUI! Follow the GUI [tutorial](http://docs.openbci.com/Tutorials/02-Ganglion_Getting%20Started_Guide#ganglion-getting-started-guide-downloadinstallrun-the-openbci-gui) to prepare your computer to communicate with your Ganglion.

Once you've downloaded the GUI zip file per tutorial instructions, fire up the GUI [as shown in this YouTube video!](http://www.youtube.com/watch?v=NAM6eOA4a8Y)

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/headband_gui_ganglion.jpeg?raw=true" width="50%">

Notice the sharp peak-trough-peak wave behavior in the upper left time series window of the GUI. The first peak corresponds with the initiation of an eye blink, the trough immediately after shows a dip in alpha brain waves that syncs to the eye's closing for a fraction of a second! The peak immediately **after** the trough corresponds to the brain signals to the eyelid to reopen, thus concluding the blink cycle.

The band power window in the lower right of the GUI shows the relative strengths of the user's alpha, beta, gamma, delta, and theta brain waves. The GUI and Ganglion work together to separate and categorize brain waves based on characteristics like frequency and amplitude. 

In the screenshot below, you'll see this analysis utilized in another built-in function, the Focus Widget! When the alpha waves are (relatively) high and beta waves are low, the GUI translates this to a focused state.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI_Ganglion.png?raw=true" width="70%">

The Ganglion Signal window in the lower left of the GUI is one of the many other useful displays. For most bioelectrical measurements, you want the skin-electrode contact surface impedance to be low. Two of the four channels show lower impedance (these happen to be the flat snap electrodes that are touching the skin over the frontal cortex). This connection must be good, hence the green light to the left of the impedance value. If the impedance light in the GUI is red, you can improve the connection by making sure the electrodes are secured against the skin and making good contact. You may find it helpful to add a little [electrode paste](https://shop.openbci.com/collections/frontpage/products/ten20-conductive-paste-2oz-jars?variant=31373533198) to boost conductivity of the Ag-AgCl coating on the electrodes.


## Headband-Cyton Tutorial

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Headband_Cyton_Front.JPG?raw=true" width="50%">

The Cyton board supports eight channels of EEG/EMG/EEG input and can stream data over [bluetooth](http://docs.openbci.com/Hardware/03-Cyton_Data_Format) or [wifi](http://docs.openbci.com/Tutorials/03-Wifi_Getting_Started_Guide). In this tutorial we will show you how to obtain three frontal lobe measurements and five temporal lobe measurements and stream the data over bluetooth!

#### Battery

All OpenBCI boards ship with a free 2-pin standard JST compatible 4-AA battery holder. For the best user experience, we recommend purchasing the LiPo battery and charger linked below.

1. [Lithium ion battery](https://www.adafruit.com/product/1578) and 
2. [USB charger](https://www.adafruit.com/product/1304)

#### Hardware

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Cyton_Headband_Pins.JPG?raw=true" width="50%">

As shown above:

1. Connect one earclip electrode to the bottom BIAS pin
2. Connect the second earclip electrode to the bottom SRB pin
3. Connect the female terminations of the three flat snap electrodes to bottom pins 1-3 (labeled N1P, N2P, and N3P). (The order of pin connections is up to user preference.)
4. Connect the female terminations of up to five spikey electrodes to bottom pins 4-8 (labeled N4P through N8P). (The order of pin connections is up to user preference.)
5. Place the velcro headband between the clip end of a colored cable and a spikey electrode, making sure to align with the hole in the headband, then snap the spikey electrode into the clip
6. Place the velcro headband between the flap snap electrode and the snap end of a colored cable, making sure to align with the hole in the headband, then snap the electrode into place.

**Assembling the Headband**

The placement of nodes on the headband is best represented in the following image:
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/EEG%20Nodes_Updated_Cyton.png?raw=true" width="50%">

In this diagram, the red circles represent areas where flat electrodes can be placed, and the blue circles represent areas where spiky electrodes can be placed. This placement is ultimately up to you, and the areas that you wish to record. However, a general suggestion for standard electrode placement is outlined in yellow.

To attach the electrodes to the headband:
1. Place the wire head on the rough side of the velcro
2. Place the electrode on the soft side of the velcro
3. Snap the two pieces together, with the velcro in between, to secure them.

The spikey electrodes are particularly difficult to insert. To attach them to the headband:
1. Loop the metal wire part of the connector around the neck of the electrode
2. Press down the plastic part to snap it into place around the neck of the electrode

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Spikey%20Electrode%202.jpeg?raw=true" width="30%">
<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/Spikey%20Electrode%201.jpeg?raw=true" width="30%">

Note that removal of electrodes takes place in the reverse order of these steps.

#### OpenBCI Software

Now that you've finished with the hardware set-up, the next step is to set up the GUI! Follow the GUI [tutorial](https://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI) to prepare your computer to communicate with your Cyton.

Once you've installed the GUI by following the tutorial, fire it up [as shown in this YouTube video!](http://www.youtube.com/watch?v=XktF8OhHH4A)

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/headband_gui_cyton.jpeg?raw=true" width="50%">

Play around with the vertical scale, filter, frequency range to see the effect on the raw data. The following screenshot shows an example of what your live-streamed brain data might look like.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/headband-images/GUI_Cyton_B.png?raw=true" width="70%">

For more details on the various GUI functions, scroll up to the OpenBCI Software section of the Headband-Ganglion Tutorial above and also check out the cool features section of the GUI [page](http://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-cool-gui-features).

For cool project ideas, head over to this [**Instructables**](https://www.instructables.com/id/Send-Focus-Data-From-OpenBCI-GUI-to-Arduino/) Page!

**Use Cases for OpenBCI GUI**

* OpenBCI device owners want to visualize their brainwaves!
* Many of the researchers, hackers and students alike who purchase OpenBCI devices want to use them to acquire data as soon as their device arrives.
* Users use macOS, Windows and Linux to acquire data
* Users want to filter incoming data in real time
* Users want to make their own experiments to test their awesome theories or duplicate state of the art research at home!
* Users struggle to get prerequisites properly installed to get data on their own from OpenBCI Cyton and Ganglion.
* Users want to stream data into their own custom applications such as MATLAB.

**What You Can Do with OpenBCI GUI and Software Stack**

* Visualize data from every OpenBCI device: Ganglion, Cyton, Cyton with Daisy, and the WiFi Shield
* Playback files using GUI
* Run as a native application on macOS, Windows, and Linux.
* Apply filters and other data processing tools to quickly clean raw data in real time
* Use the GUI as a networking system to move data out of GUI into other apps over UDP, OSC, [LSL](https://github.com/OpenBCI/OpenBCI_LSL), and Serial.
* Send data to [MATLAB](https://docs.openbci.com/3rd%20Party%20Software/01-Matlab), Neuropype (using LSL), and other [third-party softwares.](https://docs.openbci.com/3rd%20Party%20Software/00-3rdPartySoftware)
* Analyze data with Python. Links [HERE](https://github.com/OpenBCI/OpenBCI_Python) and [HERE.](https://github.com/OpenBCI/pyOpenBCI)
* [Create a widget framework](https://docs.openbci.com/Tutorials/16-Custom_Widgets) that allows users to create their own experiments.
* Output data into a saved file for later offline processing.
* [Customize the layout](https://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-customize-your-layout), change the gain, toggle on/off, check impedance of individual channels of the CytonDaisy board (or any connected OpenBCI board) directly in the GUI!
* Access built-in widgets such as Focus Widget, Band Power, Accelerometer, EEG Head Plot, and MUCH more

As always, don't hesitate to email us at support@openbci.com for assistance!
