# Streaming EMG Data with Cyton/Ganglion 


This tutorial will show you how to read EMG data (electrical signals from muscles) using OpenBCI hardware and GUI.

## Materials Needed

1. OpenBCI [Cyton Board](https://shop.openbci.com/collections/frontpage/products/cyton-biosensing-board-8-channel?variant=38958638542) or [Ganglion Board](https://shop.openbci.com/collections/frontpage/products/pre-order-ganglion-board?variant=13461804483)
2. [Skintact sticky electrodes](https://shop.openbci.com/collections/frontpage/products/skintact-f301-pediatric-foam-solid-gel-electrodes-30-pack?variant=29467659395)
3. [EMG/ECG Snap Electrodes](https://shop.openbci.com/collections/frontpage/products/emg-ecg-snap-electrode-cables?variant=32372786958)
4. [OpenBCI GUI](https://openbci.com/index.php/downloads)

To determine the number of electrodes you will need, add up:
- Two electrodes for each muscle group you are streaming data from
- One electrode to serve as the ground

The electrode pairs for each muscle group will serve as the positive and negative terminals across which a potential difference can be detected.

## Create files and folders

The file explorer is accessible using the button in left corner of the navigation bar. You can create a new file by clicking the **New file** button in the file explorer. You can also create folders by clicking the **New folder** button.

## 1. Connecting Electrodes to the OpenBCI Board

Connect each electrode pair (for each muscle group) to the top and bottom pins of each row N(x)P, where x is any of the numbers corresponding to a GUI channel. *Note: On the Cyton board, there are 8 channels available, and on the Ganglion board there are 4 channels available.*

Additionally, connect the ground pin to the AGND pin.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/EMG_Cyton_Setup.jpg?raw=true" width="50%">

In the image above, note how the positive and negative terminals (yellow and green) are connected to the top and bottom N1P pins. When you are running the GUI, data from N1P pins will be displayed on Channel 1 within the [Time Series Widget](https://docs.openbci.com/OpenBCI%20Software/02_GUI_Widget_Guide#gui-widget-guide-what-is-a-gui-widget)
.
After making these pin connections, connect the sticky electrodes to the snap electrodes **prior to applying to the skin**

## 2. Electrode-Muscle Connection

Choose muscle groups that can be flexed and relaxed easily. Place one electrode at the base of the muscle, and the other electrode at the tip of the muscle. The order of these doesn’t matter, as long as they are both linked to the same channel number. Place the ground electrode on a bony part of the body with as few muscles as possible (e.g. elbow, calf).

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/EMG_Electrode_Placement.jpg?raw=true" width="50%">

## 3. Streaming EMG Data with the OpenBCI GUI

Once you have the GUI open, turn off any channels that you have not connected to muscle sensors. Then, go to hardware settings and turn off SRB2 for all of the channels that you are streaming data from.

*Note: This is because ordinarily SRB2 is the reference point from which potentials are measured, however we are now having muscles reference themselves, so we do not want it to look at this pin.*

When you are happy with your GUI Time Series and Hardware settings, press "BEGIN DATA STREAM."

Here is an example of what your data stream should look like as you flex and relax your muscle:

![EMGGIF](https://media.giphy.com/media/VbVRPTNTb4QAuUiwyb/giphy.gif)

## 4. Using OpenBCI's EMG GUI Widget
The OpenBCI GUI also has a widget for visualizing EMG data. To view it, click on the drop down menu under “FFT Plot”, and select “EMG” instead:
<insert image>
Each circle and box represents a channel. The circle and box fill up as the intensity of the signal on that channel increases.

Look at the <media> gif above to see how this widget behaves when flexing and relaxing your muscle, and see the [GUI widget guide](https://docs.openbci.com/OpenBCI%20Software/02_GUI_Widget_Guide) for more information.

