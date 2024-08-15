#include "ai_driver.h"
#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 5
#define L_IR_PIN_ANALOG A0
#define R_IR_PIN_ANALOG A1


Servo r_servo;
Servo l_servo;
Motor motor(l_servo, r_servo, 100);
IR r_ir(R_IR_PIN_ANALOG);
IR l_ir(L_IR_PIN_ANALOG);
AI_Driver car(motor, r_ir, l_ir);

void setup() {
  // put your setup code here, to run once:
  car.init(L_MOTOR_PIN, R_MOTOR_PIN);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(l_ir.readStateAnalog());
  Serial.print(" ");
  Serial.print((r_ir.readStateAnalog() < 40 || r_ir.readStateAnalog() > 45));
  Serial.print((l_ir.readStateAnalog() < 90 || l_ir.readStateAnalog() > 97));
  Serial.print(" ");
  Serial.println(r_ir.readStateAnalog());
 
}
