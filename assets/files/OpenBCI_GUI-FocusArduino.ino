
// Example 2 - Receive with an end-marker

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;
boolean isFocusedFromGUI = false;

void setup() {
    Serial.begin(57600);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvWithEndMarker();
    showNewData();
    if (isFocusedFromGUI) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        String s = receivedChars;
        if (s.equals("false")) {
          Serial.println("Input: FALSE");
          isFocusedFromGUI = false;
        } else if (s.equals("true")) {
          Serial.println("Input: TRUE");
          isFocusedFromGUI = true;
        } else {
          Serial.println("This just in ... " + s);
        }
        newData = false;
    }
}
