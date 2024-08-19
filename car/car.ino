#include "ai_driver.h"
#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 5
#define L_IR_PIN_ANALOG A0
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
}

void loop() {
  /*
  Serial.print(r_ir.readStateAnalog());
  Serial.print(" ");
  Serial.print(!(r_ir.readStateAnalog() <= 43 || r_ir.readStateAnalog() > 52));
  Serial.print(!(l_ir.readStateAnalog() < 82 || l_ir.readStateAnalog() > 89));
  Serial.print(" ");
  Serial.println(l_ir.readStateAnalog());
  delay(50);
  */

  car.update(15, 15);
}