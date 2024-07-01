#include "motor.h"

Motor::Motor(Servo &servo){
  this-> servo = servo;
}

void Motor::init(Servo &servo){
  servo.attach(pin, min, max);
}

void Motor::fast_forward(){
  Motor.writeMicroseconds(max);
}

void Motor::fast_backward(){
  Motor.writeMicroseconds(min);
}

void Motor::stop(){
  Motor.writeMicroseconds(stop);
}

void Motor::slow_forward(){
  Motor.writeMicroseconds(stop + 200);
}

void Motor::slow_backward(){
  Motor.writeMicroseconds(stop - 200);
}

