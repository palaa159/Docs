# Custom GUI Widgets

This tutorial shows you how to create your own custom widgets for the [OpenBCI GUI](https://github.com/OpenBCI/OpenBCI_GUI). In just a few easy steps you can have your own mini applications added to the dropdown menus of the OpenBCI GUI for running specialized applications in real-time. These widgets can tap directly into the main data structure of the OpenBCI GUI, so you can experiment with brain waves and other bio data right in the GUI.

## What is a GUI Widget?

GUI widgets are the mini tools that fit into the OpenBCI GUI's interface panes. Examples of GUI widgets include the Time Series, the FFT widget, the Networking widget, and so on. In the upper left hand corner of every widget there is a dropdown menu that lists all of the available widgets. If you click the dropdown and select a new widget from the dropdown, it will replace the widget that currently fills the container you are inside of. You can rearrange the layout of the widget containers by clicking the "Layout" button in the upper righthand side of the GUI. Follow the rest of this tutorial to try creating your own!

## Helpful Background Skills

* Knowledge of [Processing](https://processing.org/) or Java-based programming
* Experience with [running the OpenBCI GUI from the Processing IDE](http://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-running-the-openbci-gui-from-the-processing-ide)


### Step 1 - duplicate the W_template.pde file & rename

The [W_template.pde](https://github.com/OpenBCI/OpenBCI_GUI/blob/master/OpenBCI_GUI/W_Template.pde) file is designed to serve as a simple starting point for creating your own widgets. You'll want to start by duplicating this file and renaming it to something like W_myNewWidget.pde, where 'myNewWidget' is something relevant to the purpose of your new widget! Try to adhere to the naming convention and put 'W_' in front to make sure that all of your widgets end up next to one another in your project directory.

You need to remember to rename the class to make sure that it is a unique and not the same class as W_template.pde. The first uncommented line of your file should read:

`class W_myNewWidget extends Widget {`

### Step 2 - add your new widget to the widgetManager.pde file

Before adding any fancy code that grabs ahold of local data structures, make sure you add your new widget to the [widgetManager.pde](https://github.com/OpenBCI/OpenBCI_GUI/blob/master/OpenBCI_GUI/WidgetManager.pde) file. By doing this, you make sure your new widget is added to the dropdown menu of each widget. This is helpful because now you can see what your doing as you add graphics to your widget as you continue to develop it.

Follow the protocol instantiating your widget globally by adding it here:

`// MAKE YOUR WIDGET GLOBALLY
W_timeSeries w_timeSeries;
W_fft w_fft;
W_networking w_networking;
W_BandPower w_bandPower;
W_accelerometer w_accelerometer;
W_ganglionImpedance w_ganglionImpedance;
W_headPlot w_headPlot;
W_template w_template1;
W_emg w_emg;
W_openBionics w_openbionics;
W_Focus w_focus;
W_PulseSensor w_pulsesensor;`

### Step 3 - make sure your widget appears in the widget dropdown




### Step 4 - design your custom widget


### Step 5 - share your custom widget with the world!