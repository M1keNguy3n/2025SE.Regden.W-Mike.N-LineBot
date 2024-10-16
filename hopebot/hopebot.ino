#include <Servo.h>

Servo leftWheel;
Servo rightWheel;

// Define sensor pins
const int leftSensorPin = A3;
const int rightSensorPin = A1;

// Define wheel control pins
const int leftWheelPin = 3;
const int rightWheelPin = 4;

// Define thresholds for line detection
const int threshold = 49;

// Variables to store the last sensor that detected the line
bool lastLineOnLeft = false;

void setup() {
    // Attach the servos to the wheels
    leftWheel.attach(leftWheelPin);
    rightWheel.attach(rightWheelPin);

    // Stop both wheels at the start
    leftWheel.writeMicroseconds(1505);
    rightWheel.writeMicroseconds(1505);
}

void loop() {
    // Read sensor values
    int leftSensorValue = analogRead(leftSensorPin);
    int rightSensorValue = analogRead(rightSensorPin);

    // Detect if on the line or not
    bool onLeftLine = (leftSensorValue < threshold);
    bool onRightLine = (rightSensorValue < threshold);

    if (onLeftLine && !onRightLine) {
        // Line is detected on the left sensor only
        lastLineOnLeft = true;
        turnRight();
    } else if (onRightLine && !onLeftLine) {
        // Line is detected on the right sensor only
        lastLineOnLeft = false;
        turnLeft();
    } else if (onLeftLine && onRightLine) {
        // Both sensors detect the line
        if (lastLineOnLeft) {
            reverseRightWheel();
        } else {
            reverseLeftWheel();
        }
    } else {
        // Neither sensor detects the line; continue previous motion
        if (lastLineOnLeft) {
            turnRight();
        } else {
            turnLeft();
        }
    }

    delay(100); // Short delay to allow sensors to detect line
}

void turnLeft() {
    leftWheel.writeMicroseconds(1505);  // Stop left wheel
    rightWheel.writeMicroseconds(1550); // Turn right wheel forward
}

void turnRight() {
    leftWheel.writeMicroseconds(1460);  // Turn left wheel forward
    rightWheel.writeMicroseconds(1505); // Stop right wheel
}

void reverseLeftWheel() {
    leftWheel.writeMicroseconds(1460);  // Reverse left wheel
    rightWheel.writeMicroseconds(1505); // Stop right wheel
}

void reverseRightWheel() {
    leftWheel.writeMicroseconds(1505);  // Stop left wheel
    rightWheel.writeMicroseconds(1550); // Reverse right wheel
}

  
