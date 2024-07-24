#include "ai_driver.h"

AI_Driver::AI_Driver(Motor &l_motor, Motor &r_motor, IR &r_sensor, IR &c_sensor, IR &l_sensor){
  this -> l_motor = l_motor;
  this -> r_motor = r_motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;
  this -> c_sensor = c_sensor;
}

AI_Driver::AI_Driver(Motor &l_motor, Motor &r_motor, IR &r_sensor, IR &l_sensor){
  this -> l_motor = l_motor;
  this -> r_motor = r_motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;  
}

void AI_Driver::init(R_MOTOR_PIN, L_MOTOR_PIN){
  r_motor.attach(R_MOTOR_PIN);
  l_motor.attach(L_MOTOR_PIN);
  r_sensor.init();
  l_sensor.init();
}

void AI_Driver::forward(){
  if (!(r_sensor.readStateDigital()) && (!(l_sensor.readStateDigital))){
    l_motor.fast_forward();
    r_motor.fast_forward();
  }
}

void AI_Driver::backward(){
  l_motor.fast_backward();
  r_motor.fast_backward();
}

void AI_Driver::turn_left(){
  if (!(l_sensor.readStateDigital()) || (r_sensor.readStateDigital)){
      l_motor.slow_forward();
      r_motor.fast_forward();
    }
}

void AI_Driver::turn_right(){
  if (!(r_sensor.readStateDigital()) || (l_sensor.readStateDigital)){
      l_motor.fast_forward();
      r_motor.slow_forward();
    }
}