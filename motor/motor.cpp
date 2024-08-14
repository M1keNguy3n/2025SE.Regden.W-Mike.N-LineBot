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

void Motor::forward(long speed){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  long l_speed = set_l_speed(speed);
  long r_speed = set_r_speed(speed);
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
    delay(10);
    timeNow = millis();
  }
}

void Motor::backward(long speed){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  long l_speed = abs(set_l_speed(speed)-1500) + 1500;
  long r_speed = abs(set_l_speed(speed)-1500) + 1500;
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_max_counterclockwise);
    r_servo.writeMicroseconds(r_max_counterclockwise);
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

void Motor::adjust_left(long r_speed, long l_speed){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
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

void Motor::adjust_right(long r_speed, long l_speed){
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
  r_servo.writeMicroseconds(1500);
  l_servo.writeMicroseconds(2300);
  delay(1000);
  r_servo.writeMicroseconds(2300);
  l_servo.writeMicroseconds(1500);
  delay(500);
}

long Motor::set_r_speed(long percent){
  return map(percent, 0, 100, 1500, 700);
}

long Motor::set_l_speed(long percent){
  return map(percent, 0, 100, 1500, 2300);
}
