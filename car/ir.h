#ifndef IR_H
#define IR_H
#include <Arduino.h>
class IR{
  private:
    byte state_digital;
    byte pin_digital;
    byte pin_analog;
    unsigned long state_analog;
  public:
    IR(){} //do not use
    IR(byte pin_digital, byte pin_analog);
    void init_digital();
    void init_analog();
    void init();
    unsigned long readStateDigital();
    unsigned long readStateAnalog();
};
#endif