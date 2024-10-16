#ifndef MOTOR_H
#define MOTOR_H

#include <Servo.h>

class Motor {
private:
    Servo servo;
    int neutralPosition;

public:
    Motor(int pin, int neutral);
    void setSpeed(int speed);
    void stop();
};

#endif

