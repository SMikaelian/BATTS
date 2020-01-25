// Code to receive serial floating point sensor data
// NOTES:
//
// SETUP:
//  ________________________            _______________________
// |       TRANSMITTER      |          |        RECEIVER       |
// | Teensy 3.0 + MPU6050 + | -------> | Arduino Mega 2560 R3 + |
// | 3DR  915MHz Air Module | -------> | 3DR 915MHz Air Module |
// |________________________|          |_______________________|
//
// - Print serial data normally on the sending side as if you were going to send it serially
//   over the USB port (Serial1 for hardware pins on Leonardo etc.)
// - Use the following code on the receiving controller:

float arrRPY[3];                                   // Array to store the roll, pitch & yaw values

void setup() {                                     // Setup function that runs initially on MCU startup
  Serial.begin(57600);                             // Start serial usb connection
  Serial1.begin(57600);                            // Start hardware serial pins connection
}

void loop() {                                      // Loop function running continuously after MCU has been setup
  getRPY();                                        // Function storing roll, pitch & yaw in arrRPY array
}

void getRPY() {                                    // Function storing roll, pitch & yaw in arrRPY array
  byte byteRead;                                   // Serial comms transmits bytes, this stores the initially read byte from the serial stream

  while (Serial1.available() > 0) {                // While data is available in the serial buffer

    byteRead = Serial1.read();                     // Read the first byte in the serial buffer
    // Searching for the start byte "<" (ASCII = 60)
    while (byteRead > 60 || byteRead < 60) {       // If the byte value is greater than or less that 60
      byteRead = Serial1.read();                   // keep reading the byte stream until 60 is found, ie. "<"
    }
    if (byteRead == 60) {                          // If "<" found
      for (int i = 0 ; i <= 2 ; i++) {             // I expected 3 values, so I looped 3 times
        arrRPY[i] = Serial1.parseFloat();          // Write the parsed floating point value found in the serial stream to arrRPY
      }
    }
    // Check that the correct values are being written to the array by examining them in a serial terminal
    Serial.print("<"); Serial.print(arrRPY[0]); Serial.print(","); Serial.print(arrRPY[1]); Serial.print(","); Serial.print(arrRPY[2]); Serial.println(">");
    break;
  }
}
