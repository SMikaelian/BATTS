#include <TinyGPS++.h>
#include <Wire.h>
#include "MPU9250.h"


// The TinyGPS++ object
TinyGPSPlus gps;


MPU9250 IMU(Wire,0x68);
 int status;

float arrRPY[9];     // Array to store roll, pitch & yaw values

void setup()
{

  Serial3.begin(115200);
  // Opening up serial port
  Serial1.begin(57600);

  while(!Serial1) {}

  while (*gpsStream)
    if (gps.encode(*gpsStream++))
      displayInfo();

  Serial.println("Done with GPS Setup");

  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}

  // Delay to open serial window manually
  delay(5000);
}
}

void loop() {
//  // Roll pin mapping
//  arrRPY[0] = analogRead(RPYPin[0]);
//  arrRPY[0] = map(arrRPY[0], 0, 1023, -10.00, 10.00);
//  // Pitch pin mapping
//  arrRPY[1] = analogRead(RPYPin[1]);
//  arrRPY[1] = map(arrRPY[1], 0, 1023, -10.00, 10.00);
//  // Yaw pin mapping
//  arrRPY[2] = analogRead(RPYPin[2]);
//  arrRPY[2] = map(arrRPY[2], 0, 1023, -10.00, 10.00);
//
//  // Print data serially (Wireless)
  /*
  Serial1.print("<");
  Serial1.print(arrRPY[0]);
  Serial1.print("|");
  Serial1.print(arrRPY[1]);
  Serial1.print("|");
  Serial1.print(arrRPY[2]);
  Serial1.println(">\n");
  */

  IMU.readSensor();
  Serial1.print("< ");
  Serial1.print(IMU.getAccelX_mss(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getAccelY_mss(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getAccelZ_mss(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getGyroX_rads(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getGyroY_rads(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getGyroZ_rads(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getMagX_uT(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getMagY_uT(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getMagZ_uT(),6);
  Serial1.print(", ");
  Serial1.print(IMU.getTemperature_C(),6);
  Serial1.println(" >");
  Serial1.
  
  // Print data serially (USB port)
  /*
  Serial.print("<");
  Serial.print(arrRPY[0]);
  Serial.print("|");
  Serial.print(arrRPY[1]);
  Serial.print("|");
  Serial.println(arrRPY[2]);
  */
  Serial.print("< ");
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print(", ");
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print(", ");
  Serial.print(IMU.getAccelZ_mss(),6);
  Serial.print(", ");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print(", ");
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print(", ");
  Serial.print(IMU.getGyroZ_rads(),6);
  Serial.print(", ");
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print(", ");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print(", ");
  Serial.print(IMU.getMagZ_uT(),6);
  Serial.print(", ");
  Serial.print(IMU.getTemperature_C(),6);
  Serial.println(" >");
  delay(100);
  
}
