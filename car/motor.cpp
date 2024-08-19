#include "motor.h"

Motor::Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime){
  this-> r_servo = r_servo;
  this-> l_servo = l_servo;
  this-> runtime = runtime;
}

void Motor::init(byte l_pin, byte r_pin){
  l_servo.attach(l_pin, 700, 2300);
  r_servo.attach(r_pin, 700, 2300);
}

void Motor::forward(){
  //start timer
  unsigned long start = millis();
  unsigned long timeNow = millis();
  //assign speeds to each motor
  int l_speed = set_l_speed(15);
  int r_speed = set_r_speed(10);
  //moves forward until runtime ends.
  if (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
    delay(100);
    timeNow = millis();
  }
}

void Motor::backward(){
  //start timer
  unsigned long start = millis();
  unsigned long timeNow = millis();
  //the reverse speed is the same distance away from the midpoint as the forward speed
  int l_speed = abs(set_l_speed(15)-1500)+1500;
  int r_speed = abs(set_r_speed(15)-1500)+1500;
  if (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(r_speed);
    delay(100);
    timeNow = millis();
  }
}

void Motor::stop_motor(){
  //stop both motors
  unsigned long timeNow = millis();
  unsigned long start = millis();
  if (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(1500);
    delay(100);
    timeNow = millis();
  }
}

void Motor::turn_left(){
  //turn 90 degress left
  unsigned long start = millis();
  unsigned long timeNow = millis();
  if (timeNow - start < turn_90){
    l_servo.writeMicroseconds(700);
    r_servo.writeMicroseconds(700);
    delay(100);
    timeNow = millis();
  }
}

void Motor::adjust_left(int r_speed){
  //slightly swivel to the left. intensity is specified using r_speed.
  unsigned long start = millis();
  unsigned long timeNow = millis();
  r_speed = set_r_speed(r_speed);
  if (timeNow - start < runtime){
    l_servo.writeMicroseconds(1500);
    r_servo.writeMicroseconds(r_speed);
    delay(100);
    timeNow = millis();
  }
}

void Motor::turn_right(){
  //turn 90 degress right
  unsigned long start = millis();
  unsigned long timeNow = millis();
  if (timeNow - start < turn_90){
    l_servo.writeMicroseconds(2300);
    r_servo.writeMicroseconds(2300);
    delay(100);
    timeNow = millis();
  }
}  

void Motor::adjust_right(int l_speed){
  //slightly swivel to the right. intensity is specified using l_speed
  unsigned long start = millis();
  unsigned long timeNow = millis();
  l_speed = set_l_speed(l_speed);
  if (timeNow - start < runtime){
    l_servo.writeMicroseconds(l_speed);
    r_servo.writeMicroseconds(1500);
    delay(100);
    timeNow = millis();
  }
} 



int Motor::set_r_speed(int percent){
  //set speed for the right motor
  int val = 0;
  val = static_cast<int>(map(percent, 0, 100, 1500, 700));
  return val;
}

int Motor::set_l_speed(int percent){
  //set speed for the left motor
  int val = 0;
  val = static_cast<int>(map(percent, 0, 100, 1500, 2300));
  return val;
}

void Motor::test(){
  Serial.println("Test running.");
  int l_speed = set_l_speed(15);
  int r_speed = set_r_speed(10);
  l_servo.writeMicroseconds(l_speed);
  r_servo.writeMicroseconds(r_speed);
  delay(100);
}
