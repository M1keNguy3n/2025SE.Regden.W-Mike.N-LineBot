#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 7
#define L_IR_PIN_ANALOG A0
#define R_IR_PIN_ANALOG A1
#define L_IR_PIN_DIGITAL 5
#define R_IR_PIN_DIGITAL 4
#include "ai_driver.h"

Servo r_servo;
Servo l_servo;
Motor motor(l_servo, r_servo, 50);
IR r_ir(R_IR_PIN_DIGITAL, R_IR_PIN_ANALOG);
IR l_ir(L_IR_PIN_DIGITAL, L_IR_PIN_ANALOG);
AI_Driver car(motor, r_sensor, l_sensor);

void setup() {
  // put your setup code here, to run once:
  car.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  car.update();
}
