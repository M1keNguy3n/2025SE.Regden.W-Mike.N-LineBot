#include "Arduino.h"
#include "ir.h"
#define IR_PIN A0
IR r_ir(IR_PIN);
void setup() {
  // put your setup code here, to run once:
  r_ir.init_digital();
}

void loop() {
  // put your main code here, to run repeatedly:
  r_ir.readStateDigital();
}
