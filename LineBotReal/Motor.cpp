#include "Motor.h"

// Constructor
Motor::Motor(int servoPin1, int servoPin2, int minPulseWidth, int maxPulseWidth) 
    : pin1(servoPin1), pin2(servoPin2), minPulse(minPulseWidth), maxPulse(maxPulseWidth) {}

// Initialization method
void Motor::init() {
    servo1.attach(pin1, minPulse, maxPulse);
    servo2.attach(pin2, minPulse, maxPulse);
}


// Turn left
void Motor::turnLeft() {
    servo1.writeMicroseconds(1505);  // Stop left motor
    servo2.writeMicroseconds(1470);  // forward right motor
}

// Turn right
void Motor::turnRight() {
    servo1.writeMicroseconds(1530);  // forward left motor
    servo2.writeMicroseconds(1505);  // Stop right motor
}

void Motor::turnBackLeft() {
    servo1.writeMicroseconds(1505);  // Stop left motor
    servo2.writeMicroseconds(1530);  // back right motor
}

// Turn right
void Motor::turnBackRight() {
    servo1.writeMicroseconds(1470);  // back left motor
    servo2.writeMicroseconds(1505);  // Stop right motor
}

// Stop
void Motor::stop() {
    servo1.writeMicroseconds(1505);  // Neutral position
    servo2.writeMicroseconds(1505);  // Neutral position
}
