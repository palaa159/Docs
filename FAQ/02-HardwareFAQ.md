#HARDWARE & SOFTWARE

##What do I need to get started?

To get started, all you need is an [OpenBCI Board](http://shop.openbci.com/collections/frontpage/boards) (Ganglion or Cyton), some electrodes, and a computer! Note that you do not need an Ultracortex. In fact, you can use any standard EEG electrode cap with the OpenBCI Boards.

##Can I use OpenBCI with other hardware & software?

Yes! OpenBCI is designed to be easily interfaced by other hardware and software. They OpenBCI hardware is software agnostic, meaning it works with OpenBCI-specific software, as well as any other 3rd-Party Software that has an OpenBCI driver. Check out the [Tutorials Section](http://docs.openbci.com/Tutorials/01-GettingStarted) to find guides that detail connecting OpenBCI to other tools.

##What is the difference between the [Ganglion](http://shop.openbci.com/collections/frontpage/products/pre-order-ganglion-board?variant=13461804483), the [Cyton Board](http://shop.openbci.com/collections/frontpage/products/openbci-32-bit-board-kit?variant=784651699), and the [16-Channel R&D Kit](http://shop.openbci.com/collections/frontpage/products/openbci-16-channel-r-d-kit?variant=785215991)?

The Cyton Board is an 8 channel biosensing amplifier that can measure ECG, EMG, and EEG. It connects to your computer wirelessly with an included USB Dongle. Data is sampled at 250Hz.
The 16-Channel R&D Kit is the same as the Cyton Board, but it also includes an expansion module to increase the channel count to 16. Data is sampled at 250Hz.
The Ganglion is a 4 channel biosensing amplifier that can measure ECG, EMG, and EEG. It connects to your computer via BLE. Data is sampled at 200Hz.
The [WiFi Shield](https://shop.openbci.com/collections/frontpage/products/wifi-shield?variant=44534009550) can be used for higher sample rates.

##How do I choose between 4, 8, or 16 channels for my research?

With additional channels, you have additional spatial resolution. The Ganglion (the 4-channel board) is great for low-cost research and education. The Cyton (8-16 channels) provides additional spatial resolution, enabling more diverse types of research requiring higher channel counts.

##What is a [WiFi Shield](https://shop.openbci.com/collections/frontpage/products/wifi-shield?variant=44534009550)

The WiFi Shield attaches to the top of your Cyton, 16-Channel R&D kit or Ganglion. The WiFi Shield is an easy way to get a higher sample rates from your Cyton or Ganglion. The WiFi Shield can be controlled through HTTP requests and can send JSON objects with data in nano volts. The WiFi Shield does not require the Cyton USB dongle to be used. The WiFi Shield does not require the Ganglion BLE to be used.

##How do our products go together?

The Cyton and Ganglion are "Carrier" boards. The Daisy, aka the Cyton expansion module to increase the channel count to 16, and the WiFi Shield are "Shields". Shields are only useful when mounted on a Carrier board.

### Cyton

#### Using out-of-the-box Bluetooth Dongle

Cyton board (8-Channels) will stream at 250Hz.
Cyton board with Daisy (16-Channels) will stream at 125Hz.

#### Using [WiFi Shield](https://shop.openbci.com/collections/frontpage/products/wifi-shield?variant=44534009550)

Cyton board with WiFi Shield (8-Channels) will stream at 250Hz, 500Hz, 1000Hz, 2000Hz, 4000Hz, 8000Hz and 16000Hz
Cyton board with WiFi Shield and Daisy (16-Channels) will stream at at 250Hz, 500Hz, 1000Hz, 2000Hz, 4000Hz, and 8000Hz

### Ganglion

#### Using onboard Bluetooth Low Energy

Ganglion board (4-Channels) will stream at 200Hz.

#### Using [WiFi Shield](https://shop.openbci.com/collections/frontpage/products/wifi-shield?variant=44534009550)

Ganglion board (4-Channels) will stream at 200Hz, 400Hz, 800Hz, 1600Hz, 3200Hz, 6400Hz, and 12800Hz

##Where do I download the OpenBCI software?

You can go to our [downloads page](http://openbci.com/donation)!
