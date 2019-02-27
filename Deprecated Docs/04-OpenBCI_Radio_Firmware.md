# Cyton Radio Firmware
##Overview
The OpenBCI Cyton boards communicate via RFduino Bluetooth modules made by RFdigital. This doc will cover the needs of the Cyton system, and how we met them with the Radio firmware. Our selection of Bluetooth and RFduino was based on the desire to connect with mobile devices, and the need for accessible development environment. RFduino modules come with a bootloader that allows uploading code via avrdude, just 'like' Arduino. There are some differences, but the basic process is very much the same between RFduino and Arduino UNO, for example. We were also able to wrork very closely with the RFduino team, and they helped us greatly over the development cycle.

OpenBCI comes with a RFduino module on-board for communication, and an RFduino based USB Dongle for communicating to computer. The method of 'talking' to and through the radio connection is standard Serial UART 8N1. It is necessary to have the paired radio modules because we also have a Arduino UNO bootloaded ATmega on the 8bit Board, and a chipKIT bootloaded PIC32 on the 32bit Board. Both of these uC's can be programmed using avrdude.

RFduino modules are built on a Bluetooth System-On-Chip radio from Nordic [nRF51822](http://www.nordicsemi.com/eng/Products/Bluetooth-Smart-Bluetooth-low-energy/nRF51822), and we are using the Gazelle stack, which gets us faster data transfer rates than using the BLE stack.

##Features and Limitations of Gazelle
The Gazelle stack is a proprietary high-speed protocol from Nordic Semi. The folks at RFduino wrap it in their Arduino compatible library and call it RFduinoGZLL. it makes high speed communication possible, but it still comes with some limits. 

* Radio Packets are 32 bytes max
* The Packet buffer is 3 packets deep
* Fastest usable baud rate is 115200 (see below for notes)

The Device Radio (on OpenBCI Board) can send any time it likes, but the Host Radio (on Dongle) can only send on the acknowledgement. In other words, If the Host wants to send something it has to wait for a packet from the Device, and then it can send its message on what is called the acknowledgement, a response that tells the Device that the packet was received. So, when the radios are 'idle', we have the Device sending a NULL packet (packet with no data) every 60mS. That timing seemed to be a sweet spot for our purposes, and makes it possible for either side of the radio link to initiate a conversation.

##Uploading Over-Air With avrdude
On a basic level, the radio link that we use needs to act as close to a transparent UART as possible. That means that any serial message, whether it's one byte or 128 bytes, needs to get from the PC to the OpenBCI Board (and back) as if the radio modules weren't even there. The first and most important problem to solve was enabling the upload of new code to the ATmega and PIC32. During the Summer of 2014, we put together an Instructable to document the work done on this front

[Program Arduino Over RFduino](http://www.instructables.com/id/Program-Arduino-Over-RFduino/)

That code formed the backbone of the OpenBCI radio firmware. Here's a list of the features:

* Large (640 bytes) 2 Dimensional Linear Buffer serialBuffer[20][32]
* Time-out on the Serial port to determine the end of Serial message
* First byte of the message reserved for Packet check-sum

Avrdude uploads code to ATmega328 with UNO bootloader in 128 byte pages, and the PIC32 with chipKIT bootloader uses 256 byte pages. The Host needs to make sure all of the bytes get through, so it uses a timer. If the UART is idle for more than 2mS, it will determine that the message is complete, and then put it on the radio. When sending large amounts of data, the firmware stores it in a 2D array, or matrix. Our firmware uses 20 32byte arrays to 'stage' whatever comes in on the serial port. While the UART is active, the firmware keeps track of how many 32byte packets are going to be sent, and then sets the very first byte of the very first packet to that value. The RFduino on the receiving side always checks that very first byte in order to know how many packets to expect.

The other basic thing we need to do is have a way for the RFduinos to communicate to each other special messages that the PC and ATmega (or PIC32) don't see. These 'radio only' messages are used for sending the reset command to the ATmega, and for keeping the radios on the same page when uploading to the PIC32. Radio only messages are always packets that have only one byte in them. Any other packet will have at least two bytes (Packet Check-Sum + Data Byte)

###32bit Board



The version of ChipKIT's bootloader that we're using does not have an automatic reset like the 8bit Board does. However, we still need to keep track of when the user wants to upload code to the PIC. To do this, we have the Device monitor a pin on the PIC. RFduino pin 5 is connected to PIC pin 12(which is also known as the PGC pin to PIC programmers). The PIC pin 12 goes HIGH when it is in bootloader mode. To [upload to 32bit OpenBCI](http://docs.openbci.com/tutorials/02-Upload_Code_to_OpenBCI_Board#upload-code-to-openbci-board-32bit-upload-how-to), press the RST button, then press and hold the PROG button while you release the RST button. Takes coordination! Users will activate bootloader mode in the chipKIT before pressing the upload button on mpide. When the Device radio feels this pin change, it sends a special character to let the Host (Dongle) know. This is important because we found that uploading to the PIC can be prone to errors if the code is trying to do *anything* else during the process.
	
			32bit DEVICE BOOTLOADER MODE CODE
			
	PGCpinState = digitalRead(PGCpin);
	if(PGCpinState != lastPGCpinState){
  		delay(5); // debounce
  		if(PGCpinState == LOW){
    		inBootLoaderMode = false;
    		RFduinoGZLL.sendToHost(outBoot,1);	// sends '('
  		}else{
    		inBootLoaderMode = true;
    		RFduinoGZLL.sendToHost(inBoot,1);	// sends '9'
  		}
  		lastPGCpinState = PGCpinState;
	}
	
			32bit HOST BOOTLOADER MODE CODE
			
	if(len == 1){  // radios send messages to eachother in single byte packets
      if(data[0] == '9') {deviceInBoot = true;} 
      if(data[0] == '(') {deviceInBoot = false;} 
      return;
    }
    
    resetPinValue = digitalRead(resetPin);
  	if(resetPinValue != lastResetPinValue){
    	if(resetPinValue == LOW){
      		if(deviceInBoot) {inBootLoaderMode = true;}  // only go inBootLoaderMode when PIC is also
    	}else{  // FTDI sets the DTR pin low when serial port is open (terminal software, apps, etc)
      		inBootLoaderMode = false; 
    	}
    	lastResetPinValue = resetPinValue;
  	}

##Passing OpenBCI commands
OpenBCI uses ASCII commands to control the board. Setting up the SD card, changing ADS channel settings, turning on and off the data stream, are all done with a simple command set. One of this issues with this simple system, is that sometimes it becomes easy for noise to creep in. We found that during data transmission mode, there would be occasional glitches, where the PIC or ATmega would appear to receive a command that we did not send (!). In order to get around this, we established what Conor dubbed 'The Burger Protocol'. What this means is that any time the PC or other controlling program sends a command character (meat), the Host RFduino will insert a '+' before and after it (buns). This way, the ATmega or PIC will not get tricked that extraneous noise on the UART is a command. The RFduinos 'know' when a command is being sent, because the OpenBCI commands are always only one character. Anything longer that 1 byte will not be burgerized. In the example at the right, the serialIndex[0] variable holds the number of bytes that are to be sent from the buffer. In this case, it is equal to 2 when there is only 1 bytes sent from the terminal or controlling program, because the first byte in the array will always be reserved for the packet check sum. You can see on the right that the message byte (meat) gets moved from serialBuffer[0][1] to serialBuffer[0][2], and then surrounded by '+' characters (buns). As a part of this process, the command byte gets 'sniffed' by the Host and Device RFduinos to see if the OpenBCI board is entering or leaving Streaming Data Mode. The controlling program sends a 'b' to begin streaming data, and an 's' to stop streaming data. RFduinos need to know this in order to change their behavior and stream the data at high speed.

			8bit EXAMPLE OF BURGER PROTOCOL ON HOST RFduino with COMMAND SNIFFING
			
	if(serialIndex[0] == 2){	// single byte messages from uC are special we need to burgerize them
        testSerialByte(serialBuffer[0][1]);  // could be command to streamData, go sniff it
        serialBuffer[0][2] = serialBuffer[0][1];  // move the command byte into patty position
        serialBuffer[0][1] = serialBuffer[0][3] = '+';  // put the buns around the patty
        serialIndex[0] = 4;                  // now we're sending the burger protocol
      }       
      
      
    void testSerialByte(char z){
      switch(z){
    	case 'b':  // PC wants to stream data
      		streamingData = true;  // enter streaimingData mode
      		streamingIdleTimer = millis();
      		radioIndex = 0;        
      		tail = 0;             
      		break;
    	case 's':  
      		streamingData = false;  // get out of streamingData mode
      		radioIndex = 0;         // reset radioBuffer index
      		break;
    	default:
      		break;
      	} 
	 }		

##Streaming Data Mode
The most sensitive state of the OpenBCI system is during streaming data mode. During this mode, the 2D linear buffer on the Device RFduino is turned into a 2D ring buffer, and both the Device and Host RFduinos will expect no more than one packet at a time, and that packet is expected to be complete (31 data bytes, 1 sample counter byte). The Device code also employs some error checking: if a packet is not complete (31 bytes of data) in a reasonable time (1000uS) then the packet is thrown out, and a new one is started.


##8bit Board
###~~Depricated


The Arduino UNO bootloader runs when the ATmega 'wakes up' from reset. Back in the day the reset signal had to be sent manually by pressing the Arduino reset button. Then some smart folks hijacked the DTR pin (legacy RS232 Handshaking pin) from the FTDI USB<>Serial chip to 'automatically' perform the reset function. We wanted to retain this automatic reset feature, so we are using 'special message' function of our code to pass the reset signal to the OpenBCI Board. With the slide switch on our USB Dongle set to GPIO6, the RFduino Host can 'feel' the polarity of the DTR on its pin 6, and then send a special character to the Device. When the Device gets the special character, it resets the ATmega. That makes it possible to upload code from the Arduino IDE and treat the 8bit Board just as if it were an Arduino UNO. 


			8bit HOST REMOTE RESET CODE
			
	resetPinValue = digitalRead(resetPin);
	if(resetPinValue != lastResetPinValue){
    	if(resetPinValue == LOW){
      		RFmessage[0] = '9';  // Device will toggle target MCLR when it gets '9'
    	}else{
      		RFmessage[0] = '(';  // Device will toggle target MCLR when it gets '('
    	}  
    	sendRFmessage = true; 
    	lastResetPinValue = resetPinValue;
    }
    
    
    		8bit DEVICE REMOTE RESET CODE
    		
    boolean testFirstRadioByte(char z){  // test the first byte of a new radio packet for reset msg
    boolean r;
	switch(z){
    	case '9':                 // HOST sends '9' when its GPIO6 goes LOW
      		digitalWrite(resetPin,LOW);  // clear RESET pin
      		r = true;  
      		break;
    	case '(':                 // HOST sends '(' when its GPIO6 goes HIGH
      		digitalWrite(resetPin,HIGH); // set RESET pin
      		r = true;
      		break;   
    	default:
      		r = false;
      		break;
    }
    return r;     // this might be useful
	}






