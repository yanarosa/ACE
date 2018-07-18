/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. 
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1); //In this case, M1
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
Adafruit_DCMotor *LbackMotor = AFMS.getMotor(3);
Adafruit_DCMotor *RbackMotor = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

//What does this function do?
void setup() {

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(255);
  rightMotor->setSpeed(255);
  LbackMotor->setSpeed(255);
  RbackMotor->setSpeed(255);
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  LbackMotor->run(FORWARD);
  RbackMotor->run(FORWARD);
  
  // turn on motor
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  LbackMotor->run(RELEASE);
  RbackMotor->run(RELEASE);
}

//Why is there a loop here if the speed has been set to 255 already?

void loop() {
  uint8_t i;
  

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  LbackMotor->run(FORWARD);
  RbackMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    leftMotor->setSpeed(i);
    rightMotor->setSpeed(i);  
    LbackMotor->setSpeed(i);
    RbackMotor->setSpeed(i);
    delay(10);
    
  }
  
 
  
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  LbackMotor->run(RELEASE);
  RbackMotor->run(RELEASE);
    delay(1000);


  rightMotor->run(FORWARD);
  RbackMotor->run(FORWARD);
    for (i=0; i<150; i++) {
    rightMotor->setSpeed(i); 
    RbackMotor->setSpeed(i);
    delay(10);
  }
  for (i=150; i!=0; i--) {
    rightMotor->setSpeed(i);
    RbackMotor->setSpeed(i);
    delay(10);
  }
  

    leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  LbackMotor->run(FORWARD);
  RbackMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    leftMotor->setSpeed(i);
    rightMotor->setSpeed(i);  
    LbackMotor->setSpeed(i);
    RbackMotor->setSpeed(i);
    delay(10);
    
  }
  for (i=255; i!=0; i--) {
    leftMotor->setSpeed(i);
    rightMotor->setSpeed(i);  
    LbackMotor->setSpeed(i);
    RbackMotor->setSpeed(i);  
    delay(10);
  }
  
rightMotor->run(FORWARD);
RbackMotor->run(FORWARD);
    for (i=0; i<150; i++) {
    rightMotor->setSpeed(i);
    RbackMotor->setSpeed(i); 
    delay(10);
  }
  for (i=150; i!=0; i--) {
    rightMotor->setSpeed(i);
    RbackMotor->setSpeed(i);
    delay(10);
  }
 

    
 
  
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  LbackMotor->run(RELEASE);
  RbackMotor->run(RELEASE);
    delay(1000);

}
