#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <Arduino.h>
#include "LineDetection.h"
#include "Movement.h"

LineDetection lineDetection(A0, A1);
Movement movement(5, 6);
ArduinoLEDMatrix matrix;

void setup() {
    movement.init();
    lineDetection.init();
    Serial.begin(9600);
    matrix.begin();
    matrix.textFont(Font_5x7);
    matrix.textScrollSpeed(100);
    matrix.stroke(0xFF, 0, 0);
    matrix.beginText(0, 1, 0xFF, 0, 0);
    matrix.print("    V00.00.02");
    matrix.endText(SCROLL_LEFT);
}

void loop() {
    int lineStatus = lineDetection.detectLine();

    matrix.beginText(3, 1, 0xFF, 0, 0);
    matrix.print(lineStatus);
    matrix.endText(SCROLL_LEFT);

    switch (lineStatus) {
        case 0:
            movement.moveForward();
            break;
        case -1:
            movement.turnLeft();
            break;
        case 1:
            movement.turnRight();
            break;
        default:
            movement.stop(); // Off the line
            break;
    }

    delay(100); // Short delay to allow servo adjustments
}
