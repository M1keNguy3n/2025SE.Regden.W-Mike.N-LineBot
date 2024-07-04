#include "Arduino.h"
#include "ir.h"
#define IR_PIN_DIGITAL 5
#define IR_PIN_ANALOG A0
IR r_ir(IR_PIN_DIGITAL, IR_PIN_ANALOG);
void setup() {
  // put your setup code here, to run once:
  r_ir.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  r_ir.readStateDigital();
  r_ir.readStateAnalog();
}
