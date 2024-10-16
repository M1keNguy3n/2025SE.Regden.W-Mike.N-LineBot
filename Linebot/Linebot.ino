#include <Arduino.h>
#include "LineDetection.h"
#include "Movement.h"


LineDetection lineDetection(A0, A1);  // Pins for left and right sensors
Movement movement(5, 6);             // Servo motor pins


void setup() {
    lineDetection.init();
    movement.init();
}


void loop() {
    int lineStatus = lineDetection.detectLine();


    if (lineStatus == 0) {
        // On the line
        movement.moveForward();
    } else if (lineStatus == -1) {
        // Too far right
        movement.turnLeft();
    } else if (lineStatus == 1) {
        // Too far left
        movement.turnRight();
    } else {
        // Off the line
        movement.stop();  // or implement a search algorithm
    }


    delay(100);  // Short delay to allow servo adjustments
}




