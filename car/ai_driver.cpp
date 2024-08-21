#include "ai_driver.h"

AI_Driver::AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor, LedMatrix &array){
  //with LED array
  this -> motor = motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;

  this -> ultrasonic = ultrasonic;
  this -> array = array;
}

AI_Driver::AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor, Ultrasonic &ultrasonic){
  //with ultrasonic
  this -> motor = motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;
  this -> ultrasonic = ultrasonic;
}

AI_Driver::AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor){
  //most simple, 3 components
  this -> motor = motor;
  this -> r_sensor = r_sensor;
  this -> l_sensor = l_sensor;  
}

void AI_Driver::init(byte L_MOTOR_PIN, byte R_MOTOR_PIN){
  //initializes the motor and sensors.
  motor.init(L_MOTOR_PIN, R_MOTOR_PIN);
  r_sensor.init();
  l_sensor.init();
}

void AI_Driver::update(long r_speed, long l_speed){
  //main loop
  byte r_state = r_sensor.r_lineDetected();
  byte l_state = l_sensor.l_lineDetected();
  array.display_text(l_state);
  array.display_text(r_state);
  
  if (!(r_sensor.r_lineDetected()) && (!(l_sensor.l_lineDetected()))){
    motor.forward();
  }
  else if (!(r_sensor.r_lineDetected()) && (l_sensor.l_lineDetected())){
    motor.stop_motor();
    motor.adjust_right(l_speed);
  }
  else if (!(l_sensor.l_lineDetected()) && (r_sensor.r_lineDetected())){
    motor.stop_motor();
    motor.adjust_left(r_speed);
  }
  else if (r_sensor.r_lineDetected() && l_sensor.l_lineDetected()){
    motor.backward();
  }
}

void AI_Driver::test(){
  //testing OOP
  Serial.println("Test running.");
  motor.test();
}