#include "led_array.h"

LedMatrix::LedMatrix(ArduinoLEDMatrix &matrix){
  this->matrix = matrix;
}

void LedMatrix::display_version(){
  //display the current version.
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(100);
  matrix.stroke(0xFF, 0, 0);
  matrix.beginText(0, 1, 0xFF, 0, 0);
  matrix.print("V00.00.01");
  matrix.endText();
}

void LedMatrix::display_text(char text){
  //display the given text.
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(100);
  matrix.stroke(0xFF, 0, 0);
  matrix.beginText(0, 1, 0xFF, 0, 0);
  matrix.print(text);
  matrix.endText();
}