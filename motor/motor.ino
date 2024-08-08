#define L_MOTOR_PIN 5
#define R_MOTOR_PIN 6
#include "motor.h"

Servo r_servo;
Servo l_servo;
Motor motor(l_servo, r_servo, 200);

void setup() {
  // put your setup code here, to run once:
  l_servo.attach(L_MOTOR_PIN);
  r_servo.attach(R_MOTOR_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.fast_forward();
}