#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <Servo.h>
class Motor{
  private:
    Servo l_servo;
    Servo r_servo;
    byte l_pin;
    byte r_pin;
    const int l_stop = 1500;
    const int l_fast_clockwise = 2300;
    const int l_fast_counterclockwise = 700;
    const int turn_90 = 520;
    const int r_stop = 1500;
    const int r_fast_clockwise = 700;
    const int r_fast_counterclockwise = 2300;
    unsigned long runtime;
  public:
    Motor(){}
    Motor(Servo &l_servo, Servo &r_servo);
    Motor(Servo &l_servo, Servo &r_servo, unsigned long runtime);
    void init(byte l_pin, byte r_pin);
    void stop_motor();
    void fast_forward();
    void fast_backward();
    void turn_left();
    void turn_right();
    void test();
    void adjust_left();
    void adjust_right();
};

#endif