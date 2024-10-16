#include "Sensor.h"
#include "Motor.h"
#include "Display.h"

// Initialize sensors with their respective pins and thresholds
Sensor leftSensor(A3, 42);
Sensor rightSensor(A1, 42);

// Create Motor instance with pins and pulse widths
Motor motor(3, 4, 700, 2300);

// Create Display instance
Display display;

bool lastLineOnLeft = false;
int lastSensor = -1; // -1 for left, 1 for right, -2 for none

void setup() {
    motor.init();
    display.init();
}

void loop() {
    // Check sensors
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    if (leftOnLine && rightOnLine) {
        // Both sensors detect the line
        if (lastSensor != -2) { // Only act if we have a previous line detection to compare
            if (lastSensor == -1) {
                motor.turnBackRight();
                display.showStatus("r"); // Reverse right
            } else if (lastSensor == 1) {
                motor.turnBackLeft();
                display.showStatus("l"); // Reverse left
            }
            // Wait until sensors no longer both detect the line
            while (leftSensor.isOnLine() && rightSensor.isOnLine()) {
                delay(50);
            }
        }
    } else if (!leftOnLine && !rightOnLine) {
        // Off the line
        if (lastLineOnLeft) {
            motor.turnRight();
            display.showStatus("R"); // Swivel right
        } else {
            motor.turnLeft();
            display.showStatus("L"); // Swivel left
        }
        lastSensor = -2; // No active line detected
    } else if (leftOnLine) {
        // Left sensor detects the line
        motor.turnRight();
        display.showStatus("R"); // Swivel right
        lastLineOnLeft = false;
        lastSensor = -1;
    } else if (rightOnLine) {
        // Right sensor detects the line
        motor.turnLeft();
        display.showStatus("L"); // Swivel left
        lastLineOnLeft = true;
        lastSensor = 1;
    }

    delay(70); // Adjust delay as necessary for stability
}

