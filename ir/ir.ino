#include "ir.h"
#define IR_PIN_DIGITAL 5
#define IR_PIN_ANALOG A3

IR r_ir(IR_PIN_DIGITAL, IR_PIN_ANALOG);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  r_ir.init_analog();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(r_ir.readStateAnalog());
}
