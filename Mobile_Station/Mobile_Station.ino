
#include <Wire.h>

int RPYPin[3];        // Array to store connection pins
float arrRPY[3];     // Array to store roll, pitch & yaw values

void setup()
{
  // Defining analog pins
  RPYPin[0] = 0;
  RPYPin[1] = 1;
  RPYPin[2] = 2;

  // Opening up serial port
  Serial1.begin(9600);

  // Delay to open serial window manually
  delay(5000);
}

void loop() {
  // Roll pin mapping
  arrRPY[0] = analogRead(RPYPin[0]);
  arrRPY[0] = map(arrRPY[0], 0, 1023, -10.00, 10.00);
  // Pitch pin mapping
  arrRPY[1] = analogRead(RPYPin[1]);
  arrRPY[1] = map(arrRPY[1], 0, 1023, -10.00, 10.00);
  // Yaw pin mapping
  arrRPY[2] = analogRead(RPYPin[2]);
  arrRPY[2] = map(arrRPY[2], 0, 1023, -10.00, 10.00);

  // Print data serially (Wireless)
  Serial1.print("<");
  Serial1.print(arrRPY[0]);
  Serial1.print("|");
  Serial1.print(arrRPY[1]);
  Serial1.print("|");
  Serial1.print(arrRPY[2]);
  
  // Print data serially (USB port)
  Serial.print("<");
  Serial.print(arrRPY[0]);
  Serial.print("|");
  Serial.print(arrRPY[1]);
  Serial.print("|");
  Serial.println(arrRPY[2]);

}
