#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

//Creating motor shield object with default I2C address
//Can use different I2C address- say for stacking by putting (0x61) inside ()
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

//Select port (M1, M2, M3, M4- (1) means M1)
//Can 3 other motors to control
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

//Setup code will run once
void setup() {
  
  AFMS.begin(); 
  //sets up frequency, default is 1.6 kHz, to change put (1000)

}

// put your main code here, to run repeatedly:
void loop() {
  
//Set speed 0 (off) - 255 (max)
//Commands are FORWARD, BACKWARD, RELEASE
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  delay (2000); 
  

 myMotor->setSpeed(150);
  myMotor->run(BACKWARD);
  delay (2000);
  

}

