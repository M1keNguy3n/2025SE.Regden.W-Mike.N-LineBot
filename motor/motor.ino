#define L_MOTOR_PIN 5
#define R_MOTOR_PIN 6
#include "motor.h"

Servo r_servo;
Servo l_servo;
Motor motor(l_servo, r_servo, 200);

void setup() {
  // put your setup code here, to run once:
  motor.init(L_MOTOR_PIN, R_MOTOR_PIN);
}

void loop() {
  motor.fast_forward();
  motor.turn_left();
  motor.fast_forward();
}