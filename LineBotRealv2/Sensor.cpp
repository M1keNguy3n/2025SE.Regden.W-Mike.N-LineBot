#include "Sensor.h"

// Constructor
Sensor::Sensor(int sensorPin, int sensorThreshold) {
    this->pin = sensorPin;
    this->threshold = sensorThreshold;
}

// Method to get the raw sensor value
int Sensor::readValue() {
    return analogRead(pin);
}

// Method to check if the sensor is detecting the line
bool Sensor::isOnLine() {
    return (analogRead(pin) <= threshold);
}
