# BrainBay

## Installation

**Windows**: Follow [OBCI on Windows](http://docs.openbci.com/tutorials/10-OpenBCI_on_Windows) tutorial to properly connect your OBCI board on Windows. Then, continue this tutorial.

**OS X**: See the [FTDI OS X fix](http://docs.openbci.com/Tutorials/10-Mac_FTDI_Driver_Fix) first, then follow these instructions.

**Linux**: Neuromore does not yet support linux platforms but plans to in the near future.

### I. Neuromore Software
Download the latest neuromore software from their [website](http://www.neuromore.com/). Their main software is the neuromore Studio which they plan to keep improving!

### II. Connect the Board

**Windows**: Connect your OBCI board and make sure it is recognized as a COM port and it's latency is set to 1 ms. To troubleshoot, read [this](http://docs.openbci.com/tutorials/10-OpenBCI_on_Windows).

**OS X**: Make sure your board is connected and visible as a device. To check you can type `ls /dev/tty.*` on your terminal. An example connected OBCI board should like like this:
