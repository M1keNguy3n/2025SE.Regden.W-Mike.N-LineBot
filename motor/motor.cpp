#include "motor.h"

Motor::Motor(Servo &servo, unsigned long runtime){
  this-> servo = servo;
  LastTimeRan = millis();
  this-> runtime = runtime;
}

void Motor::fast_forward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    servo.writeMicroseconds(max);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::fast_backward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    servo.writeMicroseconds(min);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::stop_motor(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    servo.writeMicroseconds(stop);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::slow_forward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    servo.writeMicroseconds(stop + 200);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::slow_backward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    servo.writeMicroseconds(stop - 200);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::test(){
  servo.writeMicroseconds(min);
  delay(50);
}
