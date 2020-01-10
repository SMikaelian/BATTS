#include <MPU9250.h>
#include <TinyGPS++.h>
#include <Wire.h>



// The TinyGPS++ object
TinyGPSPlus gps;


MPU9250 IMU(Wire,0x68);
 int status;

float arrRPY[9];     // Array to store roll, pitch & yaw values

const char *gpsStream =
  "$GPRMC,045103.000,A,3014.1984,N,09749.2872,W,0.67,161.46,030913,,,A*7C\r\n"
  "$GPGGA,045104.000,3014.1985,N,09749.2873,W,1,09,1.2,211.6,M,-22.5,M,,0000*62\r\n"
  "$GPRMC,045200.000,A,3014.3820,N,09748.9514,W,36.88,65.02,030913,,,A*77\r\n"
  "$GPGGA,045201.000,3014.3864,N,09748.9411,W,1,10,1.2,200.8,M,-22.5,M,,0000*6C\r\n"
  "$GPRMC,045251.000,A,3014.4275,N,09749.0626,W,0.51,217.94,030913,,,A*7D\r\n"
  "$GPGGA,045252.000,3014.4273,N,09749.0628,W,1,09,1.3,206.9,M,-22.5,M,,0000*6F\r\n";


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
  while (*gpsStream)
    if (gps.encode(*gpsStream++))
      displayInfo();

  Serial.println();
  Serial.println(F("Location Transmitted."));
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

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
