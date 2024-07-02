#ifndef AI_DRIVER_H
#define AI_DRIVER_H
#include "motor.h"
#include "ir.h"
class AI_Driver{
  private:
  Motor l_motor;
  Motor r_motor;
  IR r_sensor;
  IR c_sensor;
  IR l_sensor;
  PIR pir_sensor;
  public:
  AI_Driver(){};
  AI_Driver(Motor &l_motor, Motor &r_motor, IR &r_sensor, IR &c_sensor, IR &l_sensor);
  AI_Driver(Motor &l_motor, Motor &r_motor, IR &r_sensor, IR &l_sensor);
  void init();
  void forward();
  void backward();
  void turn_left();
  void turn_right();
}
#endif