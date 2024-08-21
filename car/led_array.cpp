#include "led_array.h"

LedMatrix::LedMatrix(ArduinoLEDMatrix &matrix){
  this->matrix = matrix;
}

void LedMatrix::display_version(){
  //display the current version.
  matrix.beginText(0, 1, 0xFF, 0, 0);
  matrix.print("V00.00.01");
  matrix.endText(SCROLL_LEFT);
}

void LedMatrix::display_text(char text){
  //display the given text.
  matrix.beginText(0, 1, 0xFF, 0, 0);
  matrix.print(text);
  matrix.endText(SCROLL_LEFT);
}