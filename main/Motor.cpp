#include "Motor.h"

Motor::Motor(int pin, int neutral) : neutralPosition(neutral) {
    servo.attach(pin, 700, 2300);
}

void Motor::setSpeed(int speed) {
    servo.writeMicroseconds(speed);
}

void Motor::stop() {
    setSpeed(1505);
}
