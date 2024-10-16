#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// Define pins for the sensors
const int leftSensorPin = A0;
const int rightSensorPin = A1;

// Define threshold values for line detection
const int leftThreshold = 40;
const int rightThreshold = 40;

// Initialize LED Matrix
ArduinoLEDMatrix matrix;

// Create servo objects
Servo servo1;
Servo servo2;

// Variables to keep track of last known line position
bool lastLineOnLeft = false;

void setup() {
    servo1.attach(9, 700, 2300);
    servo2.attach(10, 700, 2300);

    // Initialize the LED matrix
    matrix.begin();
    matrix.textFont(Font_5x7);
    matrix.textScrollSpeed(100); // Adjust as necessary
    matrix.stroke(0xFF, 0, 0);   // Set color (e.g., red)

    // Initial stop to make sure servos are neutral
    servo1.writeMicroseconds(1505);
    servo2.writeMicroseconds(1505);
}

void loop() {
    int leftSensorValue = analogRead(leftSensorPin);
    int rightSensorValue = analogRead(rightSensorPin);

    // Check the sensor values against their respective thresholds
    if (leftSensorValue < leftThreshold && rightSensorValue < rightThreshold) {
        // Both sensors are on the line
        displayStatus('1');
    } else if (leftSensorValue >= leftThreshold && rightSensorValue >= rightThreshold) {
        // Both sensors are off the line
        displayStatus('0');
        // Swivel in the last known line direction
        if (lastLineOnLeft) {
            swivelRight();
        } else {
            swivelLeft();
        }
    } else if (leftSensorValue < leftThreshold) {
        // Left sensor detects line (too far right), swivel left
        displayStatus('L');
        swivelLeft();
        lastLineOnLeft = true;
    } else if (rightSensorValue < rightThreshold) {
        // Right sensor detects line (too far left), swivel right
        displayStatus('R');
        swivelRight();
        lastLineOnLeft = false;
    }
    delay(100); // Adjust delay as necessary for sensor readings
}

void swivelLeft() {
    servo1.writeMicroseconds(1525); // Reduced speed for left swivel
    servo2.writeMicroseconds(1505);
    delay(100);  // Maintain neutral position
}

void swivelRight() {
    servo1.writeMicroseconds(1505); // Maintain neutral position
    servo2.writeMicroseconds(1485);
    delay(100); // Reduced speed for right swivel
}

void displayStatus(char status) {
    matrix.beginText(0, 1, 0xFF, 0, 0); // Start position (adjust as necessary)
    matrix.print(status);               // Display the status character
    matrix.endText();
}



