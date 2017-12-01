# Installing Windows 7 VM in VirtualBox

Some of the software compatible with OpenBCI products requires a Windows operating system. If you have a non-windows computer, you can still use this software through a Wondows virtual machine on VirtualBox.

![Ova Settings](../assets/images/ova-set.jpg)

1. Download [VirtualBox](https://www.virtualbox.org/wiki/Downloads). 
1. Go to <http://dev.modern.ie/tools/vms/> and download a Windows 7 virtual machine (I used IE8) image for your appropriate host on the "Choose your OS" tab. (The OS that your computer runs natively). Choosing Virtual Box as the platform.
1. Extract and double click on the .OVA file resulting from the extraction. This should start Virtual Box and set up your VM's configurations. 
1. Some EEG processing software uses a lot of RAM (OpenViBE aquisition server for example). In fact, some will take up one entire core, if they can. Because of this, I would advise that you configure your VM to have multiple cores and as much RAM as you deem reasonable. 
1. Import the VM, go through all the configs and start it. 
1. For more detailed instructions/tutorials and troubleshooting see the [Windows Manual](http://modernievirt.blob.core.windows.net/vhd/release_notes_license_terms_1_5_15.pdf). (If you selected a different distribution other than Win 7, see the respective manual in the Windows page.)
1. Follow the [OBCI on Windows](http://docs.openbci.com/Tutorials/11-OpenBCI_on_Windows) tutorial to properly connect your OBCI board on Windows.

NOTE: Make sure that Guest Additions are installed correctly on your VM. With the image used, they should be automatically installed.

#### Sharing files with VirtualBox

If you have files on your regular OS that you'd like to access through VirtualBox, follow these steps to create a shared folder:

1. Start VirtualBox. When the "Oracle VM VirtualBox Manager" window appears, select your virtual machine (so that it's highlighted in blue). Make sure your virtual machine is in the "powered off" mode, and not the "saved state" mode.
2. Click Settings and then the "Shared Folders" tab.
3. Click the icon for "Add new shared folder", and select the file path to a folder you'd like to share.
4. Start your virtual machine.
5. Open a file explorer window and navigate to the "Network" location.
6. You may need to select "Turn on netowrk and file sharing" as an administrator. Then, a computer called "VBOXSVR" will appear.
7. Double click on that computer and you should see your shared folder.

You're all set! For more information, look at the [VirtualBox documentation.](https://www.virtualbox.org/wiki/Documentation)

#### Using OpenBCI Hardware within VirtualBox

While using 3rd party software, you might want to stream data from your OpenBCI board directly to a program on your virtual machine. Here's how to livestream from your OpenBCI board within your VM.

**OpenBCI Cyton Board**

1. Make sure you're comfortable using your Cyton board and Dongle with your host computer and the OpenBCI GUI. To do so, check out our [Cyton Getting Started Guide](http://docs.openbci.com/Tutorials/01-Cyton_Getting%20Started_Guide).
1. Plug in your Dongle and turn on your Cyton board. Both should display a blue light.
1. Start VirtualBox. When the "Oracle VM VirtualBox Manager" window appears, select your virtual machine (so that it's highlighted in blue). Make sure your virtual machine is in the "powered off" mode, and not the "saved state" mode.
1. Click Settings and then the Ports tab.
1. Switch to the USB tab.
1. Check "Enable USB Controller" and select "USB 2.0 (EHCL) Controller".
1. Under USB Device Filters, click the "Add USB" icon with the green plus sign. The FTDI Driver used by the OpenBCI Dongle should appear in a drop down menu. Select it. It should now appear under "USB Device Filters".
1. Click "OK" to save these settings.


