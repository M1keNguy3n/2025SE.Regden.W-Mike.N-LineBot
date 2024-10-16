#include "LineDetection.h"
#include <Arduino.h>

LineDetection::LineDetection(int leftPin, int rightPin)
    : leftSensorPin(leftPin), rightSensorPin(rightPin) {}

void LineDetection::init() {
    pinMode(leftSensorPin, INPUT);
    pinMode(rightSensorPin, INPUT);
}

int LineDetection::detectLine() {
    int leftValue = analogRead(leftSensorPin);
    int rightValue = analogRead(rightSensorPin);

    int threshold = 44;

    bool leftOnLine = (leftValue < threshold);
    bool rightOnLine = (rightValue < threshold);

    if (leftOnLine && !rightOnLine) {
        return -1; // Too far right
    } else if (!leftOnLine && rightOnLine) {
        return 1; // Too far left
    } else if (leftOnLine && rightOnLine) {
        return 0; // On the line
    } else {
        return 2; // Off the line
    }
}
