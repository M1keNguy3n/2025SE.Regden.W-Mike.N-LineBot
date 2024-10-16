#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// Define servo objects
Servo servo1;
Servo servo2;

// Define pins for the servos
const int servoPin1 = 3;
const int servoPin2 = 4;

// Arrow frames for the LED matrix
const uint32_t arrow_left[] = {
		0x400c01c,
		0x3fc3fc1,
		0xcc0cc04c,
		66
};

const uint32_t arrow_right[] = {
		0x2003003,
		0x83fc3fc3,
		0x38330320,
		66
};


const uint32_t arrow_up[] = {
		0x600f01f,
		0x83fc0600,
		0x60060060,
		66
};


const uint32_t arrow_down[] = {
		0x6006006,
		0x603fc1,
		0xf80f0060,
		66
};
ArduinoLEDMatrix matrix;

// Setup function to initialize servos and LED matrix
void setup() {
    // Attach servos to specified pins with a range appropriate for continuous servos
    servo1.attach(servoPin1, 700, 2300);
    servo2.attach(servoPin2, 700, 2300);

    // Initialize the LED matrix
    matrix.begin();
    matrix.textFont(Font_5x7);
    matrix.textScrollSpeed(100);
    matrix.stroke(0xFF, 0, 0);
    matrix.beginText(0, 1, 0xFF, 0, 0);
    matrix.print("V00.00.01");
    matrix.endText(SCROLL_LEFT);
}

// Loop function to execute movement patterns
void loop() {
    // Move forward
    matrix.loadFrame(arrow_up);
    moveForward();
    delay(1000);  // Move forward for 2 seconds

    // Stop
    matrix.loadFrame(arrow_down);
    stop();
    delay(1000);  // Stop for 1 second

    // Turn left
    matrix.loadFrame(arrow_left);
    turnLeft();
    delay(1000);  // Turn left for 2 seconds

    // Stop
    matrix.loadFrame(arrow_down);
    stop();
    delay(1000);  // Stop for 1 second

    // Turn right
    matrix.loadFrame(arrow_right);
    turnRight();
    delay(1000);  // Turn right for 2 seconds

    // Stop
    matrix.loadFrame(arrow_down);
    stop();
    delay(1000);  // Stop for 1 second
}

// Function to move the robot forward
void moveForward() {
    servo1.writeMicroseconds(2300);  // Full speed forward
    servo2.writeMicroseconds(700);   // Full speed forward
}

// Function to turn the robot left
void turnLeft() {
    servo1.writeMicroseconds(1500);  // Stop left servo
    servo2.writeMicroseconds(2300);  // Full speed forward
}

// Function to turn the robot right
void turnRight() {
    servo1.writeMicroseconds(2300);  // Full speed forward
    servo2.writeMicroseconds(1500);  // Stop right servo
}

// Function to stop the robot
void stop() {
    servo1.writeMicroseconds(1500);  // Neutral position
    servo2.writeMicroseconds(1500);  // Neutral position
}

