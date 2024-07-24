#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <Servo.h>
class Motor{
  private:
    Servo &servo;
    const int max = 2300;
    const int min = 700;
    const int stop = 1500;
  public:
    Motor(){}
    Motor(Servo &servo);
    void stop_motor();
    void fast_forward();
    void fast_backward();
    void slow_forward();
    void slow_backward();
};
#endif