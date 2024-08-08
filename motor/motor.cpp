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
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::turn_left(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    l_servo.writeMicroseconds(2100);
    r_servo.writeMicroseconds(700);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::turn_right(){
  unsigned long timeNow = millis();
  while (timeNow - LastTimeRan < runtime){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(900);
    timeNow = millis();
  }
  LastTimeRan = timeNow;
}

void Motor::test(){
  l_servo.writeMicroseconds(2300);
  r_servo.writeMicroseconds(900);
  delay(50);
}
