# BATTS
Ballistic Acquisition Telemetry and Trajectory System using an Arduino to report telemetry from a self-contained device such as a drone to a fixed ground station.


Questions:
* How should each axis of data be mapped?
* What communication protocol is each component of the project using?
* How will the data be collected from the Arduino?
* How does the Beitan GPS work? How do we print data from it to the serial monitor repeatedly?
* How does the Serial*.available() function work?
* How many devices can the Mega handle?
* At what baud rate is the data optimally received at from each device?
* What have we learned so far?
* If we were to receive data from the computer, how would it be graphed?


Planning:
*	What sensors are being used with the Teensy?
	*	MPU9250 Board
	*	[ADXL345 Board](https://learn.sparkfun.com/tutorials/adxl345-hookup-guide/all). [Datasheet for the IC](https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf?_ga=2.189572520.200845294.1578683318-1747185889.1578374771). [Listing for the board we used](https://ns-electric.com/product/9-dof-imu-mpu9250/).


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


#### Relevant Links:
*	[Wireless communication between two Arduinos using clone 3DR radios](https://forum.arduino.cc/index.php?topic=307172.0)
*	[CP2014 USB-UART Bridge Datasheet](https://www.silabs.com/documents/public/data-sheets/cp2104.pdf): this chip is used on the USB-UART board we were given. If we were to design a PCB to connect the 3DR USB radio receiver to the Arduino, we would make through-hole connections to pins 20 and 21 (RXD and TXD).
*	Arduino Library [Wire.h](https://www.arduino.cc/en/reference/wire)
*	[Teensyduino Installation](https://www.pjrc.com/teensy/td_download.html)
*	[MPU9250 Library](https://github.com/bolderflight/MPU9250) (uses FIFO scheme) [MPU-9250 Datasheet](https://www.invensense.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf)
*	Another [MPU9250 Library](https://github.com/kriswiner/MPU9250)
*	[Serial inputs on Arduino](https://www.norwegiancreations.com/2017/12/arduino-tutorial-serial-inputs/)
*	[Serial.available()](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/)
*	[USB Device send/read data](https://forum.arduino.cc/index.php?topic=16202.0)
*	[TinyGPSPlus](https://github.com/mikalhart/TinyGPSPlus): we used this library for the bn-
*	[Adding External Memory to Arduino](https://forum.arduino.cc/index.php?topic=345952.0): according to a commenter on this post, using a [shield](https://www.adafruit.com/product/1141) or [breakout board](https://www.adafruit.com/product/254) (the latter uses SPI) one should be able to use a micro SD card with up to 16gb storage. We would be transmitting at least 12 [float](https://www.arduino.cc/en/pmwiki.php?n=Reference/Float) values for each transmission. The Atmega we used has ~248k of onboard [memory](https://www.arduino.cc/en/tutorial/memory).
*	[BN-88 GPS Module Pinout](https://cdn.shopify.com/s/files/1/1285/4651/products/s-l640_9d7cee7c-f599-4ef6-b081-2cc15839a830_473x473.jpg?v=1553448331)
*	[Using the ADXL345 Accelerometer Board with an Arduino](https://howtomechatronics.com/tutorials/arduino/how-to-track-orientation-with-arduino-and-adxl345-accelerometer/)


#### Misc. Links:
*	https://forum.arduino.cc/index.php?topic=275468.0
*	[Problem with using SoftwareSerial.h to write data from the BN-88 to the serial monitor](https://forum.arduino.cc/index.php?topic=423462.0)
*	[ADXL345 SPI](https://gist.github.com/hamaluik/b1903a8353dc1ec57da8)
*	[Arduino Mega with 3DR Radio](https://forum.arduino.cc/index.php?topic=339382.0)
*	[Read String from external device](https://forum.arduino.cc/index.php?topic=509104.0)
*	[Passing data from a GPS module to a bluetooth module via UART on a Teensy](https://forum.pjrc.com/threads/26549-GPS-UART-Passing-NMEA-strings-to-RX3-TX3)


#### 1.8.20

9 Axes of data are transmitted from the Teensy wirelessly using BATTS/Mobile_Station/Mobile_Station_V2/Mobile_Station_V2.ino. These are all being read via I2C from the MPU-9250 accelerometer/gyro/compass board. The format looks like `< A.x, A.y, A.z, G.x, G.y, G.z, M.x, M.y, Mz >`.

We are having trouble reading any data from the ground station. We were using code from [this guy's project](https://forum.arduino.cc/index.php?topic=307172.0).


#### 1.10.20

We discovered that the reason the arduino didn't appear to be receiving any data may have been because we were using two USB slave devices and USB slave devices cannot transmit or receive data. There is a protocol variant called USB OTG that would solve this problem. Or we could connect the ground station antenna to a raspberry pi and read data from the D+ D- line that way.

Alternatively, [this](https://www.amazon.com/FPVDrone-915MHZ-Telemetry-Pixhawk-Controller/dp/B081RMGJYX/ref=sr_1_5?keywords=3dr+radio&qid=1578546033&sr=8-5) or [this](https://www.ebay.com/itm/3DR-Radio-915MHZ-Telemetry-Kit-100mW-for-Standard-APM2-8-APM-2-6-Pixhawk-2-4-6/262884583832?hash=item3d35246998:g:RZcAAOSwuxFYvpdR&autorefresh=true) variant of the 3DR Radio Telemetry set would work as it supports USB OTG. The designer could also use the supplied Tx and Rx lines supplied on both parts of the radio Telemetry pair.