#ifndef DISPLAY_H
#define DISPLAY_H

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

class Display {
public:
    Display();
    void init();
    void showStatus(const char* status); // Shows a string on the display

private:
    ArduinoLEDMatrix matrix;
};

#endif
