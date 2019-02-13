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