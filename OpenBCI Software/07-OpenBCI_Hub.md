# OpenBCI Electron Hub

Middleware Software used to communicate with OpenBCI boards through TCP/IP command protocol. This Doc covers the OpenBCI Hub for Cyton, Ganglion, and WiFi Shield. the Cyton (32bit board) is NOT functional through this interface.

## Version
Version `v2.0.0` release September 2017
Version `v1.0.0` released January 3rd, 2017.

## OpenBCI Electron Hub Overview
The OpenBCI Electron Hub (or just "Hub") is a TCP/IP server that listens for clients on port `10996` on `localhost` aka `127.0.0.1`. Broadcast/multicast is never used for transmitting information to clients. Outgoing data is only transmitted to the requesting client. We use [semantic versioning](http://www.semver.org) the protocol is always listed first and foremost in all documentation. Please follow the rules of [semantic versioning](http://www.semver.org) to avoid breaking changes.

The hub is designed for either two use cases:

1. An owning application, such as OpenBCI's processing app, starts and stops the Hub.
2. The Hub runs continuously and 3rd party applications can simply connect as clients, use OpenBCI boards, disconnect and go on their way without closing the Hub.

A unique port, `10996`, is critical because applications must be able to hit a known port number on a local machine. This Specification shall [be available here](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron/blob/master/ganglion-api-spec.yaml) in the [source code of the Hub](https://github.com/OpenBCI/OpenBCI_Ganglion_Electron).

## Hub Command Protocol Overview

The Hub uses a comma-separated-value system followed by stop characters. The stop characters are `,;\n` or ("comma" "semi-colon" "backslash n"). A recommended client parsing is to store incoming TCP data into a buffer until the stop characters `';\n` are consecutively identified. The contents of the buffer can be now be considered a Message. The buffer can be flushed and the Message can be processed. Split the Message by `,` ("comma") to facilitate parsing. The first value will always be the command. The rest of the Message will then be translated based on the protocol for that command described in the Specification below. All commands sent to the client will be replied to asynchronously.

### Example:
If a client sends `s,start,;\n` to the Hub on `127.0.0.1:10996`, the Hub will respond with either `s,200,start,;\n` if the scan was started or an error message if unable to start such as `s,412,unable to start scan,;\n`.

## Command Set
Commands are sent from the client to the Hub. Each command gets an asynchronous response with a meaningful code. When able, errors are sent with string error messages.

### Accelerometer
**a,ACTION**

Stop or start accelerometer.

#### ACTION - START

`start`

Start accelerometer. Only useful for Ganglion.

Availability: as of `v1.0.0`

Response: on success
`a,200,start,;\n`

Response: on failure
`a,416,string error message,;\n`

#### ACTION - STOP

`stop`

Stop accelerometer. Only useful for Ganglion.

Availability: as of `v1.0.0`

Response: on success
`a,200,stop,;\n`

Response: on failure
`a,417,string error message,;\n`

### Board Type
**b,BOARD_TYPE**

Attempts to set the board type to user requested board type, such as when a user requests 16 channel Cyton. This command is only useful for Cyton because of Daisy.

Availability: as of `v2.0.0`

#### BOARD_TYPE - CYTON

`cyton`

Force set to 8 channel Cyton board.

Availability: as of `v2.0.0`

Example: `b,cyton,;\n`

#### BOARD_TYPE - DAISY

`daisy`

Availability: as of `v2.0.0`

Example: `b,daisy,;\n`

#### Responses

Response: on success where board type set correctly to Cyton with 8 Channels
`b,200,cyton,;\n`

Response: on success where board type set correctly to Cyton with Daisy 16 Channels
`b,200,daisy,;\n`

Response: on failure to set board correctly to Cyton or Daisy with 8 or 16 Channels
`b,421,some error message,;\n`

### Channel Settings
**r,ACTION,(ARGS)**

For setting the channel settings on a Cyton board with either WiFi or Serial protocols set.

Availability: as of `v2.0.0`

#### ACTION - START

`start`

Used to start a channel setting sync. This will emit channel settings on success.

Availability: as of `v2.0.0`

Example: `r,start,;\n`

Response: on success for each channel, see the [Response Set](http://docs.openbci.com/OpenBCI%20Software/07-OpenBCI_Hub#openbci-electron-hub-response-set) below for _Channel Settings_.

#### ACTION - SET

`set`

Used to set a channel for cyton over wifi or ganglion.

Availability: as of `v2.0.0`

Example: `r,set,3,0,24,normal,1,1,0,;\n`

**CHANNEL_NUMBER**

Channel number as zero indexed i.e. 0-7 or 0-15 for Cyton and Cyton with Daisy respectively.

**POWER_DOWN**

Will be either `1` if channel is powered down and `0` if channel is powered up like normal.

**GAIN**
The integer version of the gain. i.e. 1, 2, 4, 6, 8, 12, 24

**INPUT_TYPE**

Selects the ADC channel input source. It's a 'String' that **MUST** be one of the following: "normal", "shorted", "biasMethod" , "mvdd" , "temp" , "testsig", "biasDrp", "biasDrn".

**BIAS**

Selects if the channel shall include the channel input in bias generation. It's a number where `1` includes the channel in bias (default) or `0` for channel removed from bias.

**SRB2**

Select to connect (`1`) this channel's P input to the SRB2 pin. This closes a switch between P input and SRB2 for the given channel, and allows the P input to also remain connected to the ADC. It's an integer where `1` connects this input to SRB2 (default) or `0` which disconnect this input from SRB2.

**SRB1**

Select to connect (`1`) all channels' N inputs to SRB1. This effects all pins, and disconnects all N inputs from the ADC. It's an integer where `1` connects all N inputs to SRB1 and `0` disconnects all N inputs from SRB1 (default).

Response: on success
`r,200,set,;\n`

Response: on failure to set command
`r,424,verbose error message here,;\n`

Response: on failure to parse input commands properly. This means comma separated string input did not contain the correct positioned items. Verify with example.
`r,425,more verbose error message,;\n`

### Command
**k,COMMAND**

Passes through a `COMMAND`, either one char or multiple chars, to a connected device.

Availability: as of `v1.0.0`

#### COMMAND

Single or multi char to get passed through the module to the connected board. Multi char limited to 30 on WiFi and 19 on BLE.

Response: on success
`k,200,;\n`

Response: on failure because no connected device
`k,400,;\n`

Response: on failure unable to write to connected device
`k,406.string error message,;\n`

### Connect
**c,PORT_NAME,(SAMPLE_RATE),(LATENCY)**

Connect to a Ganglion BLE device with only a local name.

#### PORT_NAME

The local string name of a Cyton USB Dongle, Ganglion peripheral, or WiFi Shield unique name to connect to.

Availability: as of `v1.0.0`

Example: `c,Ganglion-XXXX,;\n` for BLE for Ganglion
Example: `c,COM4,;\n` for Serial on Windows

#### SAMPLE_RATE

**Only Required for WiFi connection**

A number that is the requested sample rate to set the attached Ganglion or Cyton to. Ganglion must have v2.0.0 firmware or later and Cyton must have v3.0.0 firmware available. Value is in Hz and must be a valid sample rate for the board of choice.

Availability: as of `v2.0.0`

Example: `c,OpenBCI-ACDC,1000,15000,;\n` for Cyton/Daisy set to 1000Hz
Example: `c,OpenBCI-ACDC,1600,15000,;\n` for Ganglion set to 1600Hz

#### LATENCY

**Only Required for WiFi connection**

A number that is the latency for the inter-packet sending on the WiFi Shield. The time is in micro-seconds.

Availability: as of `v2.0.0`

Example: `c,OpenBCI-ACDC,1000,5000,;\n` for latency set to 5000uS (5 ms)

#### Responses

Response: on success
`c,200,;\n`

Response: on failure unable to connect
`c,402,string error message,;\n`

Response: on failure to connect because already connected to another device
`c,408,;\n`

Response: on failure unable to stop scan before verification for connect or unable to stop the verification scan.
`c,411.string error message,;\n`

Response: on failure unable to start verification scan before connect
`c,412,string error message,;\n`

Response: on failure unable to verify, aka scan and find the requested BLE peripheral with local name matching the requested supplied `PORT_NAME` within 5 seconds.
`c,413,;\n`


### Disconnect
**d**

Disconnect from a connected Ganglion BLE device.

Availability: as of `v1.0.0`

Example: `d,;\n`

Response: on success
`d,200,;\n`

Response: on failure unable to disconnect
`d,401,string error message,;\n`

### Examine
**x,SHIELD**

Connect to and sync info with WiFi Shield named _SHIELD_. Should have started scan and asynchronously received the WiFi Shield name prior to calling to examine.

Availability: as of `v2.0.0`

#### SHIELD

The local shield name of WiFi Shield such as `OpenBCI-ACDC`

Example: `x,OpenBCI-ACDC,;\n`

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

**DURATION**

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

#### ACTION

* `eraseCredentials`

Erase credentials on the WiFi shield. Your WiFi shield must have no board attached. You should use the *Examine* command to connect to the WiFi Shield with no Ganglion or Cyton attached. The process will take about 6 seconds. WiFi Shield will become a hotspot again.

Availability: as of `v2.0.0`

Response: on success
`w,200,eraseCredentials,Rebooting wifi shield in 5 seconds,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

Response: on failure when failure to erase credentials command fails
`w,428,timeout waiting for response,;\n`

* `getFirmwareVersion`

Get the firmware version of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getFirmwareVersion,v1.1.4,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

* `getIpAddress`

Get the IP Address of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getIpAddress,192.168.0.101,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

* `getMacAddress`

Get the MAC Address of the attached WiFi Shield.

Availability: as of `v2.0.0`

Response: on success
`w,200,getMacAddress,AA:12:AB:23:11:CD,;\n`

Response: on failure because no wifi shield attached
`w,426,;\n`

* `getTypeOfAttachedBoard`

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
**t,CODE,SAMPLE_NUM,CHAN_1,CHAN_2,CHAN_3,CHAN_4**

Sample channel data from the Ganglion.

Availability: as of `v1.0.0`

**CODE**
The success or error code for the packet. As of `v1.0.0`, only good data is sent.

**SAMPLE_NUM**
The sample number of this sample.

**CHAN_1**
The first channel data in raw integer counts.

**CHAN_2**
The second channel data in raw integer counts.

**CHAN_3**
The third channel data in raw integer counts.

**CHAN_4**
The forth channel data in raw integer counts.

Response: on success
`t,204,1,1000,2000,8000,2500,;\n`
