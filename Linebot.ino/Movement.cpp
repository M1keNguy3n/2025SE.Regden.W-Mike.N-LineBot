#include "Movement.h" 
#include <arduino.h>
 
Movement::Movement(int pin1, int pin2) { 
    servo1.attach(pin1); 
    servo2.attach(pin2); 
} 
 
void Movement::init() { 
    // Additional initialization if needed 
} 
 
void Movement::moveForward(int speed, int duration) { 
    servo1.writeMicroseconds(speed); 
    servo2.writeMicroseconds(speed); 
    delay(duration); 
    stop(); 
} 
 
void Movement::turnRight(int speed, int duration) { 
    servo1.writeMicroseconds(speed); 
    servo2.writeMicroseconds(2300); // Adjust to turn right 
    delay(duration); 
    stop(); 
} 
 
void Movement::turnLeft(int speed, int duration) { 
    servo1.writeMicroseconds(2300); // Adjust to turn left 
    servo2.writeMicroseconds(speed); 
    delay(duration); 
    stop(); 
} 
 
void Movement::stop() { 
    servo1.writeMicroseconds(1500); // Neutral position 
    servo2.writeMicroseconds(1500); // Neutral position 
} 
 