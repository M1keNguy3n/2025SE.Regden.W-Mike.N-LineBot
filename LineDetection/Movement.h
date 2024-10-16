#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>
#include <Servo.h>

class Movement {
public:
    Movement(int servoPin1, int servoPin2);
    void init();
    void moveForward();
    void turnLeft();
    void turnRight();
    void stop();
private:
    Servo servo1;
    Servo servo2;
};

#endif
