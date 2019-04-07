# GUI to Arduino Focus Example

This tutorial shows you how to create your own custom widgets for the [OpenBCI GUI](https://github.com/OpenBCI/OpenBCI_GUI). In just a few easy steps you can have your own mini applications added to the dropdown menus of the OpenBCI GUI for running specialized applications in real-time. These widgets can tap directly into the main data structure of the OpenBCI GUI, so you can experiment with brain waves and other bio data right in the GUI.

## What is a GUI Widget?

GUI widgets are the mini tools that fit into the OpenBCI GUI's interface panes. Examples of GUI widgets include the Time Series, the FFT widget, the Networking widget, and so on. In the upper left hand corner of every widget there is a dropdown menu that lists all of the available widgets. If you click the dropdown and select a new widget from the dropdown, it will replace the widget that currently fills the container you are inside of. You can rearrange the layout of the widget containers by clicking the "Layout" button in the upper righthand side of the GUI. Follow the rest of this tutorial to try creating your own!

## Helpful Background Skills

* Knowledge of [Arduino](https://www.arduino.cc/reference/en/) or C-based programming
* Experience with [running the OpenBCI GUI from the Processing IDE](https://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-running-the-openbci-gui-from-the-processing-ide)


### Step 1 - Load the Example from the Docs in Arduino IDE

The [OpenBCI_GUI-FocusArduino.ino](../assets/files/OpenBCI_GUI-FocusArduino/OpenBCI_GUI-FocusArduino.ino) file is designed to serve as a simple starting point for creating your own Arduino project using data from the GUI over serial.


### Step 2 - Upload the Arduino sketch



### Step 3 - Start streaming to the Arduino using the Networking Widget

![OpenBCI Serial Not Focused](../assets/images/gui_arduino_serial_notFocused.png)

### Step 4 - Turn off channel one to simulate Focused state

![OpenBCI Serial Not Focused](../assets/images/gui_arduino_serial_Focused.png)


### Step 5 - share your custom widget with the world!

If you make a functional that you think others could benefit from, please share it with the world by submitting a pull request to the [OpenBCI_GUI repo](https://github.com/OpenBCI/OpenBCI_GUI)! 

