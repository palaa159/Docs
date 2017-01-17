# OpenBCI Electron Hub
Middleware Software used to communicate with OpenBCI boards through TCP/IP command protocol. This Doc covers the OpenBCI Hub for Ganglion, the Cyton (32bit board) is NOT functional through this interface.
 
## Version
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

**ACTION**

* `start`

Start accelerometer.

Availability: as of `v1.0.0`

Response: on success
`a,200,start,;\n`

Response: on failure
`a,416,string error message,;\n`

* `stop`

Stop accelerometer.

Availability: as of `v1.0.0`

Response: on success
`a,200,stop,;\n`

Response: on failure
`a,417,string error message,;\n`

### Command
**k,COMMAND**

Passes through a single char `COMMAND` to a connected device.

Availability: as of `v1.0.0`

**COMMAND**

Single char to get passed through the module to the connected board. 

Response: on success
`k,200,;\n`

Response: on failure because no connected device
`k,400,;\n`

Response: on failure unable to write to connected device
`k,406.string error message,;\n`

### Connect
**c,PORT_NAME**

Connect to a Ganglion BLE device with only a local name.

**PORT_NAME**

The local string name of a Ganglion peripheral to connect to.

Availability: as of `v1.0.0`

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
Response: on success
`d,200,;\n`
Response: on failure unable to disconnect
`d,401,string error message,;\n`

### Impedance
**i,ACTION**

Stop or start impedance testing.

**ACTION**

* `start`

Start impedance testing.

Availability: as of `v1.0.0`

Response: on success
`i,200,start,;\n`

Response: on failure
`i,414,string error message,;\n`

* `stop`

Stop impedance testing.

Availability: as of `v1.0.0`

Response: on success
`i,200,stop,;\n`

Response: on failure
`i,415,string error message,;\n`

### Scan
**s,ACTION**

Scan for Ganglion BLE devices and when found, send their local names to requesting client.

**ACTION**

* `start`

Start a scan. Stop a scan if one in progress before starting the newly requested scan.

Availability: as of `v1.0.0`

Response: on success
`s,200,start,;\n`

Response: on failure to start scan
`s,412,start,;\n`

Response: on failure to stop scan in progress
`s,411,stop,;\n`

* `status`

Is a scan in progress

Availability: as of `v1.0.0`

Response: a scan is in progress
`s,302,;\n`

Response: a scan is not in progress
`s,303,;\n`

* `stop`

Stop a scan in progress

Availability: as of `v1.0.0`

Response: on success
`s,200,stop,;\n`

Response: on failure because there is no scan in progress to stop
`s,410,;\n`

Response: on failure because unable to stop scan
`s,411,string error message,;\n`

### Status
**q**

Get the status of a Hub. If the TCO server in the Hub is working, this will always respond true.

Availability: as of `v1.0.0`

Response: on success
`q,200,;\n`

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
