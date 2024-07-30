#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <Servo.h>
class Motor{
  private:
    Servo servo;
    unsigned long LastTimeRan;
    unsigned long runtime;
    const int max = 2300;
    const int min = 700;
    const int stop = 1500;
  public:
    Motor(){}
    Motor(Servo &servo, unsigned long runtime);
    void stop_motor();
    void fast_forward();
    void fast_backward();
    void slow_forward();
    void slow_backward();
    void test();
};
#endif