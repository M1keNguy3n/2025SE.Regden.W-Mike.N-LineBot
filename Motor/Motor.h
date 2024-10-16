#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class Motor {
private:
    Servo servo1;    // Servo for the first motor
    Servo servo2;    // Servo for the second motor
    int pin1;        // Pin for the first servo
    int pin2;        // Pin for the second servo
    int minPulse;    // Minimum pulse width for full reverse
    int maxPulse;    // Maximum pulse width for full forward

public:
    // Constructor
    Motor(int servoPin1, int servoPin2, int minPulseWidth, int maxPulseWidth);

    // Initialization method
    void init();

    // Methods to control motor movement
    void turnLeft();
    void turnRight();
    void turnBackRight();
    void turnBackLeft();
    void stop();
};

#endif
