#include "ir.h"

IR::IR(byte pin_digital){
  this -> pin_digital = pin_digital;
  state = digitalRead(pin_digital);
}

void IR::init_digital(){
  pinMode(pin_digital, INPUT);
}

void IR::init_analog(){
  pinMode(pin_analog, INPUT);
}

void IR::readStateDigital(){
  state_digital = digitalRead(pin);
  return state_digital;
}

void IR::readStateAnalog(){
  state_analog = analogRead(pin);
  return state_analog;
}