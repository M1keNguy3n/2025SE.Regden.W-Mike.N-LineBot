#include <Arduino.h>
#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 5
#define L_IR_PIN_ANALOG A0
#define R_IR_PIN_ANALOG A1

Servo left_motor;
Servo right_motor;
ArduinoLEDMatrix matrix;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  left_motor.attach(5, 700, 2300);
  right_motor.attach(6, 700, 2300);
  pinMode(L_IR_PIN_ANALOG, INPUT);
  pinMode(R_IR_PIN_ANALOG, INPUT);
  matrix.begin();
  matrix.beginDraw();
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(100);
  matrix.stroke(0xFF, 0, 0);
  matrix.beginText(0, 1, 0xFFFFFF);
}

bool l_lineDetected(int l_val){
  //if the value is between 90 and 93, return true.
    return (!(l_val > 75));
}

bool r_lineDetected(int r_val){
    //if the value is between 98 and 107, return true.
    return (!(r_val > 57));
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  int r_val = analogRead(R_IR_PIN_ANALOG);
  int l_val = analogRead(L_IR_PIN_ANALOG);
  Serial.print(r_val);
  Serial.print(" ");
  Serial.println(l_val);
  delay(100);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}

/*Serial.print(r_val);
  Serial.print(" ");
  Serial.println(l_val);
  if (r_lineDetected(r_val)){
    matrix.print("R");
    
    left_motor.writeMicroseconds(1800);
    right_motor.writeMicroseconds(1500);
    delay(100);
  }
  else if (l_lineDetected(l_val)){
    matrix.print("L");
    
    left_motor.writeMicroseconds(1500);
    right_motor.writeMicroseconds(1200);
    delay(100);
  }
  left_motor.writeMicroseconds(1500);
  right_motor.writeMicroseconds(1500);
  delay(100);
  */