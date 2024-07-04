#include "motor.h"

Motor::Motor(Servo &servo){
  this-> servo = servo;
}

void Motor::fast_forward(){
  servo.writeMicroseconds(max);
}

void Motor::fast_backward(){
  servo.writeMicroseconds(min);
}

void Motor::stop_motor(){
  servo.writeMicroseconds(stop);
}

void Motor::slow_forward(){
  servo.writeMicroseconds(stop + 200);
}

void Motor::slow_backward(){
  servo.writeMicroseconds(stop - 200);
}

