#ifndef MOVEMENT_H 
#define MOVEMENT_H 
 
#include <Servo.h> 
 
class Movement { 
private: 
    Servo servo1; 
    Servo servo2; 
 
public: 
    Movement(int pin1, int pin2); 
    void init(); 
    void moveForward(int speed, int duration); 
    void turnRight(int speed, int duration); 
    void turnLeft(int speed, int duration); 
    void stop(); 
}; 
 
#endif