#include "LineDetection.h" 
#include <Arduino.h> 
 
LineDetection::LineDetection(int leftPin, int rightPin) : leftSensorPin(leftPin), rightSensorPin(rightPin) {} 
 
void LineDetection::init() { 
    pinMode(leftSensorPin, INPUT); 
    pinMode(rightSensorPin, INPUT); 
} 
 
int LineDetection::readLeftSensor() { 
    return digitalRead(leftSensorPin); 
} 
 
int LineDetection::readRightSensor() { 
    return digitalRead(rightSensorPin); 
} 
 
int LineDetection::readLeftAnalog() { 
    return analogRead(leftSensorPin); 
} 
 
int LineDetection::readRightAnalog() { 
    return analogRead(rightSensorPin); 
} 
 