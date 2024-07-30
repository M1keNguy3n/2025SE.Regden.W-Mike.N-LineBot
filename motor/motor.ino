#define MOTOR_PIN 7
#include "motor.h"

Servo myservo;
Motor motor(myservo, 50);
void setup() {
  // put your setup code here, to run once:
  myservo.attach(MOTOR_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.test();
}
