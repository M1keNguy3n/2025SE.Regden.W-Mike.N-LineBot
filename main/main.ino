#include "Robot.h"

// Define pins and thresholds
#define LEFT_SENSOR_PIN A3
#define RIGHT_SENSOR_PIN A1
#define LEFT_THRESHOLD 46
#define RIGHT_THRESHOLD 46
#define LEFT_MOTOR_PIN 3
#define RIGHT_MOTOR_PIN 4

// Create Robot instance
Robot myRobot(LEFT_SENSOR_PIN, RIGHT_SENSOR_PIN, LEFT_THRESHOLD, RIGHT_THRESHOLD, LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);

void setup() {
    // Initialization code here
    myRobot.getDisplay().showStatus('S'); // Display 'S' for Start
}

void loop() {
    // Update robot's state
    myRobot.update();
    delay(100); // Add a delay between updates to control speed
}

