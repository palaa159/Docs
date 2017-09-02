# OpenBCI Wifi Shield

**The Wifi shield and these docs are still in beta, if you see a typo [please open an issue](https://github.com/OpenBCI/Docs/issues/new).**

The OpenBCI Wifi Shield seeks to offer a plug and play Wifi solution for the OpenBCI Cyton and Ganglion.

One of the coolest parts is the restful fully qualified web server sitting on your OpenBCI board!

## Ganglion

### Prerequisites

1. OpenBCI Ganglion with at least [2.x.x firmware](https://github.com/OpenBCI/OpenBCI_Ganglion_Library/blob/development/OpenBCI_Ganglion_Library/examples/WifiGanglion/DefaultGanglion.ino)
2. Wifi shield with [current firmware](https://github.com/OpenBCI/OpenBCI_WIFI/blob/master/examples/ESP8266HuzzahSSDP/ESP8266HuzzahSSDP.ino)
3. Wireless local area network (internet)
4. Two batteries to power the whole system

## Cyton

### Prerequisites

1. OpenBCI Cyton with at least [3.x.x firmware](https://github.com/OpenBCI/OpenBCI_32bit_Library/tree/dev-3.0.0)
2. Wifi shield with [current firmware](https://github.com/OpenBCI/OpenBCI_WIFI/blob/master/examples/ESP8266HuzzahSSDP/ESP8266HuzzahSSDP.ino)
3. Wireless local area network (internet)
4. Battery to power the whole system

## Connecting to the Wifi Shield

Be sure that your WiFi Shield is on your local network. Please continue reading if your OpenBCI Wifi Shield is on the same wifi network as your computer.

The steps for connecting to the Wifi Shield and streaming over TCP:

1. Get Wifi Shield On Your Wireless Network
2. Find IP Address of Wifi Shield
3. Open a TCP Socket on Host Computer
4. Send `POST` `/tcp` http request with open socket IP/Port number, can include options for output format (i.e. JSON or RAW output), along with latency.
5. Send `POST` `/command` http requests for control or for just streaming use GET `/stream/start` or GET `/stream/stop`
6. Send `POST` `/latency` http requests for tuning, if packets are dropped because older router or poor connection.

The steps for connecting to the Wifi Shield and streaming over MQTT:

1. Get Wifi Shield On Your Wireless Network
2. Find IP Address of Wifi Shield
3. Open a TCP Socket on Host Computer
4. Send `POST` `/mqtt` http request with broker address with optional username and password
5. Send `POST` `/command` http requests for control

## Get IP Address of Wifi Shield

Use [Simple Service Discovery Protocol](https://en.wikipedia.org/wiki/Simple_Service_Discovery_Protocol) (SSDP) to find the device on your local network. Use a tool in your favorite language [Python](http://brisa.garage.maemo.org/doc/html/upnp/ssdp.html) | [Node.js](https://github.com/diversario/node-ssdp) | [C](https://developer.gnome.org/gssdp/stable/).

The [Node.js SDK](https://github.com/aj-ptw/OpenBCI_NodeJS/blob/wifi/examples/getStreamingWifi/getStreamingWifi.js) which will implement SSDP for you.

Use a graphical user interface [Mac - Lan Scan](https://itunes.apple.com/us/app/lanscan/id472226235?mt=12)

We are still hashing out the best ways to discover the Wifi shield on the networks (home vs. enterprise and beyond) so [please contribute ides if you have any on this github issue](https://github.com/OpenBCI/OpenBCI_WIFI/issues/8) and we can add it in! [Wifi Direct Feature Request (researcher frequently requested feature)](https://github.com/OpenBCI/OpenBCI_WIFI/issues/9)

## Open a TCP Socket on Host Computer

In order to get low latency high-reliability wireless data transmission we will open a TCP socket on your host Computer. The Wifi Shield will stream data to this socket. **IMPORTANT** The data comes over this socket raw and is defined in the docs for [Binary Data Format](http://docs.openbci.com/Hardware/03-Cyton_Data_Format#cyton-data-format-binary-format).

If you want the data in another format, please comment on [this issue](https://github.com/OpenBCI/OpenBCI_WIFI/issues/11), thinking protocols like `JSON`.

## OpenBCI HTTP Rest Server

### Send `/tcp` http request for TCP configuration

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

### Send `/mqtt` http request for MQTT configuration

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

### Send `/command` http requests for control

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server. To change the sample rate of the Cyton, please use the `~` command as defined in the Cyton SDK docs.

### Send `/latency` http requests for tuning

Refer to [http server description](https://app.swaggerhub.com/apis/pushtheworld/openbci-wifi-server/1.3.0) swagger.io page as the single source of truth in regards to the OpenBCI Wifi Server.

The time in micro seconds (us) between packet sends. The higher the OpenBCI sample rate, the higher the latency needed. Default is 1000us, minimum stable is 50us. For upper limit sample rates such as 4kHz/8kHz/16kHz, latency around 20ms seems to really stabilize the system.  

## Parsing Data from Wifi Shield

Data can be sent from the Wifi shield in two different formats: `raw` and `JSON`.

### `raw` Byte Stream Format
The first byte to send is the control byte. For streaming data, that goes on the TCP socket, send `0xCX` (where `X` is `0-F` in hex) as the control byte. In the `OpenBCI_32bit_Library` code base:

~~~
/*  
 * @description Writes channel data and axisData array to serial port in
 *  the correct stream packet format.
 */
void OpenBCI_32bit_Library::sendChannelDataWifi(void)  {

    wifiStoreByte(OPENBCI_EOP_STND_ACCEL); // 0xC0 1 byte

    wifiStoreByte(sampleCounter); // 1 byte

    ADS_writeChannelDataWifi(); // 24 bytes

    accelWriteAxisDataWifi(); // 6 bytes

    wifiFlushBuffer(); // Flushes the buffer to the SPISlave ESP8266 device!

    sampleCounter++;

}
~~~  

This code writes 32 bytes of data in the correct format and therefore as soon as it arrives at the Wifi shield. The Wifi shield will convert the 32 byte packet to the standard 33 byte [binary format](http://docs.openbci.com/Hardware/03-Cyton_Data_Format#cyton-data-format-binary-format) by moving the control byte `0xCn`, where `n` is `0-F` (hex), to the stop position and add add `0xA0` to the start position. This allows for a seamless integration with the tried and tested parsing systems already built for the Cyton.
**Important** if you want to only send `20` bytes of data per packet, you still must send this `32` bytes with the proper start and stop bytes.
