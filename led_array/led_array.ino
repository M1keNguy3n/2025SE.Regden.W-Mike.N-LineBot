/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-uno-r4-led-matrix-displays-number-character
 */

#include "led_array.h"

ArduinoLEDMatrix matrix;
LedMatrix LEDarray(matrix);

void setup() {
  // put your setup code here, to run once:
  LEDarray.begin();
}

void loop() {
  LEDarray.display_version();
  delay(1000);

  LEDarray.display_text('0');
  delay(1000);
}

