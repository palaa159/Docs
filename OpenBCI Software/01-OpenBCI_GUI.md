# The OpenBCI GUI

[Suggest changes to this doc](https://github.com/OpenBCI/Docs/edit/master/OpenBCI%20Software/01-OpenBCI_GUI.md)

![image](../assets/images/GUI-V2-SCREENSHOT.JPG)

The OpenBCI GUI is OpenBCI's default software tool for visualizing, recording, and streaming data from the OpenBCI Boards. It can be launched as a standalone application or launched from Processing (a Java-based programming language). In this guide, we will walk you through how to go about doing it both ways.

## Hardware/Driver Setup for OpenBCI_GUI and OpenBCIHub

### Cyton on macOS/Windows/Linux

![FTDI Install](../assets/images/FTDI.png)

The FTDI chip on your OpenBCI Dongle requires you to install the FTDI drivers on your machine. You may already have these installed, if you've worked with Arduino or other USB hardware accessories. You can download the latest FTDI drivers for your operating system [here](http://www.ftdichip.com/Drivers/VCP.htm). **Note:** if you jumped ahead and are already running your GUI, you may need to restart your GUI for this to take effect.

![Unidentified Developer MAC](../assets/images/securityAndPrivacy.png)

**If using a MAC:** When you try to install the FTDI driver, your computer may tell you that it is unable to install the application because it is from an unidentified developer. In this case, go to System Preference > Security & Privacy and switch your settings to "Allow Applications Downloaded from: Anywhere," as seen in the screenshot to the right. You will most likely have to unlock the lock (and type in your root password) at the bottom of the Security & Privacy window before you can make this change.

### Ganglion on Windows

The OpenBCI Ganglion uses Bluetooth LE (aka Bluetooth Smart, Bluetooth 4.0) and in order to use the Ganglion with Windows, you need a small USB Dongle. We have verified CSR 4.0 Dongles in our [store](http://shop.openbci.com/products/csr-4-0-bluetooth-dongle), and you can get them from various online vendors.  

**IMPORTANT:** The BLE Dongle *must* be a verified CSR 4.0 Dongle!

![CSR Dongle to USB port](../assets/images/ganglion_win_1_plugCSRDongleIn.JPG)

First plug in your CSR 4.0 BLE Dongle.   

![Searching Zadig in Google](../assets/images/ganglion_win_2_searchZadigInGoogle.PNG)

Then, go to the [Zadig tool website](http://zadig.akeo.ie) to get the driver.

![Windows Vista or Later](../assets/images/ganglion_win_3_downloadZadigForWindowsVistaOrLater.PNG)

Download Zadig for Windows Vista or Later

![Open Zadig Installer](../assets/images/ganglion_win_4_openZadigExe.PNG)

Open the Zadig tool once it's done downloading. Acknowledge the message to allow the program to make changes to your OS.

![No to updates](../assets/images/ganglion_win_5_noToUpdates.PNG)

Select *No To Updates* when prompted.

![Select Options](../assets/images/ganglion_win_6_selectOptions.PNG)

On the top bar select *Options*.

![List all devices](../assets/images/ganglion_win_7_selectListAllDevices.PNG)

Then select *List All Devices*.

![Select CSR](../assets/images/ganglion_win_8_selectCSRFromDropDown.PNG)

Select CSR from the dropdown.

![Replace Driver](../assets/images/ganglion_win_9_selectReplaceDriver.PNG)

Then press *Replace Driver*.

![Driver Installed Success](../assets/images/ganglion_win_10_driverInstalledMessage.PNG)

You should then see a progress bar followed by a success message.

![Driver Installed Success](../assets/images/ganglion_win_11_bothSayWinUSB.PNG)

Note that both drop-downs both say *WinUSB*.  

**We are in the process of updating this guide to include Windows 7 users. it *is* possible to use the Ganglion and CSR 4.0 BLE Dongle on Windows 7. For now, please visit this [forum post](http://openbci.com/forum/index.php?p=/discussion/918/ganglion-and-windows-7), which outlines the procedure.**

### Ganglion on macOS/Linux

Turn on your computer's Bluetooth if not already.

![Bluetooth On!](../assets/images/ganglion_BLE-ON.png)  

Do not use a dongle with macOS. Dongles such as the `CSR` dongles are only needed for Windows and sometimes linux.

### Wifi on macOS/Windows/Linux

There are no prerequisites for running the WiFi Shield with Cyton or Ganglion on macOS/Windows/Linux, move on to the installation section below.

## Installing the OpenBCI GUI as a "Standalone" Application

### Download the Appropriate Application For Your OS

The fastest way is to download the standalone .exe/.app for your machine and operating system. To do this, head to the [Downloads](http://openbci.com/donation) page of the OpenBCI website, and click the download link that correlates to your OS and machine.

![image](../assets/images/Downloads.JPG)

### Install OpenBCI_GUI On macOS

Drag and drop the `OpenBCI_GUI` application to you `Applications` folder.

![Drag and drop application](../assets/images/gui_drag_and_drop.png)

### Install OpenBCI_GUI On Windows

First unzip the windows application you downloaded from the [downloads](http://openbci.com/donation) section of the OpenBCI Website.

![unzipped gui on windows](../assets/images/gui_windows_unzipped.PNG)

Please place the OpenBCIHub in your Program Files directory such that the structure looks like:
"\Program Files\OpenBCIHub\OpenBCIHub.exe"

![drag and drop](../assets/images/gui_windows_drag_and_drop_hub.png)

Enter the new OpenBCIHub folder and right click on the executable -> properties -> compatibility -> tick "Run this program as an administrator".

![set to run as admin always](../assets/images/gui_windows_properties_run_as_admin_hub.PNG)

Create a short cut on your desktop by right click on the executable -> Send to -> Desktop

Then double click the executable to run it for the first time. You must check both check boxes when prompted.

![accept networking](../assets/images/gui_windows_accept_networking.PNG)

We recommend you leave the Hub running, even when not using the OpenBCI_GUI, the hub's impact on performance when not in use is minimal.

![low impact on CPU](../assets/images/gui_windows_hub_low_impact.PNG)

Verify the hub is running in your windows tool tray

![clicking the icon](../assets/images/gui_windows_openbci_hub_running.PNG)

To quit the hub, click the tray cat icon, and then press the quit button.

![quit the hub](../assets/images/gui_windows_openbci_hub_quit.png)

Please place the GUI in your Program Files directory such that the structure looks like:
"\Program Files\OpenBCI_GUI\OpenBCI_GUI.exe"

![drag and drop](../assets/images/gui_windows_drag_and_drop_gui.png)

If you already have a GUI installed, you may select to replace all the files.

![replace all files popup](../assets/images/gui_windows_replace_warning.PNG)

Replacing the files may bring up another pop up that you need to accept for altering files within the Program Files folder.

![replace need admin](../assets/images/gui_windows_replace_admin_needed.PNG)

Lastly, right click on the executable -> properties -> compatibility -> tick "Run this program as an administrator".

![set to run as admin always](../assets/images/gui_windows_properties_run_as_admin.PNG)

### Install OpenBCI_GUI on Linux

Unzip the downloaded application.

## Running the OpenBCI_GUI

**Important Notes:**

 * In some cases, there may be issues with the way your machine handles the BLE application that enables communication with the Ganglion Board.
 * If you run into additional issues, please visit the [OpenBCI_GUI Section](http://openbci.com/index.php/forum/#/categories/openbci_gui) of our Forum

### Running on macOS

Navigate to your `Applications` folder and double click the `OpenBCI_GUI` You may see a message pop up asking you if you're sure you want to open it. Click Open and the app will launch.

![allow GUI to run](../assets/images/ganglion_permissions.png)

### Running on Windows

Double click the `OpenBCIHub` if you set the properties to always start as administrator, or right click on the executable and run as administrator.

From testing, it's incredibly important to run as adminstrator for Cyton over Serial or Ganglion over BLE. You don't need to run the OpenBCIHub as an administrator for WiFi.

We recommend you leave the Hub running, even when not using the OpenBCI_GUI, so you don't forget to start the hub before running the OpenBCI_GUI. The hub has a very low memory usage and zero CPU impact when not streaming data.

You can verify the hub is running in your windows tool tray

![clicking the icon](../assets/images/gui_windows_openbci_hub_running.PNG)

Now with the Hub running, double click the `OpenBCI_GUI` if you set the properties to always start as administrator, or right click on the executable and run as administrator.

### Running on Linux

Open a terminal application and navigate to the directory (with `cd`) of the unzipped application.

Then launch the Application from terminal with the command:

```
$ sudo ./OpenBCI_GUI
```

This will launch the OpenBCI_GUI and OpenBCIHub.

## Running the OpenBCI GUI From The Processing IDE

The OpenBCI GUI was built using [Processing](https://processing.org/), a popular, Java-based creative coding framework. If you are interested in adding features or modifying the existing code, it is really easy to do so, if you are familiar with Java. If you are not, don't fret! Processing is one of the easiest software packages to pick up as a beginner coder.

The things you will need to run the OpenBCI GUI in Processing are:  

 * [Processing App](https://processing.org/download/?processing)
 * [OpenBCI GUI Sketch](https://github.com/OpenBCI/OpenBCI_GUI)
 * [OpenBCI Electron HUB](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron/releases)

First, go to processing.org and download the latest version of Processing.

Go ahead and move it to your `Applications` folder, and launch the application. If this is the first time that you are running Processing, it will create what it calls it's `Sketch` folder. The default location for the `Sketch` folder is in your Documents folder:  

 On a Mac `Users/<user-name>/Documents/Processing`  
 On a Windows `C:\Users\Username\Documents\Processing`

This is the location that we will move the OpenBCI GUI files that we'll download next.  

![GUI repo](../assets/images/ganglion_GUI-repo.png)

The OpenBCI GUI code repository is located on github [here](https://github.com/OpenBCI/OpenBCI_GUI). click on the `Clone or download` button in green on the right, and select `Download ZIP`. If you are a advanced github user, go ahead and clone it, or fork it if you like.  

After the download completes and the file extracts itself, you will see the folder called `OpenBCI_GUI-master`. Change the name of this file to `OpenBCI_GUI`. If you don't change it, it won't work! Now move the folder `OpenBCI_GUI` and it's entire contents to your Sketch folder:

On a Mac `Users/<user-name>/Documents/Processing`  
On a Windows `C:\Users\Username\Documents\Processing`

![libraries folder](../assets/images/ganglion_libraries-folder.png)

Inside the `OpenBCI_GUI` folder, there is a folder called `libraries`. Theses are the 3rd party libraries that the OpenBCI GUI uses to work it's magic. You need to move all of these folders into:

On a Mac `Users/<user-name>/Documents/Processing/libraries`  
On a Windows `C:\Users\Username\Documents\Processing\libraries`

folder. If there is no folder called `libraries` in that location, go ahead and make one. Once you have done that, quit out of Processing. There's one more big step, and it means going back to the OpenBCI github repository.

### Install OpenBCI Hub on Mac/Linux

![OBCI Electron github](../assets/images/ganglion_electron-github.png)   

There is a piece of software which is necessary to make the connection between the GUI and your computer's Bluetooth hardware.
We call this the OpenBCI Electron Hub. Go to our github repository for the [Hub](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron/releases/latest), and click on the link for your Operating System.  

![electron hub download](../assets/images/ganglion_hub-download.png)

After it downloads and unpacks itself, your Downloads folder will look like this. the `Ganglion Hub app` needs to be inside your sketch folder, in a specific place.  

![Hub Home](../assets/images/ganglion_hub-home.png)

Move the `Ganglion Hubb app` from your Downloads folder to:

`Users/<user-name>/Documents/Processing/OpenBCI_GUI/OpenBCI_GUI/data`

### Install OpenBCI Hub on Windows

The fastest way is to download the standalone .exe/.app for your machine and operating system. To do this, head to the [Downloads](http://openbci.com/donation) page of the OpenBCI website, and click the download link that correlates to your OS and machine.

![unzipped gui on windows](../assets/images/gui_windows_unzipped.PNG)

Please place the OpenBCIHub in your Program Files directory such that the structure looks like:
"\Program Files\OpenBCIHub\OpenBCIHub.exe"

![drag and drop](../assets/images/gui_windows_drag_and_drop_hub.png)

Enter the new OpenBCIHub folder and right click on the executable -> properties -> compatibility -> tick "Run this program as an administrator".

![set to run as admin always](../assets/images/gui_windows_properties_run_as_admin_hub.PNG)

Create a short cut on your desktop by right click on the executable -> Send to -> Desktop

Then double click the executable to run it for the first time. You must check both check boxes when prompted.

![accept networking](../assets/images/gui_windows_accept_networking.PNG)

To quit the hub, click the tray cat icon, and then press the quit button.

![quit the hub](../assets/images/gui_windows_openbci_hub_quit.png)

Now simply run the hub before starting from processing.   

### Open The OpenBCI GUI Project in Processing & Launch It!

![processing startup](../assets/images/ganglion_processing-launch.png)

When you get Processing running again, you will see a window open up. This is the Processing IDE (Integrated Development Environment).

![Select Sketchbook](../assets/images/ganglion_file-sketchbook.png)
![Select OpenBCI GUI from Sketchbook](../assets/images/ganglion_sketchbook-window.png)

Select `File > Sketchbook` and you will open a window where you should see the option to select `OpenBCI GUI`. When you get that far, select `OpenBCI GUI` and the Processing will open up yet another window, that contains all the code to successfully run the OpenBCI GUI.  

![GUI code window](../assets/images/ganglion_GUI-code-window.png)

If you don't know anything about coding, don't edit these files. If you like to dig in to the meat of what makes things work, by all means. have at it. You are looking at the program code that makes the OpenBCI GUI work it's magic. Now, it's time to run it!

![Processing RUN](../assets/images/ganglion_processing-RUN.png)

Press the `play` button on the upper left of the IDE, and the sketch will try to launch in all it's glory. If this is your first time running the sketch, you will get a message from the Mac OS that will ask you if you will allow permission for an unsigned app to run. The app in question is the Electron Hub. If you've enabled apps to run from Anywhere, you can just give permission to run the app. However, it is likely that the GUI will not function, because timing is everything. You will need to quit the sketch (press `command+q` or click the `x` button on the upper left of the GUI). Then, relaunch the sketch by pressing the `play` button as above. This time you won't get the alert from the Mac OS, and the GUI will launch in all it's glory!  

If you are encountering issues launching the GUI at this point, please head to the [OpenBCI_GUI section](http://openbci.com/index.php/forum/#/categories/openbci_gui) of our Forum and look for help or post a question.

### Using the OpenBCI GUI

![use gui](../assets/images/USE-GUI.JPG)

Check out this [Youtube video](https://www.youtube.com/watch?v=agV1B2l-QLw) on how to use the OpenBCI GUI. We are in the process of updating it to match the GUI V3! Coming Soon.

## Customize Your Layout

The OpenBCI GUI displays up to six customizable windows in twelve layouts! You can choose what each window displays by clicking the dropdown menu at the upper left of each window. In the screengrab below, my GUI is showing Time Series, FFT Plot, and Accelerometer. Here's a tip that some users have inquired about: display the impedance of individual channels by toggling the small Ohm icon to the right of each color coded channel number. See below:

<img src="https://github.com/OpenBCI/Docs/blob/master/assets/images/GUI_Impedance.png?raw=true" width="100%">

## Decrease Setup Time by Saving/Loading Settings
Starting with GUI V3, you can save and load a snapshot of nearly every setting in the GUI (ex. Layout, Time Series Channel Settings, Networking Settings, etc.) by using a dropdown menu (pictured below) or keyboard shortcuts!

![Config Button](../assets/images/GUI_Config_Button_Screenshot.png)

Start the system first. Then, arrange the GUI to suit your needs and __click "Config"-->"Save Settings"__. You will see a message saying "Settings Saved!" 

Afterwards, or the next time you open the GUI, just __click "Config"-->"Load Settings"__. If the settings are incompatible (ex. loading 16 channels while using 8), the GUI will show an error at the bottom . If all is well, the GUI will display "Settings Loaded!" as the GUI snaps directly to your desired settings! When in Live Mode, please allow 1-2 seconds to successfully apply settings to Cyton and Ganglion boards.

Alternatively, you can Save and Load with capital 'S' and capital 'L' on your keyboard! 

## Other Keyboard Shortcuts
__Use the spacebar to start or stop the data stream!__ You can use _lowercase 'b' to set "Bias Don't Include"_ on all channels, or _uppercase 'B' to set "Bias Include"_ on all channels. 

Using an _English keyboard_, you can deactivate channels 1-16 using: 
1,2,3,4,5,6,7,8
q,w,e,r,t,y,u,i

Similarly, activate channels 1-16 using:
!, @, #, $, %, ^, &, *
Q,W,E,R,T,Y,U,I
