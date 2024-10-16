#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
private:
    int pin;           // Analog pin for the sensor
    int threshold;     // Threshold value for detecting the line

public:
    // Constructor
    Sensor(int sensorPin, int sensorThreshold);

    // Method to check if the sensor is detecting the line
    bool isOnLine();

    // Method to get the raw sensor value
    int readValue();
};

#endif
