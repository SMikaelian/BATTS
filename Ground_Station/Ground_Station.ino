 float arrRPY[3];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
}

void getRPY() {     // Get roll, pitch & yaw function
  byte byteRead;   // Read first byte of the incoming transmission
  boolean startByte = false;   // Boolean opperator

  
  while (Serial.available() > 0) {  // While there is serial data being trasmitted
    
    byteRead = Serial.read();  // Read first byte received
    Serial.println(byteRead);   // Visual check for myself to see what it is
    
    while (byteRead >= 60 || byteRead <= 60) {  // 60 is ASCII code for <, which is my identifier
      byteRead = Serial.read();   // read next byte until it is 60 (<)
      Serial.println(byteRead);    // Visual check for myself
    }
    if (byteRead == 60) {  // If 60 (<) is detected
      startByte = true;       // Change boolean operator value
    if (startByte) {             // If startByte is detected use Serial.parseFloat() to detect the next floating
      arrRPY[0] = Serial.parseFloat();  //point value in the serial communication and write the floating
      arrRPY[1] = Serial.parseFloat();  // point value to the storage array.
      arrRPY[2] = Serial.parseFloat();
    }
  }
  Serial.print(arrRPY[0]); Serial.print(" | "); Serial.print(arrRPY[1]); Serial.print(" | "); Serial.println(arrRPY[2]);  // Visual check to see what has been written to the array.
  }
}
