// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
 
int controle1 = A0;
int controle2 = A1;
int controle3 = A2;
 
void setup() 
{ 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
} 
 
void loop() 
{ 
  acionaServo(servo1, controle1);
  acionaServo(servo2, controle2);
  acionaServo(servo3, controle3);
  delay(15);
} 

void acionaServo(Servo servo, int controle) {
  int val = analogRead(controle);
  val = map(val, 0, 1023, 0, 179);
  servo.write(val);
}
