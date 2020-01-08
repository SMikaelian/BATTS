#include <HardwareSerial.h>
int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial3.begin(57600);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // send data only when you receive data:
  if (Serial3.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial3.read();

    // say what you got:
    Serial3.print("I received: ");
    Serial3.println(incomingByte, DEC);
    Serial.println(incomingByte, DEC);
    delay(500);
    Serial3.println("Working..");
    Serial.println("Working..");
  }
}

//#include <SoftwareSerial.h>
//
//#define BAUDRATE 57600
//
//SoftwareSerial radioSerial(0,1); // Rx, Tx
//char inByte;
//
//void setup(){
//  Serial.begin(BAUDRATE);
//  radioSerial.begin(BAUDRATE);
//}
//
//void loop(){
//  if(radioSerial.available() > 0){
//    inByte = radioSerial.read();
//    Serial.write(inByte);
//  }
//}
