#include "Sensor.h"

// Initialize sensors with their respective pins and thresholds
Sensor leftSensor(A3, 46);
Sensor rightSensor(A1, 46);

void setup() {
    Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
    // Check and print the status of the left sensor
    if (leftSensor.isOnLine()) {
        Serial.println("Left sensor is on the line!");
    } else {
        Serial.println("Left sensor is off the line!");
    }

    // Check and print the status of the right sensor
    if (rightSensor.isOnLine()) {
        Serial.println("Right sensor is on the line!");
    } else {
        Serial.println("Right sensor is off the line!");
    }

    delay(500); // Adjust delay as needed
}
