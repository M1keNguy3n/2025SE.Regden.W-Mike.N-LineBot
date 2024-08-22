#include "ai_driver.h"
#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 5
#define L_IR_PIN_ANALOG A3
#define R_IR_PIN_ANALOG A1


Servo r_servo;
Servo l_servo;
Motor motor(l_servo, r_servo, 60);
IR r_ir(R_IR_PIN_ANALOG);
IR l_ir(L_IR_PIN_ANALOG);
ArduinoLEDMatrix matrix;
LedMatrix array(matrix);
AI_Driver car(motor, r_ir, l_ir, array);

void setup() {
  // put your setup code here, to run once:
  car.init(L_MOTOR_PIN, R_MOTOR_PIN);
  Serial.begin(9600);
  delay(2000);
  
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(100);
  matrix.stroke(0xFF, 0, 0);
}

void loop() {
  car.update(30, 30);
}