#include "ai_driver.h"
#include "motor.h"
#include "ir.h"

AI_Driver::AI_Driver(Motor &motor, IR &r_sensor, IR &c_sensor, IR &l_sensor){
  this -> motor = motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;
  this -> c_sensor = c_sensor;
}

AI_Driver::AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor){
  this -> motor = motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;  
}

void AI_Driver::init(byte R_MOTOR_PIN, byte L_MOTOR_PIN){
  motor.init(L_MOTOR_PIN, R_MOTOR_PIN);
  r_sensor.init();
  l_sensor.init();
}

void AI_Driver::turn_left(){
  if (!(l_sensor.l_lineDetected()) || (r_sensor.r_lineDetected())){
      motor.turn_left();
    }
}

void AI_Driver::turn_right(){
  if (!(r_sensor.r_lineDetected()) || (l_sensor.l_lineDetected())){
      motor.turn_right();
    }
}

void AI_Driver::adjust_right(long r_speed, long l_speed){
  motor.adjust_left(r_speed, l_speed);
}

void AI_Driver::adjust_left(long r_speed, long l_speed){
  motor.adjust_left(r_speed, l_speed);
}

void AI_Driver::update(long speed, long r_speed, long l_speed){
  
  if (!(r_sensor.r_lineDetected()) && (!(l_sensor.l_lineDetected()))){
    motor.forward(speed);
  }
  if (!(r_sensor.r_lineDetected()) && (l_sensor.l_lineDetected())){
    motor.adjust_right(r_speed, l_speed);
  }
  if (!(l_sensor.l_lineDetected()) && (r_sensor.r_lineDetected())){
    motor.adjust_left(r_speed, l_speed);
  }
  if (r_sensor.r_lineDetected() && l_sensor.l_lineDetected()){
    motor.backward(speed);
  }
}