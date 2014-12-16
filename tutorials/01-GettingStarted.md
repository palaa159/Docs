# Getting Started w/ OpenBCI


## I. What You Need

![OpenBCI Contents](../assets/images/Contents8bit.png)

 1. OpenBCI board
 2. OpenBCI Dongle
 3. OpenBCI Electrode Starter Kit (ESK) or your own electrodes
 4. 6V AA battery pack & (x4) AA batteries (batteries not included)
 5. (x4) plastic feet for board stabilization

### 1. Your Board

![OpenBCI 8bit Top](../assets/images/8.jpg)

This tutorial can be followed if you are working with any OpenBCI board (8bit, 32bit, or 32bit with Daisy). I'll be working with the 8bit board.

### 2. Your OpenBCI USB Dongle

![OpenBCI Dongle](../assets/images/dongle.png)

The OpenBCI USB Dongle has an integrated RFDuino that communicates with the RFDuino on the OpenBCI board. The dongle establishes a serial (if you're working on a MAC) or COM (if you're on PC or Linux) connection with your computer with its on-board FTDI chip. You'll be connecting to this serial port from the OpenBCI GUI or whatever other software you want to end up using to interface your OpenBCI board.

### 3. Your Electrode Starter Kit (ESK) Or Other Electrodes

![Electrode Starter Kit](../assets/images/electrodeStarterKit.png)

If you ordered an Open BCI Electrode Starter Kit, it should come with:

 * 10 passive, gold cup electrodes on a color-coded ribbon cable
 * 4oz Jar of Ten20 conductive electrode paste
 
![TouchProof Adapter](../assets/images/touch_proof.jpg)
 
If you plan to work with your own electrodes, the touch-proof adapter may come in handy. It will convert any electrode that terminates in the industry-standard touch-proof design to an electrode that can be plugged into OpenBCI!

### 4. Your 6V AA Battery Pack & 4 AA Batteries

![Battery Connection](../assets/images/batteryConnection.png)

Both the 8bit board and the 32 bit boards have specific input voltage ranges. These input voltage ranges can be found on the back-side of the board, next to the power supply. **BE VERY CAREFUL** to not supply your board with voltages above these ranges, or else you will damage your board's power supply. For this reason, we recommend that you always use the battery pack that came with your OpenBCI kit.

### 5. (x4) Plastic Feet

![Plastic Feet](../assets/images/8bitboard_wPlasticFeet.png)

Your OpenBCI kit comes with 4 plastic feet that can be snapped into the wholes of your board to provide extra stability while working.

## II. Download & Install the OpenBCI GUI

### 1. Download the OpenBCI GUI App

![OpenBCI GUI](../assets/images/GUI.jpg)

