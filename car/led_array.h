#ifndef LED_ARRAY_H
#define LED_ARRAY_H
#include <Arduino.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

class LedMatrix: public ArduinoLEDMatrix{
  private:
    ArduinoLEDMatrix matrix;
  public:
    LedMatrix(ArduinoLEDMatrix& matrix);
    void display_version();
    void display_text(char text);
};
#endif