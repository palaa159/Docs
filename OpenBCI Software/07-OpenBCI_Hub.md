# OpenBCI Hub

Middleware Software used to communicate with OpenBCI boards through TCP/IP command protocol. This Doc covers the OpenBCI Hub for Cyton, Ganglion, and WiFi Shield.

## Version
Version `v2.0.0` released September 2018

Version `v1.0.0` released January 3rd, 2017.

## OpenBCI Electron Hub Overview
The OpenBCI Electron Hub (or just "Hub") is a TCP/IP server that listens for clients on port `10996` on `localhost` aka `127.0.0.1`. Broadcast/multicast is never used for transmitting information to clients. Outgoing data is only transmitted to the requesting client. We use [semantic versioning](http://www.semver.org) the protocol is always listed first and foremost in all documentation. Please follow the rules of [semantic versioning](http://www.semver.org) to avoid breaking changes.

The hub is designed for either two use cases:

1. An owning application, such as OpenBCI's processing app, starts and stops the Hub.
2. The Hub runs continuously and 3rd party applications can simply connect as clients, use OpenBCI boards, disconnect and go on their way without closing the Hub.

A unique port, `10996`, is critical because applications must be able to hit a known port number on a local machine. This Specification shall [be available here](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron/blob/master/ganglion-api-spec.yaml) in the [source code of the Hub](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron).

## Hub Command Protocol Overview

As of v2.0.0, the Hub uses JSON to pass messages send and receive messages over TCP. Each JSON string should end in a `\n`. Parse for `\n` and then strip the beginning of the string down to the character before `\n` and use your languages built in JSON parser. The contents of the buffer can be now be considered a Message. The buffer can be flushed and the Message can be processed. There will always be a 'command' key which will aid in parsing the rest of message. The rest of the Message will then be translated based on the protocol for that command described in the Specification below. All commands sent to the client will be replied to asynchronously.

### Example:
If a client sends `{"type":"scan", "action":"start"}\n` to the Hub on `127.0.0.1:10996`, the Hub will respond with either `{"type":"scan", "action":"start", "code":200}\n` if the scan was started or an error message if unable to start such as `{"type":"scan","code":412,"message":"unable to start scan"}\n`.

## Command Set
Commands are sent from the client to the Hub. Each command gets an asynchronous response with a meaningful code. When able, errors are sent with string error messages.

### Accelerometer

**type: `accelerometer`**

Stop or start accelerometer.

#### `action` - `start`

Description:
Start accelerometer. Only useful for Ganglion.

Availability:
As of `v1.0.0`

Example:
`{"type":"accelerometer", "action": "start"}`

Response: on success
`{"type":"accelerometer", "action": "start", "code": 200}`

Response: on failure
`{"type":"accelerometer", "action": "start", "code": 416, "message": "string error message"}`

#### `action` - `stop`

Description:
Stop accelerometer. Only useful for Ganglion.

Availability:
As of `v1.0.0`

Example:
`{"type":"accelerometer", "action": "stop"}`

Response: on success
`{"type":"accelerometer", "action": "stop", "code": 200}`

Response: on failure
`{"type":"accelerometer", "action": "stop", "code": 417, "message": "string error message"}`


### Board Type

**type: `boardType`**

Attempts to set the board type to user requested board type, such as when a user requests 16 channel Cyton. This command is only useful for Cyton because of Daisy.

#### `boardType` - `cyton`

Description:
Force set to 8 channel Cyton board.

Availability:
As of `v2.0.0`

Example:
`{"type":"boardType", "boardType": "cyton"}`

Response: on success
`{"type":"boardType", "boardType": "cyton", "code": 200}`

Response: on failure
`{"type":"boardType", "boardType": "cyton", "code": 421, "message": "string error message"}`

#### `boardType` - `daisy`

Description:
Force set to 16 channel Cyton board.

Availability:
As of `v2.0.0`

Example:
`{"type":"boardType", "boardType": "daisy"}`

Response: on success
`{"type":"boardType", "boardType": "daisy", "code": 200}`

Response: on failure
`{"type":"boardType", "boardType": "daisy", "code": 421, "message": "string error message"}`

### Channel Settings

**type: `channelSettings`**

For setting the channel settings on a Cyton board with either WiFi or Serial protocols set.

Availability: as of `v2.0.0`

#### `action` - `start`

Description:
Used to start a channel setting sync. This will emit channel settings on success.

Availability:
As of `v2.0.0`

Example:
`{"type":"channelSettings", "action": "start"}`

Response: on success
`{"type":"channelSettings", "action": "start", "code": 200}`

Response: on failure when channel setting sync is already in progress
`{"type":"channelSettings", "action": "start", "code": 422, "message": "Sync in progress"}`

Response: on success for each channel, see the [Response Set](http://docs.openbci.com/OpenBCI%20Software/07-OpenBCI_Hub#openbci-electron-hub-response-set) below for _Channel Settings_.

#### `action` - `set`

Description:
Used to set a channel for cyton over wifi or ganglion.

**channelNumber**

Channel number as zero indexed i.e. 0-7 or 0-15 for Cyton and Cyton with Daisy respectively.

**powerDown**

Will be either `true` if channel is powered down and `false` if channel is powered up like normal.

**gain**
The integer version of the gain. i.e. 1, 2, 4, 6, 8, 12, 24

**inputType**

Selects the ADC channel input source. It's a 'String' that **MUST** be one of the following: "normal", "shorted", "biasMethod" , "mvdd" , "temp" , "testsig", "biasDrp", "biasDrn".

**bias**

Selects if the channel shall include the channel input in bias generation. It's a number where `true` includes the channel in bias (default) or `false` for channel removed from bias.

**srb2**

Select to connect `true` this channel's P input to the SRB2 pin. This closes a switch between P input and SRB2 for the given channel, and allows the P input to also remain connected to the ADC. It's an integer where `true` connects this input to SRB2 (default) or `false` which disconnect this input from SRB2.

**srb1**

Select to connect `true` all channels' N inputs to SRB1. This effects all pins, and disconnects all N inputs from the ADC. It's an integer where `true` connects all N inputs to SRB1 and `false` disconnects all N inputs from SRB1 (default).

Availability:
As of `v2.0.0`

Example:
```
{
  "action": "set",
  "type": "channelSettings",
  "channelNumber": 3,
  "powerDown": false,
  "gain": 24,
  "inputType": "normal",
  "bias": true,
  "srb2": true,
  "srb1": false
}
```

Response: on success
`{"type":"channelSettings", "action": "set", "code": 200}`

Response: on failure to set command
`{"type":"channelSettings", "action": "set", "code": 424, "message": "verbose error message here"}`

Response: on failure to parse input commands properly. This means comma separated string input did not contain the correct positioned items. Verify with example.
`{"type":"channelSettings", "action": "set", "code": 425, "message": "more verbose error message"}`

### Command

**type: `command`**

Passes through a `COMMAND`, either one char or a string, to a connected device.

Availability: as of `v2.0.0`

#### `command` - `*`

Description:
Single or multi char to get passed through the module to the connected board. Multi char limited to 30 on WiFi and 19 on BLE.

Availability:
As of `v2.0.0`

Example:
`{"type":"command", "command": "1"}`

Response: on success
`{"type":"command", "command": "start", "code": 200}`

Response: on failure unable to write to connected device
`{"type":"command", "command": "start", "code": 406, "message": "verbose error message"}`

Response: on failure when protocol of current device is not selected
`{"type":"command", "command": "start", "code": 420, "message": "verbose error message"}`

### Connect

**type: `connect`**

Connect to any device a local name or IP address.

Availability: as of `v2.0.0`

**name**

The local string name of a Cyton USB Dongle, Ganglion peripheral, or WiFi Shield unique name to connect to.

**burst** *optional*

True to use burst mode, only applies when UDP is set for protocol. Either `true` and `false`.

**sampleRate** *optional*

A number that is the requested sample rate to set the attached Ganglion or Cyton to. Ganglion must have v2.0.0 firmware or later and Cyton must have v3.0.0 firmware available. Value is in Hz and must be a valid sample rate for the board of choice.

**latency** *optional*

A number that is the latency for the inter-packet sending on the WiFi Shield. The time is in micro-seconds.

**protocol** *optional*

The type of internet protocol to use, either 'udp' or 'tcp'.

**ipAdderss** *optional*

The ip

Availability:
As of `v2.0.0`

Example for Ganglion and Cyton:
`{"type": "connect", "name": "Ganglion-XXXX"}`

Example for WiFi with name over tcp:
```
{
  "type": "connect",
  "name": "OpenBCI-XXXX",
  "latency": 1000,
  "sampleRate": 500,
  "protocol": "tcp"
}
```

Example for WiFi with IP Address over UDP with burst mode:
```
{
  "type": "connect",
  "ipAddress": "192.168.4.1",
  "latency": 1000,
  "sampleRate": 500,
  "protocol": "udp",
  "burst": true
}
```

Response: on success
`{"type":"connect", "firmware": "v2.0.0", "code": 200}`

Response: on failure to connect
`{"type":"connect", "code": 402, "message": "verbose error message"}`

Response: on failure already connected
`{"type":"connect", "code": 408}`

### Disconnect

**type: `disconnect`**

Disconnect from a connected device.

Availability:
As of `v1.0.0`

Example:
`{"type":"disconnect"}`

Response: on success
`{"type":"disconnect", "code": 200}`

Response: on failure unable to disconnect to connected device
`{"type":"disconnect", "code": 401, "message": "verbose error message"}`

### Examine

**type: `examine`**

Examine a WiFi shield.

Availability:
As of `v2.0.0`

Example with shield name:
`{"type":"examine", "shieldName": "OpenBCI-XXXX"}`

Example with ipAddress:
`{"type":"examine", "ipAddress": "192.168.4.1"}`

If was searching for WiFi Shield prior to start, expect response on a
`{"type":"scan", "action": "stop", "code": 200}`

Response: on success
`{"type":"examine", "code": 200}`

Response: on failure to connect to device
`{"type":"examine", "code": 402, "message": "verbose error message"}`

Response: on failure if already connected to device
`{"type":"examine", "code": 408, "message": "verbose error message"}`

Response: on failure to stop scan
`{"type":"examine", "code": 411, "message": "could not stop error"}`

### Examine
**x,SHIELD**

Connect to and sync info with WiFi Shield named _SHIELD_. Should have started scan and asynchronously received the WiFi Shield name prior to calling to examine.

Availability: as of `v2.0.0`

#### SHIELD

The local shield name of WiFi Shield such as `OpenBCI-ACDC`

Example: `x,OpenBCI-ACDC,;\n`

#### Responses

Response: on success
`x,200,;\n`
If was searching for WiFi Shield prior to start expect response on a
`s,200,stop,;\n`

Response: on failure to stop scan
`x,411,could not stop error,;\n`

Response: on already connected to WiFi Shield
`x,408,;\n`

### Impedance
**i,ACTION**

Stop or start impedance testing.

#### ACTION - START

`start`

Start impedance testing.

Availability: as of `v1.0.0`

Response: on success
`i,200,start,;\n`

Response: on failure
`i,414,string error message,;\n`

#### ACTION - STOP

`stop`

Stop impedance testing.

Availability: as of `v1.0.0`

Response: on success
`i,200,stop,;\n`

Response: on failure
`i,415,string error message,;\n`

### Protocol
**p,ACTION,PROTOCOL**

Protocol should also be started prior to each session. It will cleanly start a session.

#### ACTION - START

`start`

Start a protocol. Stop all other protocols before starting this new one.

Availability: as of `v2.0.0`

The currently supported protocols are `ble`, `serial` and `wifi`.

**PROTOCOL - BLE**

`ble`

Only the Ganglion uses the `ble` as of today. Paired, with `start`, the `ble` will start a ble attempt to start the bluetooth low energy drivers. [Tutorial found on docs.openbci.com](http://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-hardwaredriver-setup-for-openbci_gui-and-openbcihub-ganglion-on-windows). Windows it's very important for you to use Zadig tool as described in the tutorial.

Availability: as of `v2.0.0`

Example: `p,start,ble,;\n`

Response: on success, ganglion will also start searching once driver is initialized.
`p,200,ble,start,;\n`
`s,200,start,;\n`

Response: on failure
`p,412,failed to start driver,;\n`

**PROTOCOL - Serial (Dongle)**

`serial`

Only the Cyton uses the `serial` as of today. Paired, with `start`, the `serial` will start a serial driver. [Tutorial found on docs.openbci.com](http://docs.openbci.com/OpenBCI%20Software/01-OpenBCI_GUI#the-openbci-gui-hardwaredriver-setup-for-openbci_gui-and-openbcihub-cyton-on-macoswindowslinux). Need FTDI VCP drivers.

Availability: as of `v2.0.0`

Example: `p,start,serial,;\n`

Response: on success, ganglion will also start searching once driver is initialized.
`p,200,serial,start,;\n`

**PROTOCOL - WiFi Shield**

`wifi`

Both the Cyton and Ganglion can use the `wifi` protocol as of today. Paired, with `start`, the `wifi` command will start a wifi driver. There are no dependencies for this protocol.

Example: `p,start,wifi,;\n`

Response: on success, ganglion will also start searching once driver is initialized.
`p,200,wifi,start,;\n`

#### ACTION - STATUS

`status`

Check the to see if a protocol has been started and is set as the current protocol.

Availability: as of `v2.0.0`

The currently supported protocols are `ble`, `serial` and `wifi`.

**PROTOCOL - BLE**

`ble`

Availability: as of `v2.0.0`

Example: `p,status,ble,;\n`

Response: on ganglion was started successfully and running
`p,200,ble,status,;\n`

Response: on failure of ganglion to be started successfully
`p,501,ble,status,;\n`

**PROTOCOL - Serial (Dongle)**

`serial`

Availability: as of `v2.0.0`

Example: `p,status,serial,;\n`

Response: on cyton serial object started successfully and running
`p,304,;\n`

Response: on cyton serial object not started
`p,305,;\n`

**PROTOCOL - WiFi Shield**

`wifi`

Availability: as of `v2.0.0`

Example: `p,status,wifi,;\n`

Response: on wifi object started successfully and running
`p,304,;\n`

Response: on wifi object not started
`p,305,;\n`

#### ACTION - STOP

`stop`

Stop and destroy a protocol. These are designed to be over called, in that calling when protocol is not started, will still result in success message.

Availability: as of `v2.0.0`

The currently supported protocols are `ble`, `serial` and `wifi`.

**PROTOCOL - BLE**

`ble`

Availability: as of `v2.0.0`

Example: `p,stop,ble,;\n`

Response: on ganglion was stopped and cleaned up
`p,200,ble,stop,;\n`

**PROTOCOL - Serial (Dongle)**

`serial`

Availability: as of `v2.0.0`

Example: `p,stop,serial,;\n`

Response: on cyton serial was stopped and cleaned up
`p,200,serial,stop,;\n`

**PROTOCOL - WiFi Shield**

`wifi`

Availability: as of `v2.0.0`

Example: `p,stop,wifi,;\n`

Response: on wifi object stopped and cleaned up
`p,200,wifi,stop,;\n`

### Scan
**s,ACTION**

Scan for Ganglion BLE devices and when found, send their local names to requesting client.

#### ACTION - START

`start`

Start a scan. Stop a scan if one in progress before starting the newly requested scan.

Example: `s,start,;\n`

Availability: as of `v1.0.0`

Response: on success
`s,200,start,;\n`

Response: on failure to start scan
`s,412,start,;\n`

Response: on failure to stop scan in progress
`s,411,stop,;\n`

#### ACTION - STATUS

`status`

Is a scan in progress

Example: `s,status,;\n`

Availability: as of `v1.0.0`

Response: a scan is in progress
`s,302,;\n`

Response: a scan is not in progress
`s,303,;\n`

#### ACTION - STOP

`stop`

Stop a scan in progress

Example: `s,stop,;\n`

Availability: as of `v1.0.0`

Response: on success
`s,200,stop,;\n`

Response: on failure because there is no scan in progress to stop
`s,410,;\n`

Response: on failure because unable to stop scan
`s,411,string error message,;\n`

### SD Card
**m,ACTION,(DURATION)**

**Cyton must be connected over WiFi or Serial**

#### ACTION

* `start`

Start and SD card recording with a human readable command.

Example: `m,start,15min,;\n`

Availability: as of `v2.0.0`

#### DURATION

The duration you want to log SD information for. Opens a new SD file to write into. Limited to:

 * `14sec` - 14 seconds
 * `5min` - 5 minutes
 * `15min` - 15 minutes
 * `30min` - 30 minutes
 * `1hour` - 1 hour
 * `2hour` - 2 hour
 * `4hour` - 4 hour
 * `12hour` - 12 hour
 * `24hour` - 24 hour

#### Responses

Response: on success
`m,200,start,;\n`

Response: on failure because there is no SD card or some other failure
`m,499,start,No sd card found,;\n`

Response: on failure because unsupported protocol set
`m,433,;\n`

#### ACTION

* `stop`

Stop an SD card recording. Does not have DURATION property.

Example: `m,stop,;\n`

Availability: as of `v2.0.0`

Response: on success
`m,200,start,;\n`

Response: on failure with message
`m,499,stop,some error,;\n`

### Status
**q**

Get the status of a Hub. If the TCO server in the Hub is working, this will always respond true.

Availability: as of `v1.0.0`

Response: on success
`q,200,;\n`

### WiFi
**w,ACTION**

Used to get information on an attached WiFi Shield.

#### ACTION - ERASE CREDENTIALS

`eraseCredentials`

Erase credentials on the WiFi shield. Your WiFi shield must have no board attached. You should use the *Examine* command to connect to the WiFi Shield with no Ganglion or Cyton attached. The process will take about 6 seconds. WiFi Shield will become a hotspot again.

Availability: as of `v2.0.0`

Response: on success
`w,200,eraseCredentials,Rebooting wifi shield in 5 seconds,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

Response: on failure when failure to erase credentials command fails
`w,428,timeout waiting for response,;\n`

#### ACTION - GET FIRMWARE VERSION

`getFirmwareVersion`

Get the firmware version of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getFirmwareVersion,v1.1.4,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

#### ACTION - GET IP ADDRESS

`getIpAddress`

Get the IP Address of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getIpAddress,192.168.0.101,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

#### ACTION - GET MAC ADDRESS

`getMacAddress`

Get the MAC Address of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getMacAddress,AA:12:AB:23:11:CD,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

#### ACTION - GET TYPE OF BOARD ATTACHED

`getTypeOfAttachedBoard`

If the WiFi Shield is connected to a board, return the type of board. Potential board types are _none_, _cyton_, _daisy_, or _ganglion_

Availability: as of `v2.0.0`

Response: on success
`w,200,getTypeOfAttachedBoard,cyton,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

## Response Set
As soon as a client has established itself to the Hub as a requester of information, messages will asynchronously be sent to the client.

### Accelerometer
**t,CODE,AXIS_X,AXIS_Y,AXIS_Z**

Description: Accelerometer data from the Ganglion.
Availability: as of `v1.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good data is sent.

**AXIS_X**
The X axis in raw integer counts.

**AXIS_Y**
The Y axis in raw integer counts.

**AXIS_Z**
The Z axis in raw integer counts.

Response: on success
`a,202,50,0,30,;\n`

### Channel settings
**r,CODE,CHANNEL_NUMBER,POWER_DOWN,GAIN,INPUT_TYPE,BIAS,SRB2,SRB1**

Description: A channel setting for Cyton.
Availability: as of `v2.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good data is sent.

**CHANNEL_NUMBER**

Channel number as zero indexed i.e. 0-7 or 0-15 for Cyton and Cyton with Daisy respectively.

**POWER_DOWN**

Will be either `true` if channel is powered down and `false` if channel is powered up like normal.

**GAIN**
The integer version of the gain. I.e. 1, 2, 4, 6, 8, 12, 24

**INPUT_TYPE**

Selects the ADC channel input source. It's a 'String' that **MUST** be one of the following: "normal", "shorted", "biasMethod" , "mvdd" , "temp" , "testsig", "biasDrp", "biasDrn".

**BIAS**

Selects if the channel shall include the channel input in bias generation. It's a 'Bool' where `true` includes the channel in bias (default) or `false` it removes it from bias.

**SRB2**

Select to connect (`true`) this channel's P input to the SRB2 pin. This closes a switch between P input and SRB2 for the given channel, and allows the P input to also remain connected to the ADC. It's a 'Bool' where `true` connects this input to SRB2 (default) or `false` which disconnect this input from SRB2.

**SRB1**

Select to connect (`true`) all channels' N inputs to SRB1. This effects all pins, and disconnects all N inputs from the ADC. It's a 'Bool' where `true` connects all N inputs to SRB1 and `false` disconnects all N inputs from SRB1 (default).

### Impedance
**i,CODE,CHANNEL,VALUE**

Accelerometer data from the Ganglion.

Availability: as of `v1.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good data is sent.

**CHANNEL**
The channel number for the impedance `VALUE`. Either 1, 2, 3, 4 or 0 for the reference channel.

**VALUE**
The impedance value in ohms for `CHANNEL`.

Response: on success
`i,203,1,300,;\n`

### Message
**l,CODE,MESSAGE**

Description: Message from the Ganglion.
Availability: as of `v1.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good messages are sent.

**MESSAGE**
The string message from the Ganglion.

Response: on success
`l,200,string message,;\n`

### Samples
**t,CODE,SAMPLE_NUM,CHAN_1,CHAN_2,CHAN_3,CHAN_4,(CHAN_N),(PACKET_TYPE),(ACCEL_DATA/AUX_DATA)**

Sample channel data from the Ganglion or Cyton.

Availability: as of `v1.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good data is sent.

Availability: as of `v1.0.0`

**SAMPLE_NUM**
The sample number of this sample.

Availability: as of `v1.0.0`

**CHAN_1**
The first channel data in raw integer counts.

Availability: as of `v1.0.0`

**CHAN_2**
The second channel data in raw integer counts.

Availability: as of `v1.0.0`

**CHAN_3**
The third channel data in raw integer counts.

Availability: as of `v1.0.0`

**CHAN_4**
The forth channel data in raw integer counts.

Availability: as of `v1.0.0`

**CHAN_N**
The nth channel data in raw integer counts. Meaning the data will continue for the number of channels. Cyton would be 8 and daisy would be 16.

Availability: as of `v2.0.0`

**PACKET_TYPE**
The type of packet, can be as of `v2.0.0` either `0xC0` for 3 ACCEL_DATA raw integer count values or `0xC1` for 6 AUX_DATA 8 bit unsigned values.

Availability: as of `v2.0.0`

**ACCEL_DATA/AUX_DATA**
When PACKET_TYPE is `0xC0` then expect 3 ACCEL_DATA raw integer count values. When PACKET_TYPE is `0xC1` for 6 AUX_DATA 8 bit unsigned values that range between 0-255.

#### Responses

Response: on success
`t,204,1,1000,2000,8000,2500,;\n`
