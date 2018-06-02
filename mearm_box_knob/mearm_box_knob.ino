/*
 * Controls a mearm robotic arm
 * Based on Knob arduino example:
 * http://www.arduino.cc/en/Tutorial/Knob
 * 
 * adapted by Otavio Carneiro
 * www.carneiro.blog.br
 * www.github.com/ocarneiro
 */

#include <Servo.h>

Servo servo3;
Servo servo5;
Servo servo6;
Servo servo9;

int pot0 = 0;
int pot1 = 1;
int pot2 = 2;
int pot3 = 3;

void setup() {
  servo3.attach(3);
  servo5.attach(5);
  servo6.attach(6);
  servo9.attach(9);
}

void loop() {
  servo3.write(fromPotToServo(analogRead(pot0)));
  servo5.write(fromPotToServo(analogRead(pot1)));
  servo6.write(fromPotToServo(analogRead(pot2)));
  servo9.write(fromPotToServo(analogRead(pot3)));
  delay(15);
}

int fromPotToServo(int pot) {
  return map(pot, 0, 1023, 0, 180);
}

