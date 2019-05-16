# OpenBCI GUI Widget Tutorials

This contains page contains in-depth information on OpenBCI "Widgets" in the OpenBCI GUI. After going through the [Cyton Getting Started GUI](https://docs.openbci.com/Tutorials/01-Cyton_Getting%20Started_Guidem), you may want to learn more about what the GUI can do. This is the place!

In the picture below, we see four Widgets: Time Series, Head Plot, FFT Plot, and Focus Widget.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/GUI-V4-Screenshot.jpg?raw=true" width="50%">

Widget behavior may vary depending on the data mode being used. Using the picture above as an example, you can see the Playback Scrollbar and current time displayed at the bottom of the Time Series Widget while in Playback Mode.

There is a separate tutorial that explains the basics of [creating your own Widget](https://docs.openbci.com/Tutorials/16-Custom_Widgets).

<details><summary> What is a "GUI Widget"?</summary><br>

#### What is a GUI Widget?

GUI widgets are the mini tools that fit into the OpenBCI GUI's interface panes. Examples of GUI widgets include the Time Series, the FFT widget, the Networking widget, and so on. In the upper left hand corner of every widget there is a dropdown menu that lists all of the available widgets. If you click the dropdown and select a new widget from the dropdown, it will replace the widget that currently fills the container you are inside of. You can rearrange the layout of the widget containers by clicking the "Layout" button in the upper righthand side of the GUI. The FFT widget is pictured below.

![image](../assets/images/fftWidget.png)

</details>

## What do I need to learn more?
- The [OpenBCI_GUI](https://github.com/OpenBCI/OpenBCI_GUI/releases/latest) standalone app or Processing sketch
- An [OpenBCI Board](https://shop.openbci.com/collections/frontpage) *(Required to access some widgets)*

## EMG Widget

<details><summary> Expand this dropdown for a breakdown of the EMG Widget, originally shared in the OpenBCI Forum.</summary><br>

**In a nutshell, we are trying to map the current flex of a muscle into the "comfortable flex range" of said muscle, and then represent that as a decimal between 0 and 1.** Having the normalized value is nice because then you can apply it as scalar to any other variable, allowing for a pseudo-analog mapping of the strength of any muscle flex to an arbitrary output. In theory, if you relax, the value will be 0, and if you flex, the value will go to 1. The current EMG strength is a collection of raw voltage values averaged (or smoothed) over a known window of time. The bigger the window your averaging over, the smoother the data.

We establish an upper threshold (the outer dark blue circle of the circular visualizer) and a lower threshold (the inner dark blue circle) for the constantly updating "comfortable EMG range." Then we're mapping the current EMG (the filled circle that matches the color of the channel) value between the upper and lower thresholds. This pseudo-analog mapped value is represented more clearly in the bar graph off to the right of each channel's circular visualizer. The upper threshold is constantly creeping downwards and lower threshold is constantly creeping upwards until they get the Min ΔuV away from one another. This ensures that the overall system never creates an upper/lower flex range that is too big to influence with a muscle flex. The drop-downs of the widget are designed to allow you to tweak the various parameters of this relationship.

There are 4 drop-downs giving us control over 4 parameters: 
1) **Smooth**
2) **uV Limit** 
3) **Creep** 
4) **Min ΔuV**

#### Smooth: 
This is the size of the window. If we set this value at the smallest setting of 0.01 seconds (ie lowering the smooth value), our data will be very jittery but responsive. Alternatively, if we increase the smooth and set our window to 2.0 seconds, the output will be very smooth but not as responsive.

#### uV Limit: 
This is a cutoff point for an allowable uV value in any individual data block. Any uV values above this number will be chopped off, and set to this upper uV limit. This is to prevent crazy big blips in the data from substantially distorting the average. Sometimes dropped packets and rapid body movements can great large spikes that don't correlate to muscle activity. This helps account for those issues.

#### Creep: 
This value indicates how quickly the upper uV limit creeps downward and how quickly the lower limit creeps upward. Notice that by adjusting this value, the upper threshold and lower threshold rings will creep inwards more quickly. I prefer this to be slow. If this is too fast and we wait too long between muscle activations, the upper threshold will have crept very close to the lower threshold and the system will be hyper sensitive. This can certainly be improved with a smarter algorithm.

#### Min ΔuV: 
This value sets the minimum voltage range between the upper threshold and lower threshold. The upper threshold and lower threshold cannot get any closer than this. By making this value bigger, you will have to flex harder to go from 0 to 100% flex, after the thresholds have crept as close as they will get to one another (aka Min ΔuV).

</details>


## Playback History Widget

This Widget only appears when in playback mode. It allows you to select a different playback without having to "Stop System". There is a button in the top right of the Widget that allows you to select any OpenBCI playback file (.txt or .csv). Selecting other types of files may cause an error.
___

##### More Info Coming Soon!

Have a new Widget or information on an existing Widget? [Suggest changes to this doc.](https://github.com/OpenBCI/Docs/edit/master/OpenBCI%20Software/01-OpenBCI_GUI.md)