#ifndef AI_DRIVER_H
#define AI_DRIVER_H
#include "motor.h"
#include "ir.h"

class AI_Driver{
  private:
    Motor motor;
    IR r_sensor;
    IR c_sensor;
    IR l_sensor;
  public:
    AI_Driver(){};
    AI_Driver(Motor &motor, IR &r_sensor, IR &c_sensor, IR &l_sensor);
    AI_Driver(Motor &motor, IR &r_sensor, IR &l_sensor);
    void init();
    void forward();
    void backward();
    void turn_left();
    void turn_right();
    void update();
}
#endif