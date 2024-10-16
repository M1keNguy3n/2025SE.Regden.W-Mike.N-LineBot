#include "Display.h"

Display::Display() {
    matrix.begin();
    matrix.textFont(Font_5x7);
    matrix.textScrollSpeed(100);
    matrix.stroke(0xFF, 0, 0); // Red
}

void Display::showStatus(char status) { // Show status on the LED matrix
    matrix.beginText(0, 1, 0xFF, 0, 0);
    matrix.print(status);
    matrix.endText();
}
