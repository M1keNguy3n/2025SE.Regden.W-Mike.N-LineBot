#include "motor.h"

Motor::Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
  LastTimeRan = millis();
  this-> runtime = runtime;
}

void Motor::fast_forward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(700);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::fast_backward(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(2300);
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
  servo.write(100);
  delay(50);
}
