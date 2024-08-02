#define L_MOTOR_PIN 7
#define R_MOTOR_PIN 8
#include "motor.h"

Servo r_servo;
Motor r_motor(r_servo, 50);
Servo l_servo;
Motor l_motor(l_servo, 50);

void setup() {
  // put your setup code here, to run once:
  l_servo.attach(L_MOTOR_PIN);
  r_servo.attach(R_MOTOR_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  l_motor.test();
  r_motor.test();
}
