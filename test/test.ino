#include <Arduino.h>
#include <Servo.h>
#define L_MOTOR_PIN 5
#define R_MOTOR_PIN 6
Servo l_motor;
Servo r_motor;
void setup() {
  // put your setup code here, to run once:
  l_motor.attach(5);
  r_motor.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  //backward
  //l_motor.writeMicroseconds(700);
  //r_motor.writeMicroseconds(2300);
  //forward
  l_motor.writeMicroseconds(2300);
  r_motor.writeMicroseconds(700);
  delay(3000);
  //180 clockwise
  //l_motor.writeMicroseconds(2300);
  //r_motor.writeMicroseconds(2300);
  //delay(1030);
  //90 clockwise
  l_motor.writeMicroseconds(2300);
  r_motor.writeMicroseconds(2300);
  delay(550);
  //90 anticlockwise
  l_motor.writeMicroseconds(700);
  r_motor.writeMicroseconds(700);
  delay(550);
  //discharge
  l_motor.writeMicroseconds(2300);
  r_motor.writeMicroseconds(700);
  delay(200);
}
