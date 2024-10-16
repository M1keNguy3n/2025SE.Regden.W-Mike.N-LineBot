#include "Sensor.h"

// Constructor
Sensor::Sensor(int sensorPin, int sensorThreshold) {
    pin = sensorPin;
    threshold = sensorThreshold;
}

// Method to check if the sensor is detecting the line
bool Sensor::isOnLine() {
    int sensorValue = analogRead(pin);
    return (sensorValue > threshold);
}

// Method to get the raw sensor value
int Sensor::readValue() {
    return analogRead(pin);
}
