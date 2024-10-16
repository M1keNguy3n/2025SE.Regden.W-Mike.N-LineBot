#include "Movement.h"


Movement::Movement(int servoPin1, int servoPin2) {
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
}


void Movement::init() {
  servo1.attach(5);
  servo2.attach(6);
    // Initialization code if needed
}


void Movement::moveForward() {
    servo1.writeMicroseconds(2300);
    servo2.writeMicroseconds(700);
}


void Movement::turnLeft() {
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(2300);
}


void Movement::turnRight() {
    servo1.writeMicroseconds(2300);
    servo2.writeMicroseconds(1500);
}


void Movement::stop() {
    servo1.writeMicroseconds(1500); // Neutral position
    servo2.writeMicroseconds(1500); // Neutral position
}


