# BATTS
Ballistic Acquisition Telemetry and Trajectory System using an Arduino to report telemetry from a self-contained device such as a drone to a fixed ground station.


Questions:
-How should each axis of data be mapped?
-What communication protocol is each component of the project using?
-How will the data be collected from the Arduino?
-How does the Beitan GPS work? How do we print data from it to the serial monitor repeatedly?
-How does the Serial*.available() function work?
-How many devices can the Mega handle?
-At what baud rate is the data optimally received at from each device?
-What have we learned so far?
-If we were to receive data from the computer, how would it be graphed?


Priority I:
-Transmission of data from the Teensy 3.2 to an Arduino using the 3DR radio transmitter/receiver.


Priority II:
-Read data from Accelerometer board to Teensy, document and implement a simple data transmission protocol. Eg. A = Accelerometer Data, G = Gyroscope Data, M = MPU Magnetometer Data, and  AD = ADXL345 Board Data

Data is output to the serial monitor according to the same scheme it’s sent to the radio transmitter. Eg.

< A.x, A.y, A.z | G.x, G.y, G.z | M.x, M.y, Mz | AD.x, AD.y, AD.z >

The characters ‘<‘ and ‘>’ have ASCII values 60 and 62, which can be detected when parsing the data. If there is a loss of some of the data.

The way I wrote the above example assumes that the data from the MPU and the magnetometer board would transmit data in sync. There is no reason to believe this would be the case. What are the implications of this?

Priority III:
-Create a case to house the electronics. Power the circuit with a 5V LiPo battery and a basic Adafruit battery charger board.



#### 1.8.20

9 Axes of data are transmitted from the Teensy wirelessly using BATTS/Mobile_Station/Mobile_Station_V2/Mobile_Station_V2.ino. These are all being read via I2C from the MPU-9250 accelerometer/gyro/compass board. The format looks like `< A.x, A.y, A.z, G.x, G.y, G.z, M.x, M.y, Mz >`.

We are having trouble reading any data from the ground station. We were using code from [this guy's project](https://forum.arduino.cc/index.php?topic=307172.0).