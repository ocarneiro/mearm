// Controle de um braco robotico meArm usando poteciometros
// Baseado no exemplo servo -> knob

#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int controle1 = A0;
int controle2 = A1;
int controle3 = A2;
int controle4 = A3;
 
void setup() 
{ 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  
} 
 
void loop() 
{ 
  lePotAcionaServo(servo1, controle1);
  lePotAcionaServo(servo2, controle2);
  lePotAcionaServo(servo3, controle3);
  lePotAcionaServo(servo4, controle4);
  delay(50);
} 

int leComando(int controle) {
  int val = analogRead(controle);
  val = map(val, 0, 1023, 0, 179);
  return val;
}

void lePotAcionaServo(Servo servo, int controle) {
  int val = leComando(controle);
  servo.write(val);
}
