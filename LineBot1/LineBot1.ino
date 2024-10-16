#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

Servo servo1;
Servo servo2;

// Define pins for the sensors
const int leftSensorPin = A3;
const int rightSensorPin = A1;

// Define threshold for line detection
const int threshold = 43;

// Initialize LED Matrix
ArduinoLEDMatrix matrix;

// Variables to keep track of last known line position
bool lastLineOnLeft = false;

void setup() {
    servo1.attach(3, 700, 2300);
    servo2.attach(4, 700, 2300);

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

    // Check the sensor values against the threshold
    if (leftSensorValue < threshold && rightSensorValue < threshold) {
        // On the line
        displayStatus('1');
    } else if (leftSensorValue >= threshold && rightSensorValue >= threshold) {
        // Off the line
        displayStatus('0');
        // Swivel in the last known line direction
        if (lastLineOnLeft) {
            swivelRight();
        } else {
            swivelLeft();
        }
    } else if (leftSensorValue < threshold) {
        // Too far to the right, swivel left
        displayStatus('L');
        swivelLeft();
        lastLineOnLeft = true;
    } else if (rightSensorValue < threshold) {
        // Too far to the left, swivel right
        displayStatus('R');
        swivelRight();
        lastLineOnLeft = false;
    }
    delay(45); // Adjust delay as necessary for sensor readings
}

void swivelLeft() {
    servo1.writeMicroseconds(1520); // Reduced speed for left swivel
    servo2.writeMicroseconds(1505);
}

void swivelRight() {
    servo1.writeMicroseconds(1505); // Maintain neutral position
    servo2.writeMicroseconds(1490);
}

void displayStatus(char status) {
    matrix.beginText(0, 1, 0xFF, 0, 0); // Start position (adjust as necessary)
    matrix.print(status);               // Display the status character
    matrix.endText();
}


