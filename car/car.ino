#define R_MOTOR_PIN 6
#define L_MOTOR_PIN 7
#define L_IR_PIN_ANALOG A0
#define R_IR_PIN_ANALOG A1
#define L_IR_PIN_DIGITAL 5
#define R_IR_PIN_DIGITAL 4

Servo r_servo;
Motor r_motor(r_servo);
Servo l_servo;
Motor l_motor(r_servo);
IR r_ir(R_IR_PIN_DIGITAL, R_IR_PIN_ANALOG);
IR l_ir(L_IR_PIN_DIGITAL, L_IR_PIN_ANALOG);

void setup() {
  // put your setup code here, to run once:
  r_motor.attach(R_MOTOR_PIN);
  l_motor.attach(L_MOTOR_PIN);
  l_ir.init();
  r_ir.init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
