#ifndef DISPLAY_H
#define DISPLAY_H

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

class Display {
private:
    ArduinoLEDMatrix matrix;

public:
    Display();
    void showStatus(char status);
};

#endif
