#include "motor.h"

Motor::Motor(Servo &l_servo, Servo &r_servo){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
}

Motor::Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
  this-> runtime = runtime;
}

void Motor::init(byte l_pin, byte r_pin){
  l_servo.attach(l_pin);
  r_servo.attach(r_pin);
}

void Motor::fast_forward(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1900);
    r_servo.writeMicroseconds(1100);
    delay(50);
    timeNow = millis();
  }
}

void Motor::fast_backward(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(2300);
    delay(50);
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
    delay(50);
    timeNow = millis();
  }
}

void Motor::adjust_left(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    delay(50);
    timeNow = millis();
  }
}

void Motor::turn_right(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < turn_90){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(2300);
    delay(50);
    timeNow = millis();
  }
}  

void Motor::adjust_right(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    delay(50);
    timeNow = millis();
  }
} 

void Motor::test(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < 1000){
    l_servo.writeMicroseconds(850);
    delay(50);
    timeNow = millis();
  }
  l_servo.writeMicroseconds(950);
  delay(2000);
}
