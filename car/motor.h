#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <Servo.h>
class Motor{
  private:
    Servo servo;
    const max = 2300;
    const min = 700;
    const stop = 1500;
  public:
    Motor(){}
    Motor(Servo &servo);
    void initServo();
    void stop();
    void fast_forward();
    void fast_backward();
    void slow_forward();
    void slow_backward();

};
#endif