#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor(int p) : pin(p) {}

LineSensor::LineSensor(int p, int thresh) : Sensor(p), threshold(thresh) {}

int LineSensor::readValue() {
    return analogRead(pin);
}

bool LineSensor::isOnLine() {
    return readValue() < threshold;
}
