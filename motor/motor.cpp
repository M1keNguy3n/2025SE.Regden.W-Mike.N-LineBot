#include "motor.h"

Motor::Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
  this-> runtime = runtime;
}

void Motor::fast_forward(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(700);
    timeNow = millis();
  }
}

void Motor::fast_backward(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(2300);
    timeNow = millis();
  }
}

void Motor::stop_motor(){
  unsigned long timeNow = millis();
  unsigned long start = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    timeNow = millis();
  }
}

void Motor::turn_left(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < turn_90){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(700);
    timeNow = millis();
  }
}

void Motor::turn_right(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < turn_90){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(2300);
    timeNow = millis();
  }
}  

void Motor::test(){
  l_servo.writeMicroseconds(2300);
  r_servo.writeMicroseconds(700);
  delay(50);
}
