#ifndef ROBOT_H
#define ROBOT_H

#include "Sensor.h"
#include "Motor.h"
#include "Display.h"

class Robot {
private:
    LineSensor leftSensor;
    LineSensor rightSensor;
    Motor leftMotor;
    Motor rightMotor;
    Display display;
    bool lastLineOnLeft;

public:
    Robot(int leftSensorPin, int rightSensorPin, int leftThreshold, int rightThreshold, int leftMotorPin, int rightMotorPin);
    void update();

    Motor& getLeftMotor() { return leftMotor; }
    Motor& getRightMotor() { return rightMotor; }
    Display& getDisplay() { return display; }

private:
    void swivelLeft();
    void swivelRight();
    void swivelToFindLine();
    void handleSharpTurn();
    void reverse();
};

#endif
