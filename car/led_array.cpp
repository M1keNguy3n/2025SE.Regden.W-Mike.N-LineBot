#include "led_array.h"

LedMatrix::LedMatrix(ArduinoLEDMatrix &matrix){
  this->matrix = matrix;
}

void LedMatrix::display_version(){
  //display the current version.
  matrix.beginText();
  matrix.print("V00.00.01");
  matrix.endText();
}

void LedMatrix::display_text(char text){
  //display the given text.
  matrix.beginText();
  matrix.print(text);
  matrix.endText();
}