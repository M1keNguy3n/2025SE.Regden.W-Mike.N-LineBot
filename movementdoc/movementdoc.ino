
#include <Servo.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

const uint32_t arrow_right[] = {
		0x400c01c,
		0x3fc3fc1,
		0xcc0cc04c,
		66
};

const uint32_t arrow_left[] = {
		0x2003003,
		0x83fc3fc3,
		0x38330320,
		66
};

const uint32_t arrow_down[] = {
		0x600f01f,
		0x83fc0600,
		0x60060060,
		66
};

const uint32_t arrow_up[] = {
		0x6006006,
		0x603fc1,
		0xf80f0060,
		66
};

ArduinoLEDMatrix matrix;
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
   matrix.begin();
   matrix.textFont(Font_5x7);
   matrix.textScrollSpeed(100);
   matrix.stroke(0xFF, 0, 0);
   matrix.beginText(0, 1, 0xFF, 0, 0);
   matrix.print("    V00.00.02");
   matrix.endText(SCROLL_LEFT);
  servo1.attach(5, 700, 2300);
  servo2.attach(6, 700, 2300);
}

void loop() {
  matrix.loadFrame(arrow_up);
  servo1.writeMicroseconds(2100);
  delay(70);
  servo2.writeMicroseconds(700);  // forward
  delay(5000);

  servo1.writeMicroseconds(1505);
  servo2.writeMicroseconds(1505);  // stop
  delay(1000);

  matrix.loadFrame(arrow_down);
  servo1.writeMicroseconds(700);
  delay(70);
  servo2.writeMicroseconds(2300);  // back
  delay(5000);

  servo1.writeMicroseconds(1505);
  servo2.writeMicroseconds(1505);  // stop
  delay(1000);

  matrix.loadFrame(arrow_right);
  servo1.writeMicroseconds(2100);
  servo2.writeMicroseconds(1505);  // right forward
  delay(1000);

  matrix.loadFrame(arrow_right);
  servo1.writeMicroseconds(900);
  servo2.writeMicroseconds(1505);  // right backward
  delay(1000);
  
  matrix.loadFrame(arrow_left);
  servo1.writeMicroseconds(1505);
  servo2.writeMicroseconds(700);  // left forward
  delay(1000);
  
  matrix.loadFrame(arrow_left);
  servo1.writeMicroseconds(1505);
  servo2.writeMicroseconds(2300);  // left backward
  delay(1000);

  servo1.writeMicroseconds(1505);
  servo2.writeMicroseconds(1505);  // stop
  delay(1000);

}