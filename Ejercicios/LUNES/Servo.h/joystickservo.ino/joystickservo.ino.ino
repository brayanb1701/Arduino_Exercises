#include <Servo.h>

Servo servo1;


int joyY = 0;

int joyVal;

void setup() {
  // put your setup code here, to run once:
servo1.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  joyVal = analogRead(joyY);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);
  delay(15);
}
