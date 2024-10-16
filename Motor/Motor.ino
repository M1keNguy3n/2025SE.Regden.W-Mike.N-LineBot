#include "Motor.h"

// Create Motor instance with pins and pulse widths
Motor motor(3, 4, 700, 2300);

void setup() {
    motor.init();
    delay(1000);  // Wait for servos to initialize
}

void loop() {
    // Turn left
    motor.turnLeft();
    delay(2000);  // Turn left for 2 seconds

    // Turn right
    motor.turnRight();
    delay(2000);  // Turn right for 2 seconds

    motor.turnBackLeft();
    delay(2000);  // Turn left for 2 seconds

    // Turn right
    motor.turnBackRight();
    delay(2000);  // Turn right for 2 seconds

    // Stop
    motor.stop();
    delay(2000);  // Stop for 2 seconds
}
