#include "led_array.h"

LedMatrix::LedMatrix(ArduinoLEDMatrix& matrix, frame){
  this->matrix = matrix;
  this->frame = frame;
}

void LedMatrix::add_to_frame(char c, int pos){
  int index = 0;
  if (c >= '0' && c <= '9')
    index = c - '0';
  else if (c >= 'A' && c <= 'Z')
    index = c - 'A' + 10;
  else {
    Serial.println("WARNING: unsupported character");
    return;
  }

  for (int row = 0; row < 8; row++) {
    uint32_t temp = fonts[index][row] << (7 - pos);
    for (int col = 0; col < 12; col++) {
      frame[row][col] |= (temp >> (11 - col)) & 1;
    }
  }
}

void LedMatrix::display_frame(){
  matrix.renderBitmap(frame, 8, 12);
}

void LedMatrix::clear_frame(){
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      frame[row][col] = 0;
    }
  }
}