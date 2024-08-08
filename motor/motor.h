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
    Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime);
    void stop_motor();
    void fast_forward();
    void fast_backward();
    void turn_left();
    void turn_right();
    void test();
};
#endif