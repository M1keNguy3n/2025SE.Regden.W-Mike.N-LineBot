#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

Servo servo1;
Servo servo2;

// Define pins for the sensors
const int leftSensorPin = A0;
const int rightSensorPin = A1;

// Define individual thresholds for each sensor
const int leftThreshold = 53;
const int rightThreshold = 44;

ArduinoLEDMatrix matrix;

// Track the last known position of the line
bool lastLineOnLeft = true;
bool lastLineOnRight = false;

void setup() {
    servo1.attach(5, 700, 2300);
    servo2.attach(6, 700, 2300);

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

    // Line detection logic using individual thresholds
    if (leftSensorValue >= leftThreshold && rightSensorValue >= rightThreshold) {
        // Off the line
        displayStatus('0');
        swivelToFindLine();
        lastLineOnRight = true;
    } else if (leftSensorValue < leftThreshold && rightSensorValue >= rightThreshold) {
        // Too far to the right, swivel left
        displayStatus('L');
        swivelLeft();
        lastLineOnLeft = true;
    } else if (leftSensorValue > leftThreshold && rightSensorValue <= rightThreshold) {
        // Too far to the left, swivel right
        displayStatus('L');
        swivelRight();
        lastLineOnRight = true;
    }  else if (leftSensorValue >= leftThreshold && rightSensorValue >= rightThreshold) {
        // Off the line
        displayStatus('0');
        swivelToFindLine();
        lastLineOnRight = true;
    } else if (leftSensorValue < leftThreshold && rightSensorValue < rightThreshold) {
        // Both sensors detect the line (sharp turn situation)
        handleSharpTurn();
    }
    delay(100);
}

void swivelLeft() {
    servo1.writeMicroseconds(1535); // Adjust as necessary for slower swivel
    servo2.writeMicroseconds(1505); // Neutral position
}

void swivelRight() {
    servo1.writeMicroseconds(1505); // Neutral position
    servo2.writeMicroseconds(1475); // Adjust as necessary for slower swivel
}

void swivelToFindLine() {
    // Determine which direction to swivel based on last known position
    if (lastLineOnLeft) {
        swivelRight();
    } else if (lastLineOnRight) {
        swivelLeft();
    }
}

void handleSharpTurn() {
    // Reverse slightly
    servo1.writeMicroseconds(700);  // Reverse left wheel
    servo2.writeMicroseconds(2300); // Reverse right wheel
    delay(1000); // Adjust the delay for appropriate reversing distance

    // Turn to get back on track
    if (lastLineOnLeft) {
        swivelRight(); // Swivel in the opposite direction of the last known line position
    } else {
        swivelLeft();
    }
    delay(1000);  // Adjust the delay for appropriate turning angle
}

void displayStatus(char status) {
    matrix.beginText(0, 1, 0xFF, 0, 0);
    matrix.print(status);
    matrix.endText();
}


