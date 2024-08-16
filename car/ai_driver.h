#ifndef AI_DRIVER_H
#define AI_DRIVER_H
#include "motor.h"
#include "ir.h"
#include <Arduino.h>
#include <Servo.h>

class AI_Driver{
  private:
    Motor motor;
    IR r_sensor;
    IR c_sensor;
    IR l_sensor;
  public:
    AI_Driver(){}
    AI_Driver(Motor &motor, IR &r_sensor, IR &c_sensor, IR &l_sensor);
    AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor);
    void init(byte R_MOTOR_PIN, byte L_MOTOR_PIN);
    void forward(long speed);
    void backward(long speed);
    void turn_left();
    void turn_right();
    void update(long speed, long r_speed, long l_speed);
    void adjust_right(long r_speed, long l_speed);
    void adjust_left(long r_speed, long l_speed);
    void test();
};
#endif