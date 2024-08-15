#include "ir.h"

IR::IR(byte pin_digital, byte pin_analog){
  this -> pin_digital = pin_digital;
  this -> pin_analog = pin_analog;
}

IR::IR(byte pin_analog){
  this -> pin_analog = pin_analog;
}

void IR::init(){
  pinMode(pin_analog, INPUT);
  state_analog = analogRead(pin_analog);
  pinMode(pin_digital, INPUT);
  state_digital = digitalRead(pin_digital);
}

void IR::init_digital(){
  pinMode(pin_digital, INPUT);
  state_digital = digitalRead(pin_digital);
}

void IR::init_analog(){
  pinMode(pin_analog, INPUT);
  state_analog = analogRead(pin_analog);
}

byte IR::readStateDigital(){
  state_digital = digitalRead(pin_digital);
  return state_digital;
}

unsigned long IR::readStateAnalog(){
  state_analog = analogRead(pin_analog);
  delay(5);
  return state_analog;
}

bool IR::l_lineDetected(){
  return !(readStateAnalog() < 90 || readStateAnalog() > 93);
}

bool IR::r_lineDetected(){
  return !(readStateAnalog() < 98 || readStateAnalog() > 107);
}

