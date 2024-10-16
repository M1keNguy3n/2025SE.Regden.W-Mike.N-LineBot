#include "Robot.h"

Robot::Robot(int leftSensorPin, int rightSensorPin, int leftThreshold, int rightThreshold, int leftMotorPin, int rightMotorPin)
    : leftSensor(leftSensorPin, leftThreshold),
      rightSensor(rightSensorPin, rightThreshold),
      leftMotor(leftMotorPin, 1505),
      rightMotor(rightMotorPin, 1505),
      lastLineOnLeft(true) {}

void Robot::update() {
    if (leftSensor.isOnLine() && rightSensor.isOnLine()) {
        handleSharpTurn();
    } else if (leftSensor.isOnLine() && !rightSensor.isOnLine()) {
        display.showStatus('L');
        swivelLeft();
        lastLineOnLeft = true;
    } else if (!leftSensor.isOnLine() && rightSensor.isOnLine()) {
        display.showStatus('R');
        swivelRight();
        lastLineOnLeft = false;
    } else if (!leftSensor.isOnLine() && !rightSensor.isOnLine()) {
        display.showStatus('0');
        swivelToFindLine();
    } else {
        display.showStatus('1');
    }
}

void Robot::swivelLeft() {
    leftMotor.setSpeed(1535);
    rightMotor.stop();
}

void Robot::swivelRight() {
    leftMotor.stop();
    rightMotor.setSpeed(1475);
}

void Robot::swivelToFindLine() {
    if (lastLineOnLeft) {
        swivelRight();
    } else {
        swivelLeft();
    }
}

void Robot::handleSharpTurn() {
    reverse();
    if (lastLineOnLeft) {
        swivelRight();
    } else {
        swivelLeft();
    }
}

void Robot::reverse() {
    leftMotor.setSpeed(1470);
    rightMotor.setSpeed(1540);
    delay(100);  // Reverse for 0.1 second
    leftMotor.stop();
    rightMotor.stop();
}
