#include "motor.h"

Motor::Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
  this-> runtime = runtime;
}

void Motor::init(byte l_pin, byte r_pin){
  l_servo.attach(l_pin);
  r_servo.attach(r_pin);
}

void Motor::forward(int speed){
  //start timer
  unsigned long start = millis();
  unsigned long timeNow = millis();
  //assign speeds to each motor
  int l_speed = set_l_speed(speed);
  int r_speed = set_r_speed(speed);
  //moves forward until runtime ends.
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
    delay(10);
    timeNow = millis();
  }
}

void Motor::backward(int speed){
  //start timer
  unsigned long start = millis();
  unsigned long timeNow = millis();
  //the reverse speed is the same distance away from the midpoint as the forward speed
  int l_speed = abs(set_l_speed(speed)-1500) + 1500;
  int r_speed = abs(set_r_speed(speed)-1500) + 1500;
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
    delay(10);
    timeNow = millis();
  }
}

void Motor::stop_motor(){
  //stop both motors
  unsigned long timeNow = millis();
  unsigned long start = millis();
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    delay(10);
    timeNow = millis();
  }
}

void Motor::turn_left(){
  //turn 90 degress left
  unsigned long start = millis();
  unsigned long timeNow = millis();
  while (timeNow - start < turn_90){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(700);
    delay(50);
    timeNow = millis();
  }
}

void Motor::adjust_left(int r_speed, int l_speed){
  //slightly swivel to the left. intensity is specified using r_speed.
  unsigned long start = millis();
  unsigned long timeNow = millis();
  r_speed = set_r_speed(r_speed);
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
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
    delay(10);
    timeNow = millis();
  }
}  

void Motor::adjust_right(int r_speed, int l_speed){
  //slightly swivel to the right. intensity is specified using l_speed
  unsigned long start = millis();
  unsigned long timeNow = millis();
  l_speed = set_l_speed(l_speed);
  while (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(1500);
    delay(10);
    timeNow = millis();
  }
} 

void Motor::test(){
  unsigned long start = millis();
  unsigned long timeNow = millis();
  r_servo.writeMicroseconds(1500);
  l_servo.writeMicroseconds(1580);
  delay(1000);
  r_servo.writeMicroseconds(2300);
  l_servo.writeMicroseconds(1500);
  delay(500);
}

int Motor::set_r_speed(int percent){
  int val = 0;
  val = static_cast<int>(map(percent, 0, 100, 1500, 2300));
  return val;
}

int Motor::set_l_speed(int percent){
  int val = 0;
  val = static_cast<int>(map(percent, 0, 100, 1500, 700));
  return val;
}
