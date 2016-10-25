# Upload Code to OpenBCI Board

## Overview
The OpenBCI 32bit boards were updated with new firmware across all three main microcontrollers, the Pic 32 ([`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino)) and both RFduinos on the Dongle ([`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino)) and the Board ([`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino)). This tutorial does not explain how to program the firmware using the OpenBCI Dongle and `PC`; you will want to refer to the tutorials [Upload Code to OpenBCI Board](https://github.com/OpenBCI/Docs/blob/master/tutorials/02-Upload_Code_to_OpenBCI_Board.md) and [Upload Code to OpenBCI Dongle](https://github.com/OpenBCI/Docs/blob/master/tutorials/03-Upload_Code_to_OpenBCI_Dongle.md). If you have spent a lot of time writing custom Arduino code to run on the OpenBCI, then you will find this tutorial helpful in upgrading to get the new stability and features of the 2.0.0 firmware.

## Sending data packets from the Pic32 to the PC
At 250Hz, we are at the upper limit of the physical hardware. The [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) RFduino must send data packets as soon as it get's them from the [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) because of the slow serial baud rate between [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) and [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) (`115200`, a faster baud rate messes up the radio on the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino)). On the other hand, over the air programming must be able to combine multiple radio packets together into one page and write at one time, therefore, over the air programming must wait to see if it received all data over the serial port before sending. These two requirements led to the original firmware being stateful, where the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) and [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) would be in either `streaming` or `not streaming` mode. This led to problems and could result in the `PC` not being able to contact the `Board` because the radios were stuck in streaming mode and the reset button on the `Board` is not tied to the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) so one would have to power cycle the entire `Board`.

### An Example
Let's say you want to send custom data from the `Board` to the `PC`. In order to do that simply wrap the data with the correct start byte, `0x41`, and stop byte, `0xCX` (where `X` is `0-F` in hex). In the `OpenBCI_32bit_Library` code base:
```
/**
 * @description Writes channel data and `axisData` array to serial port in
 *  the correct stream packet format.
 *
 *  Adds stop byte `OPENBCI_EOP_STND_ACCEL`. See `OpenBCI_32bit_Library_Definitions.h`
 */
void OpenBCI_32bit_Library::sendChannelDataWithAccel(void)  {

    Serial0.write('A'); // 0x41 1 byte

    Serial0.write(sampleCounter); // 1 byte

    ADS_writeChannelData(); // 24 bytes

    accelWriteAxisData(); // 6 bytes

    Serial0.write(OPENBCI_EOP_STND_ACCEL); // 0xC0 1 byte

    sampleCounter++;

}
```
This code writes 33 bytes of data from the [`Pic32`](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/DefaultBoard/DefaultBoard.ino) to the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) in the correct format and therefore as soon as it arrives at the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) will be sent to the [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) and to the `PC`. New to firmware version 2 is the ability to have different stop bytes, in the original firmware, one could only send stop bytes of `0xC0` however now, we can send `0xCX` where `X` is `0-F` hex. **Important** if you want to only send `20` bytes of data per packet, you still must send this `33` bytes with the proper start and stop bytes. Sending data too fast will result in a buffer overflow on the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) and cause the system to restart and send an error message to the [`Host`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioHost32bit/RadioHost32bit.ino) and `PC`.

### Sending one byte of data every 10ms or 100Hz
Here is an example taken from the file called `BoardWithCustomData.ino` from the `examples` folder in the `OpenBCI_32bit_Library` repo.

```
void sendLEDStatus() {
  // Must have header byte
  Serial0.write('A'); // 0x41 1 byte
  // Write the LED state
  Serial0.write(LEDState); // 1 byte
  // Fill the rest with fake data
  for (int i = 0; i < 30; i++) {
    Serial0.write(0x00);
  }
  // Send a stop byte with an `B` or `1011` in the last nibble to indicate a
  //  different packet type.
  Serial0.write(0xCB); // 1 byte
}
```
As you can see above, we only really want to send 1 byte, but if we want to do it fast, at this 100Hz rate, we must wrap it in the start byte and stop byte to tell the [`Device`](https://github.com/OpenBCI/OpenBCI_Radios/blob/master/examples/RadioDevice32bit/RadioDevice32bit.ino) RFduino to send the packet as soon as it get's the stop byte.

## Adopting the new Pic32 code paradigm
We drastically reduced the complexity of the `.ino` files in order to make custom device programming more approachable for new programmers but also add a suite of features to give great power to great programmers. We have created an environment to drive contribution to the main project in the form of examples. If you want to contribute code the main library for others to use, now you can simple to a pull request. Joel was able to adapt his [pulse sensor code](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithPulseSensor/BoardWithPulseSensor.ino) to the new firmware in about 20 minutes! Now anyone who downloads the firmware, will get the pulse sensor code versus having to dig through all the `OpenBCI` repos to find an example of [how to use a pulse sensor](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithPulseSensor/BoardWithPulseSensor.ino), [have external triggers](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWith2ButtonExternalTriggers/BoardWith2ButtonExternalTriggers.ino), [read an analog input](https://github.com/OpenBCI/OpenBCI_32bit_Library/blob/master/examples/BoardWithAnalogSensor/BoardWithAnalogSensor.ino), etc...

Please dig through the [`examples`](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/master/examples) folder on the [`OpenBCI_32bit_Library`](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/master) for a deep dive into all the possibilities with the new code. Remember if you have new code you want to share, please do!! [Make a pull request](https://help.github.com/articles/creating-a-pull-request/)!
