#include "ir.h"
#define IR_PIN_DIGITAL 5
#define IR_PIN_ANALOG A0
IR r_ir(IR_PIN_DIGITAL, IR_PIN_ANALOG);
void setup() {
  // put your setup code here, to run once:

  r_ir.init_digital();
  Serial.begin(115200);

  r_ir.init();

  r_ir.init();

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.write(r_ir.readStateDigital());
  r_ir.readStateDigital();
  r_ir.readStateAnalog();
}
