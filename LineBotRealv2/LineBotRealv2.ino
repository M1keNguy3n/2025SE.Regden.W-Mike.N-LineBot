#include "Sensor.h"
#include "Motor.h"
#include "Display.h"

// Initialize sensors with their respective pins and thresholds
Sensor leftSensor(A3, 58);
Sensor rightSensor(A4, 47);

// Create Motor instance with pins and pulse widths
Motor motor(8, 9, 700, 2300);

// Create Display instance
Display display;

void setup() {
    motor.init();       // Initialize motors
    motor.stop();
    display.init();     // Initialize display
    delay(1000);        // Wait for servos and display to initialize
}

void loop() {
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    if (!leftOnLine && !rightOnLine) {
        motor.forward();
        display.showStatus("F");
    } if (leftOnLine) {
        // If the left sensor detects the line, turn right
        motor.turnRight();
        display.showStatus("R"); // Display 'R' for turning right
    } if (rightOnLine) {
        // If the right sensor detects the line, turn left
        motor.turnLeft();
        display.showStatus("L"); // Display 'L' for turning left
    }
    delay(25); // Adjust delay as needed for sensor readings
}