From the links below or from our [downloads page], get the latest version of the OpenBCI GUI]. There are versions for [Mac OS X](http://ultracortex.com/downloads/application.macosx.zip), [Win32](http://ultracortex.com/downloads/application.windows32.zip), [Win64](http://ultracortex.com/downloads/application.windows64.zip), [Linux32](http://ultracortex.com/downloads/application.linux32.zip), and [Linux64](http://ultracortex.com/downloads/application.linux64.zip). If you’re having issues installing or launching the app, check out (or start) the [Forum section](http://openbci.com/index.php/forum#/categories/software) on this.

### 2. Or run it from Processing (for developers)

![Processing IDE](../assets/images/Processing.png)

You can also launch the application (and check out all of the code that makes it work) from the [Processing IDE](https://processing.org/). Processing is a very powerful Java-based creative coding framework with lots of great graphics libraries. The latest version of the code is always kept in our [OpenBCI_Processing](https://github.com/OpenBCI/OpenBCI_Processing) Github repo. You can also check out other branches of the code, where we’ll be trying out new features. For more information on working with the Processing code, check out the [Up & Running w/ The OpenBCI GUI](http://docs.openbci.com/03-OpenBCI_GUI) docs page.


### 3. Launch the OpenBCI GUI

![Launch GUI](../assets/images/LaunchGUI.png)

a. Double-click the **OpenBCI_GUI app** icon (or run the .exe file if you're on Windows) and the GUI should launch without any issues. If you're encountering an error here, please refer to the [Forum section](http://openbci.com/index.php/forum#/categories/software) on this.

![Synthetic](../assets/images/Synthetic.png)

b. Once the GUI is running, select "SYNTHETIC (algorithmic)" and hit the "START SYSTEM" button to launch the GUI with a synthetic data generator.

![Start Data Stream](../assets/images/StartDataStream.png)

c. Click the dark overlay on the GUI to exit the SYSTEM CONTROL PANEL and then hit the "Start Data Stream" button to begin the stream of synthetically generated EEG data. You should then see data streaming across the "EEG Data" graph on the left side of the GUI. 

## III. Prepare your OpenBCI Hardware


### 1. Make sure your FTDI drivers are installed and up-to-date

![FTDI Install](../assets/images/FTDI.png)

The FTDI chip on your OpenBCI Dongle requires you to install the FTDI drivers on your machine. You may already have these installed, if you've worked with Arduino or other USB hardware accessories. You can download the latest FTDI drivers for your operating system [here](http://www.ftdichip.com/Drivers/VCP.htm). **Note:** you may need to restart your GUI for this to take effect.

### 2. Plug in your OpenBCI USB Dongle

![Dongle Connection](../assets/images/dongleConnection.png)

Plug this in (facing upwards!) and you should see a blue LED light up.

**Note:** make sure your USB Dongle is switched to GPIO 6 and not RESET. The switch should be set closer to your computer as seen in the picture to the right.

### 3. Plug in your 6V AA batter pack (with batteries)

![Battery Connection](../assets/images/batteryConnection.png)

Both the 8bit board and the 32 bit boards have specific input voltage ranges. These input voltage ranges can be found on the back-side of the board, next to the power supply. **BE VERY CAREFUL** to not supply your board with voltages above these ranges, or else you will damage your board's power supply. For this reason, we recommend that you always use the battery pack that came with your OpenBCI kit. There's a good reason we put this notice in here twice!

### 4. Switch your OpenBCI board to PC (not OFF or BLE)

![Power Up Board](../assets/images/PowerUpBoard.JPG)

Make sure to move the small switch on the right side of the board from "OFF" to "PC". As soon as you do, you should see a blue LED blink 3 times. You don't press the reset button just to the left of the switch. If the LED still does not blink 3 times, make sure you have full battery. If you're sure your batteries are fully charged, consult the [hardware section](http://openbci.com/index.php/forum#/categories/hardware) of our Forum.

**Note:** it's important to plug in your Dongle before you turn on your OpenBCI board. Sometimes, if the data stream seems broken, you may need to unplug your USB Dongle and power down your OpenBCI board. Make sure to plug your USB Dongle in first, then power up your board afterwards.

## IV. Connect to your OpenBCI board from the GUI

### 1. Relaunch your OpenBCI GUI

You may need to relaunch the OpenBCI GUI after installing the FTDI drivers.

### 2. Select LIVE (from OpenBCI)

![Select Live](../assets/images/selectLIVE.png)

In order to connect to your OpenBCI, you must specify the data source to be "LIVE (from OpenBCI)" in the first section of the SYSTEM CONTROL PANEL. Before hitting the START SYSTEM button, you need to configure your OpenBCI board (follow the steps below).

### 3. Find your USB Dongle's Serial/COM port 

![Select Serial](../assets/images/selectSerial.png)

In the first section of the LIVE (from OpenBCI) sub-panel, find your Dongle's Serial/COM port name. If you're using a MAC, it's name will be in the following format:

**/dev/tty.usbserial-DNxxxxxx**

If you're using Windows or Linux, it will appear as:

**COM#**

Your USB Dongle's port name will likely be at the top of the list. If you don't see it:

1. Make sure your dongle is plugged in and switched to GPIO 6 (not RESET)
2. Click the REFRESH LIST button in the SERIAL/COM PORT section of the sub-panel
3. Make sure you've installed the latest FTDI drivers, as described in section III.1

If you're still having trouble finding your USB Dongle's port name, refer to the [Forum](http://openbci.com/index.php/forum#/categories/hardware) about debugging your hardware connection.

### 4.(optional) Edit the Playback file name

![File Name](../assets/images/fileName.png)

In the DATA LOG FIlE section of the LIVE (from OpenBCI) sub-panel you can specify the name of your playback file. This file name is automatically defaulted to:

**SavedData\OpenBCI-RAW- + date/time**

You can edit the the name of this file by clicking in the "File Name" text field.

If you're running the OpenBCI GUI from Processing. This file will be saved at the root of your OpenBCI_GUI directory. 

If you're running the OpenBCI GUI as a standalone application, this file will be saved in /Contents/Java/Data/EEG_Data/

If working from a Mac, you'll need to right-click on the OpenBCI_GUI application and then select "show package contents" to see the /Contents directory where your playback files are saved.

After creating a Playback file, it can be replayed by running the OpenBCI GUI with the Plaback File data source mode. As a result, you can easily share recorded OpenBCI Playback files with your friends and colleagues.

### 5 Select your channel count (8 or 16)

![Channel Count](../assets/images/channelCount.png)

The CHANNEL COUNT setting is defaulted to 8. If you are working with an OpenBCI Daisy Module and 32bit board (16-channel) system, be sure to click the 16 CHANNELS button before starting your system.

### 6. Select your SD setting

![WRITE TO SD](../assets/images/writeToSD.png)

If you want to log data to a MicroSD inserted into the OpenBCI Board, in the WRITE TO SD (Y/N)? sub-panel section you can select the maximum recording time of the file. This setting is defaulted to "Do not write to SD…" and will automatically switch to this if you do not have a MicroSD card properly inserted into your OpenBCI Board.

**Note:** be sure to select a file size that is larger than your planned recording time. The OpenBCI writes to the local SD in a way that enables us to write lots of data very quickly. As a result, however, we must specify how large the file will be before we begin. The technique is known as block writing.

### 7. Press "START SYSTEM"

![START SYSTEM](../assets/images/startSystem.png)

Now you're ready to start the system! Press the START SYSTEM button and wait for the OpenBCI GUI to establish a connection with your OpenBCI Board. This usually takes ~5 seconds. 

![Initializing](../assets/images/initializing.png)

During this time, the help line at the bottom of the OpenBCI GUI should be blinking the words: "Initializing communication w/ your OpenBCI board."

**TROUBLESHOOTING**

If the initialization fails, try the following steps in order:

1. Making sure you've selected the correct serial/COM port
2. Power down your OpenBCI board and unplug your USB Dongle. Then, plug back in your USB Dongle and power up your OpenBCI board in that order. Then try restarting the system, but pressing the START SYSTEM button again.
3. If this does not work, try relaunching the OpenBCI GUI application and redo step 2 above. Then reconfigure the SYSTEM CONTROL PANEL settings, and retry START SYSTEM.
4. Make sure that your batteries are fully charged and then retry the steps above.
5. If you are still having troubles connecting to your OpenBCI board, refer to the [Forum](http://openbci.com/index.php/forum) for extra troubleshooting advice.

### 8. Your OpenBCI is now live!

![Start Stream](../assets/images/startStream.png)

Once the GUI successfully connects to your OpenBCI Board, click anywhere outside of the SYSTEM CONTROL PANEL to access the rest of the features of the GUI.

You can now press the bright green Start Data Stream button (located at the top middle of the GUI) to begin streaming live data from your OpenBCI board.

![Touch](../assets/images/touch.JPG)

To make sure that it is responsive, (after you've started the data stream) try running your fingers along the electrode pins at the top of your board. 

![Chaos](../assets/images/chaos.png)

You should see the 8 (or 16 if you're using a Daisy module) channels on the EEG DATA montage behave chaotically in response to you touching the pins. The headplot on the right side of the GUI should become fully saturated (turning bright red) when you do this. And all the tracess of the FFT graph on the lower right should instantly shift upwards.

If this is the case, congratulations; you are now connected to your OpenBCI board. It's time to see some brain waves!

## V. Connect yourself to OpenBCI

In this quick demo, we'll be showing you how to set up 3 channels of electrophysiological data that reveal your heart activity (EKG or ECG), muscle activity (EMG), and brain activity (EEG)!

For more information on these three signals, refer to wikipedia:

 * [Heart Acitivity - Electrocardiography (EKG or ECG)](http://en.wikipedia.org/wiki/Electrocardiography)
 * [Muscle Acitivity - Electromyiography (EMG)](http://en.wikipedia.org/wiki/Electromyography)
 * [Brain Activity - Electroencephalography (EEG)](http://en.wikipedia.org/wiki/Electroencephalography)


### 1. What you need

![What You Need](../assets/images/whatYouNeed.JPG)

#### Necessary:

* Ten20 conductive elctrode paste (or other conductive electrode gel)
* Your OpenBCI board, USB Dongle, battery pack, and x4 AA batteries
* x6 gold cup electrodes (from your OpenBCI electrode starter kit or other). If you are using an OpenBCI electrode starter kit, use the following electrodes so as to be consistent with the GUI's color-coding protocol:
  1. Black
  2. White
  3. Purple
  4. Green
  5. Blue
  6. Red
 
#### Optional:

* Paper towels for cleaning excess Ten20 paste
* Medical tape (or other tape) for adding extra stability to electrodes
* Ear swabs for cleaning paste from electrodes, once you're finished

### 2. Connect your electrodes to OpenBCI

![Electrode Connections 1](../assets/images/electrodeConnections1.JPG)

1. Connect the white electrode to the SRB2 pin (the bottom SRB pin). The SRB2 pin is the default "reference pin" for your OpenBCI input channels. 
2. Connect the black electrode to the bottom BIAS pin. The BIAS pin is similar to the ground pin of common EEG systems, but it uses destructive interference waveform techniques to eliminate the "common mode noise" of all of the active channels.
3. Connect the purple electrode to the 2N pin (the bottom pin of the N2P input)
4. Connect the green electrode to the 4N pin (the bottom pin of the N4P input)
5. Connect the blue electrode to the 4P pin (the top pin of the N4P input)
6. Connect the red electrode to the 7N pin (the bottom pin of the N7P input)

![Electrode Connections 2](../assets/images/electrodeConnections2.JPG)

#### Basic OpenBCI pin overview

The picture to the right is a perspective view of the electrode inputs that we are working with in this tutorial. The bottom pins are (N) inputs, and the top pins are (P) inputs. The default board settings look at all N channels in refernce to SRB2 (the bottom SRB pin). SRB1 (the top SRB pin) can also be used as a reference, but when it is activated, it is activated for ALL channels. If using SRB1 as the reference electrode, P inputs must be used as the other input of the potential difference measurement. On the contrary, individual channels can be removed from SRB2. If a channel is removed from SRB2, it can be examined as a unique voltage potential, between the N and P pins of that channel. We will be doing this for the heart measurement in this tutorial, while examining 2 EEG channels in reference to SRB2, using the channel 2 and 7 N pins. For more information on this, refer to page 16 of the [ADS1299 datasheet](http://www.ti.com/lit/ds/symlink/ads1299.pdf). The ADS1299 chip is the analog front-end at the core of the OpenBCI board.

### 3. Connect your electrodes to your head and body

![Electrode Paste](../assets/images/electrodePaste.png)

a) We're going to start with the electrodes on your head. Begin by scooping Ten20 electrode paste into your white gold cup electrode. This is going to be your reference (or SRB2) electrode for the other electrodes on your head. Fill the electrode so there is a little extra electrode paste spilling over the top of the gold cup, as seen in the picture to the right. 
 
**Note:** Use a paper towl or napkin to remove excess electrode paste as you are applying your electrodes.

![SRB2](../assets/images/earlobe.JPG)
 
b) Now apply this electrode to either one of your earlobes (either A1 or A2 as seen on the 10-20 system image  below). You can use some medical tape (or electric tape!) to give this electrode some extra stability, ensuring that it does not fall off. This electrode is the reference that all of the EEG electrodes on your head will be measured in comparison to. The uV reading that will appear in the GUI's EEG DATA montage is a measure of the potential difference between each electrode and this reference electrode (SRB2). SRB1 (the top SRB pin) can also be used as a reference pin, but we won't discuss that here. Check out the other docs on how to maximize the usage of the other pins!

![Fp2](../assets/images/Fp2.JPG)
 
c) Follow the same procedure for the purple electrode and apply it to your forhead 1 inch above your left eyebrow (as if you were looking at yourself) and an inch to the left of your forheads centerline. 
 
![1020](../assets/images/1020.jpg)
 
This electrode location is Fp2 on the [10-20 System](http://en.wikipedia.org/wiki/10-20_system_%28EEG%29). The 10-20 System international standard for electrode placement in the context of EEG. Fp indicates the a "frontal polar" site.
 
![O1](../assets/images/O1.JPG)
 
d) Now follow the same procedure for the red electrode and place it on the back of your head, 1 inch above the inion (as seen on the 10-20 system), and 1 inch to the left. This electrode location is O1 on the 10-20 system. The 'O' stands for occiptal, meaning above your occipital lobe (or visual cortex).
 
**Note:** to do this, pull your hair aside and make sure the electrode is nested as deeply as possible, with the electrode paste making a definitive conductive connection between your scalp and the gold cup.

![headband](../assets/images/headband.JPG)

e) Now follow the same procedure as step 2 above to apply the black electrode to your other earlobe (either A1 or A2 from the 10-20 system). The black electrode is connected to the BIAS pin, which is used for noise cancelling. It is similar to a GROUND pin, which establishes a common ground between the OpenBCI board and your body, but it has some extra destructive interference noise cancelling techniques built in! 

You're now done connecting electrodes to our noggin! I like to use a cheap cotton hairband to add extra stability to all of the electrodes connected to my head, by placing it gently on top of all of the electrodes. 
 
![forearm](../assets/images/forearm.JPG)

f) Now connect the green electrode to your right forearm, somewhere on top of a muscle that you can flex easily. With this electrode we will be looking at both heart activity and muscle activity. I also like to use tape to hold this electrode in place. That's going to hurt a little bit to take off. Hopefully your arms aren't as hairy as mine...

![wrist](../assets/images/wrist.JPG)

g) Finally, connect the blue electrode to your wrist on the opposite arm with the green electrode. This will serve as the reference electrode for the blue electrode. If you noticed, the blue electrode is on the pin above the green electrode. We will be removing pin 4 from SRB2 so that it is not included in the same reference signal being used to measure brain waves. The main reason for this is because the microvolt (uV) values produced by your heart and muscles are much stronger than the signals we can detect from your brain, so we don't want these signals to interfere. I'll go into more detail about this later on, when it comes time to adjust the channel settings in the GUI.
 

### 4. Launch the GUI and adjust your channel settings

1. If your OpenBCI GUI is not already running, relaunch it and configure the DATA SOURCE mode to LIVE (from OpenBCI). Refer to **section IV** of this guide for more information on this process. Since we are only using 3 channels, set the channel count to 8, even if you have a daisy system. Nothing will go wrong if you start the system with 16 channels, except the EEG DATA montage will be unnecessarily cluttered.

2. Once you have pressed START SYSTEM and the GUI has connected to your OpenBCI device, exit the SYSTEM CONTROL PANEL and start the live data stream. You should see live data from your body (and the unattached channels) streaming into the EEG DATA montage on the left side of the GUI.

![Power Down](../assets/images/powerDown.JPG)

3. Now we are going to power down the channels we aren't using. Do this by clicking the channel number buttons outside of the left side of the EEG DATA montage. We are only using channels 2, 4, and 7, so power down every other channel. Don't bother with the smaller dark grey squares to the right of the buttons with numbers; they are used for impedance measuring, but we won't go into that now. You can also power down the channels with keyboard shortcuts (1-8). Power them back up with [SHIFT] + 1-8. If you are working with a daisy module, channels 9-16 can be powered down with q, w, e, r, t, y, u, i, respectively. You can power those channels back up with [SHIFT] + the same key. 

![Signals At Start](../assets/images/signalsAtStart.png)

4. Now that you have powered down channels 1, 3, 5, 6, and 8, your EEG DATA montage should look similar to the screenshot on the right (after you relax and let the system settle).

![Adjust Channel Settings](../assets/images/adjustChannelSettings.png)

5. Adjust the channel settings...


### 5. Minimize system noise

### 6. Check out your heartbeat

### 7. Watch your muscles flex

### 8. Check out your blink artifacts

### 9. Brain waves (Alpha) with OpenBCI!

### 10. More on how to use the OpenBCI GUI


## MORE COMING SOON...




# -- CRUDE BELOW THIS POINT --






a. Attach the 4 plastic feet to your OpenBCI board plus some spaghetti



b. Buy 4 AA batteries and put them in your battery pack

![Pin Connections](../assets/images/PinConnections.png)

c. Connnect the battery pack to the OpenBCI board



d. Connect your electrodes to the OpenBCI board: Black->BIAS; White->SRB; Gray->N1P

![Test Setup](../assets/images/TestSetup.png)

e. Connect the USB Dongle to your computer

### 3. Software Setup
![Processing Libaries](../assets/images/processing_libraries.png)

1. Download Processing
2. Download GWOptics and ControlP5 Libraries
3. Unzip the libraries and put them in the /Processing/libraries/ folder.
4. Download the OpenBCI_Processing Github Repository:
`git clone https://github.com/OpenBCI/OpenBCI_Processing.git`

### 4. Headware Setup
![Electrode Paste](../assets/images/electrodePaste.png)

1. Apply electrode paste to the 3 electrodes. Make sure to add enough paste so that it forms a convex shape on the electrode cavity, allowing for a strong seal with the skin.
2. Connect 1 ground electrode (typically to the mastoid behind the ear)
3. Connect 1 reference electrode to the earlobe
4. Connect 1 EEG channel electrode (any location on the head from where you want to sample EEG)

### 5. Test It
![Testing](../assets/images/testing_screenshot.png)

1. Open the file OpenBCI_GUI.pde in Processing and run the program.
2. Select your serial/COM port in the left hand menu and click Initialize System.
3. If for some reason, the brainwaves don't start streaming, switch your OpenBCI board to Off and then back to "PC", and redo the previous step.
4. Click into the main interface and press Tab to change to Channel settings.
5. De-select every channel but the one your EEG channel electrode is connected to, which will be Channel 1 if you connected it to the N1P pin.
6. If all goes as it should, you should see your brainwaves streaming out.
7. Play with the controls to get a feel for different ways to view the data.
8. Blink your eyes, grit your teeth, play around with it!
