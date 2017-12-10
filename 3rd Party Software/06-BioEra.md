# BioEra

From the BioEra homepage: BioEra is a visual designer useful for analyzing signals in real time. It can be used with any device with ability to stream data to a computer.

BioEra is used to create a design visually. A design represents data flow from input (e.g. biofeedback device) to output (e.g. visual or sound feedback). The flow can be customized with hundreds built-in objects (elements). For example an amplitude of alpha brainwaves can be filtered from input EEG signal, it can then trigger a MIDI, video or a computer task at a certain threshold level. 

## Setting Up Your Environment

**Windows:** BioEra only works with Windows and Android systems.

**MacOS and Linux:** If you have Mac OS or Linux, you can use BioEra through a virtual machine program like VirtualBox. Check out our VirtualBox tutorial [here!](http://docs.openbci.com/Tutorials/12-Win7_VM_Installation)

## Installation

Click on the download link for the trial version of BioEra here: (http://www.proatech.com/download.php). If you're using a virtual machine, be sure to download and set up BioEra from within the VM environment.

Click **BioEra Trial 4.027 for Windows - full**, or the equivalent link for the latest version, and follow the prompts to run the program.

During installation, you may get an error that your computer or virtual machine has the incorrect processor for the program; just disregard the warning and continue with the installation.

## Getting Started

Once installation is complete, navigate to the new "BioEraTrial" folder and double-click the "bioera" executable file. This will run BioEra.

A PacMan demo will pop up automatically. Play around with the demo, or take a look at the [BioEra website](http://www.bioera.net/index.shtml), to learn more about the software's capabilites.

## Streaming from OpenBCI within BioEra

This section will show how to stream data live from your OpenBCI board within BioEra. 

1. Start BioEra. To start a new project, select System -> New Design from the toolbar of one of the windows.
2. Two new windows will appear - one with a light gray background (the "design" window) and one with a dark gray background (the "output" window). In the design window, select Element -> New.
3. In the New Element window, find the "FTDI Serial Port" object. Select it and click "OK".
4. An FTDI icon should now be visible in the design window.
5. Navigate to Element -> New again from the toolbar. Find the "OpenBCI" object. Select it and click "OK". 
6. An OpenBCI icon should now be visible in the design window.
7. Connect the output of the FTDI object with the input of the OpenBCI object, as shown. To connect the two objects, click on the output of the FTDI object, the click on the input of the OpenBCI object.
8. Select an Oscilloscope object and connect one of the OpenBCI channels to it.

## Documentation

To learn more about BioEra, look through their [manual](http://www.proatech.com/be/manual.html) or [forum](http://www.bioera.net/support/forum.jsp).

Build something new using BioEra and OpenBCI hardware? Post about it on our [community page!](http://openbci.com/community/)
