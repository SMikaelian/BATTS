//#include <HardwareSerial.h>
//#include <SoftwareSerial.h>
//
//float re;
//void setup() {
//  // put your setup code here, to run once:
//  Serial2.begin(57600);
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  if(Serial3.available() > 0){
//    re= Serial2.read();
//    //Serial3.print((char) );
//    Serial2.println("Works");
//    Serial2.println(re);
//    Serial.println("Working..");
//    delay(500);
//  }
//}

#include <SoftwareSerial.h>

SoftwareSerial mySerial(15, 14); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  //Serial1.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(57600);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
