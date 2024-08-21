#ifndef AI_DRIVER_H
#define AI_DRIVER_H
#include "motor.h"
#include "ir.h"
#include "ultrasonic.h"
#include "led_array.h"
#include <Arduino.h>
#include <Servo.h>

class AI_Driver: public Motor, public IR{
  private:
    Motor motor;
    IR r_sensor;
    IR l_sensor;
    Ultrasonic ultrasonic;
    LedMatrix array;
  public:
    AI_Driver(){}
    AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor, LedMatrix &array);
    AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor, Ultrasonic &ultrasonic);
    AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor);
    void init(byte L_MOTOR_PIN, byte R_MOTOR_PIN);
    void update(long r_speed, long l_speed);
    virtual void test();
};
#endif