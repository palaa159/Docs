# MATLAB

[MATLAB](https://en.wikipedia.org/wiki/MATLAB) is a powerful numerical computing language and environment that is widely used in a wide variety of academic, research, and industry applications. 

A few Matlab toolboxes have been created specifically for working with EEG and BCI. [EEGLAB](http://sccn.ucsd.edu/eeglab/), [BCILAB](http://sccn.ucsd.edu/wiki/BCILAB), [ERPLAB](http://erpinfo.org/erplab), and [FieldTrip](http://www.fieldtriptoolbox.org/) are a few toolboxes that have helped OpenBCI users work in MATLAB.

This tutorial will walk through setting up your Matlab environment for use with OpenBCI hardware, as well as some basic uses and functionalities that Matlab offers for working with brain-computer interfaces.

#### Installation
Go to the [MathWorks website](http://www.mathworks.com/help/install/ug/install-mathworks-software.html) for MATLAB installation instructions. 

*Please note that MATLAB is commercial software. Licenses must either be purchased or acquired through academic or professional institutions.*

Several useful MATLAB toolkits (EEGLAB, BCILAB, FieldTrip, etc) have been created for collecting and analyzing EEG data, so this tutorial will focus on using MATLAB through these toolkits.

## Loading OpenBCI Data

To get started, use your OpenBCI board (like the Cyton or Ganglion board) and the OpenBCI GUI to stream some data. Whenever you stream data to the GUI, it's also automatically saved in .csv format on your computer. On MacOs, data is saved to a folder called "SavedData" that's in the same location as your OpenBCI application:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Third_party_software/saved_data_folder.png?raw=true" width="80%">

The save location for an OpenBCI GUI session is also at the top of the window:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/Third_party_software/save_location_GUI.png?raw=true" width="80%">

The OpenBCI Processing GUI saves data in text (txt) or comma separated value (csv) files. Import the CSV file into MATLAB as a matrix by using the "Import Data" wizard:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/matlab_tutorial/matlab_import_data.png?raw=true" width="80%">

Select a saved OpenBCI data file. Once the data import screen is open, select the "Numeric Matrix" import option. Deselect all of the header rows. Also deselect the final column, the timestamp values, since the import wizard can only parse numeric values. Feel free to give your matrix a conveneint name, like "eeg_data":

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/matlab_tutorial/matlab_import_screen.png?raw=true" width="80%">

Click "Import Selection". Your matrix should now appear as an object in your workspace! Keep reading to learn more about processing your data with MATLAB toolboxes.


## EEGLAB

From the EEGLAB wiki: "EEGLAB is an interactive Matlab toolbox for processing continuous and event-related EEG, MEG and other electrophysiological data using independent component analysis (ICA), time/frequency analysis, and other methods including artifact rejection."

#### Setup
Go to the [EEGLAB downloads page](http://sccn.ucsd.edu/eeglab/downloadtoolbox.html) and follow the instructions for your operating system.

Download the zip file of the most current version of EEGLAB and extract it into a directory on your system. Then, make this toolbox accessible from Matlab by adding a path to this directory (the steps to do this vary by OS - see the "EEGLAB downloads page" link above).

To check if EEGLAB is correctly set up, go to the Matlab prompt and type:
> \>\> eeglab

If the toolkit is not yet correctly implemented, the console should output:
"Undefined function or variable 'eeglab'."

If it is set up correctly, a pop-up window should appear with the EEGLAB GUI.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/Matlab/eeglab_gui.jpg?raw=true" width="70%">

#### Preparing OpenBCI Datasets for EEGLAB Use
OpenBCI saves data in the opposite orientation from what EEGLAB needs. So, after importing your OpenBCI data to MATLAB as described above, perform a simple matrix transposition:
```
eeg_data = eeg_data'
```
Your data matrix is now ready to use with EEGLAB.

#### Using EEGLAB

If EEGLAB isn't already running, enter "eeglab" into the Matlab command line to start the program. Import your matrix into EEGLAB using the EEGLAB GUI: File -> Import Data -> Using EEGLAB functions and plugins -> From ASCII/float file or Matlab array

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/Matlab/eeglab_dataimport.png?raw=true" width="80%">

In the pop-up window that appears, enter information about the data set. Select "Matlab variable", and enter the name of the variable where your matrix is stored. Enter the Data Sampling rate (it should be commented in at the top of the txt file - usually 250 Hz by default in the OpenBCI GUI). The other fields can be left at default, and EEGLAB will automatically fill in the information from the data set.

Channel locations are useful for plotting EEG scalp maps in 2-D or 3-D format. OpenBCI uses the standard 10-20 format for the 8 and 16 channel models, which can be found within these sfp files: [8 channel](../assets/Matlab/electrode_positions_8channel.sfp) and [16 channel](/assets/Matlab/electrode_positions_16channel.sfp). You can then import channel data by click "Browse" next to "Channel location file or info" and locating the OpenBCI sfp file you downloaded.

The data is now imported into EEGLAB and ready to use!

#### Plotting Data in EEGLAB

To double check your data is imported correctly, and to get familiar with EEGLAB's interface, try plotting your data. Select Plot -> Channel data (scroll) from the EEGLAB pop-up window.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/matlab_tutorial/EEGLAB_plot.png?raw=true" width="50%">

Your data should appear in a window like the image below:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/matlab_tutorial/EEGLAB_plot_image.png?raw=true" width="80%">

Check out the links in the Further Reading section to learn more about processing data with EEGLAB!

#### Streaming into EEGLAB
From what I can tell, EEGLAB seems to work primarily with datasets and recorded data. To use streaming in MATLAB with these toolboxes, see the [BCILAB tutorial](http://docs.openbci.com/3rd%20Party%20Software/01-Matlab#matlab-bcilab) below.



## BCILAB

From the [BCILAB wiki](http://sccn.ucsd.edu/wiki/BCILAB): "BCILAB is a MATLAB toolbox and EEGLAB plugin for the design, prototyping, testing, experimentation with, and evaluation of Brain-Computer Interfaces (BCIs), and other systems in the same computational framework."

BCILAB provides a GUI from which you can control the plugin, but batch scripting can be used for those well-versed in MATLAB programming.

#### Installation
To install BCILAB, download the [development version of BCILAB](https://github.com/sccn/BCILAB/tree/devel) and extract it to any directory that is not your EEGLAB folder. Note: I found that the non-developer version (found [here](https://sccn.ucsd.edu/wiki/BCILAB#Quick_Start_Guide)) had bugs that were fixed by using the BCILAB-devel version instead.

Open up MATLAB, and set your current MATLAB directory to the unzipped BCILAB file:
```
>> cd your/path/to/bcilab;
```
Once you're in the file, just type the command:
```
>> bcilab
```
To start running BCILAB. After some console output, you should see the text "Welcome to the BCILAB toolbox!" and then a new GUI with the BCILAB menu should appear.

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/Matlab/bcilab_menu.png?raw=true" width="80%">

#### Streaming into BCILAB with Lab Streaming Layer (LSL)

See our [Labstreaminglayer Tutorial](http://docs.openbci.com/3rd%20Party%20Software/04-LSL) for instructions on how to start a stream from the OpenBCI headset to your computer. Follow the tutorial on how to start a stream using the OpenBCI Python API.

Once a stream has been started on your computer, open BCILAB within MATLAB (>> cd your/path/to/bcilab; bcilab) and from the menu, select **Online Analysis > Read input from... > Lab streaming layer...**

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/Matlab/bcilab_lsl.png?raw=true" width="80%">

## ERPLAB

From the [ERPLAB homepage](http://erpinfo.org/erplab): "ERPLAB Toolbox is a free, open-source Matlab package for analyzing ERP data.  It is tightly integrated with EEGLAB Toolbox, extending EEGLAB’s capabilities to provide robust, industrial-strength tools for ERP processing, visualization, and analysis.  A graphical user interface makes it easy for beginners to learn, and Matlab scripting provides enormous power for intermediate and advanced users."

#### Setup
[Download](https://github.com/lucklab/erplab/releases) and extract the latest ERPLAB release to the "plugins" folder of your EEGLAB directory (if you have an old release of EEGLAB, you will also have to enter the path to this directory in MATLAB by *File > Set Path*)

Next time your launch EEGLAB, the ERPLAB menu should appear in the EEGLAB GUI:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/Matlab/erplab.png?raw=true" width="70%">

#### Analyzing EEG Data Sets
To use ERPLAB for analyzing EEG datasets, import your data set as seen in the [Loading OpenBCI Datasets in EEGLAB section](#loading-openbci-datasets-in-eeglab). After the EEG data is imported into EEGLAB, you can then use ERPLAB functions to analyze your data. [Read more on using ERPLAB on their website](http://erpinfo.org/erplab/erplab-documentation/manual_4/)

## FieldTrip
From the [FieldTrip hopmepage](http://www.fieldtriptoolbox.org/development/realtime): "The toolbox offers advanced analysis methods of MEG, EEG, and invasive electrophysiological data, such as time-frequency analysis, source reconstruction using dipoles, distributed sources and beamformers and non-parametric statistical testing."

#### Setup
[Download](http://www.fieldtriptoolbox.org/download) the latest version of FieldTrip from the download page (you will have to provide an email address and descriptiption of research). 

Add the FieldTrip directory to your MATLAB path and check out FieldTrip's [getting started guide](http://www.fieldtriptoolbox.org/getting_started).

## Further Reading

[EEGLAB Wiki](http://sccn.ucsd.edu/wiki/EEGLAB)

[BCILAB Wiki](http://sccn.ucsd.edu/wiki/BCILAB)

[ERPLAB Homepage](http://erpinfo.org/erplab)

[FieldTrip Homepage](http://www.fieldtriptoolbox.org/)


