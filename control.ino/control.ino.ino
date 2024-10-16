#include "Control.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

const int leftSensorPin = A0;   // Digital pin connected to the left sensor's OUT1 pin
const int rightSensorPin = A1;  // Digital pin connected to the right sensor's OUT2 pin

void setup() {
  pinMode(leftSensorPin, INPUT);   // Set the left sensor pin as INPUT
  pinMode(rightSensorPin, INPUT);  // Set the right sensor pin as INPUT
  matrix.begin();
  }

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
void leftEye(){
  //Left eye
  frame[1][3] = 1;
  frame[1][4] = 1;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void wink(){
  //Wink with the left eye
  frame[1][3] = 0;
  frame[1][4] = 0;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void rightEye(){
  //Right eye
  frame[1][8] = 1;
  frame[1][9] = 1;
  frame[2][8] = 1;
  frame[2][9] = 1;
}

void mouth(){
  //Mouth
  frame[5][3] = 1;
  frame[5][9] = 1;
  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
  frame[6][9] = 1;
}

void loop() {
  int leftSensorValue = digitalRead(leftSensorPin);    // Read the left sensor value
  int rightSensorValue = digitalRead(rightSensorPin);  // Read the right sensor value

  if (leftSensorValue == HIGH && rightSensorValue == LOW) {
      leftEye();
    // The robot is on the left edge of the line
    // Turn right or take appropriate action to stay on track
  } else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
      rightEye();
  } else if (leftSensorValue == LOW && rightSensorValue == LOW) {
      leftEye();
      rightEye();
      mouth();

      matrix.renderBitmap(frame, 8, 12);

      delay(1000);
      wink();

      matrix.renderBitmap(frame, 8, 12);
      delay(1000);
    // The robot is on the line
    // Continue moving forward or adjust as needed
  } else if (leftSensorValue == HIGH && rightSensorValue == HIGH) {
      mouth();
    // The robot is off the line or in an ambiguous position
    // Take appropriate action to align with the line
  }
}