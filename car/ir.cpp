#include "ir.h"

IR::IR(byte pin_digital, byte pin_analog){
  //instantiate an IR sensor with digital and analog pin
  this -> pin_digital = pin_digital;
}

IR::IR(byte pin_analog){
  //instantiate an IR sensor with analog pin
  this -> pin_analog = pin_analog;
}

void IR::init(){
  //initialize the analog and digital pin, if available.
  pinMode(pin_analog, INPUT);
  state_analog = analogRead(pin_analog);
  pinMode(pin_digital, INPUT);
  state_digital = digitalRead(pin_digital);
}

void IR::init_digital(){
  //initialize the digital pin, if available.
  pinMode(pin_digital, INPUT);
  state_digital = digitalRead(pin_digital);
}

void IR::init_analog(){
  //initialize the analog pin, if available.
  pinMode(pin_analog, INPUT);
  state_analog = analogRead(pin_analog);
}

byte IR::readStateDigital(){
  //return a byte value, 0 or 1.
  state_digital = digitalRead(pin_digital);
  return state_digital;
}

unsigned long IR::readStateAnalog(){
  //returns the value from the ir.
  delay(10);
  return analogRead(pin_analog);
}

bool IR::l_lineDetected(){
  //if the value is between 58 and 65, return true.

<<<<<<< HEAD
  return (!(readStateAnalog() > 65));
=======
  return (readStateAnalog() < 46);
>>>>>>> 79b4874d0bc216b7253ad82bae1139df80b70f55
}

bool IR::r_lineDetected(){
  //if the value is between 46 and 56, return true.

<<<<<<< HEAD
  return (!(readStateAnalog() > 55));
=======
  return (readStateAnalog() < 56);
>>>>>>> 79b4874d0bc216b7253ad82bae1139df80b70f55
}

