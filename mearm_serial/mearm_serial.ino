// Controle de um braco robotico meArm usando poteciometros
// Baseado no exemplo servo -> knob

#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
 
int controle1 = A0;
int controle2 = A1;
int controle3 = A2;

int valorComando = 90;
 
String comandoLido = "";
boolean comandoCompleto = false;

void setup() 
{ 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  
  Serial.begin(9600);
  comandoLido.reserve(20);

} 
 
void loop() 
{ 
  if (comandoCompleto) {
    valorComando = comandoLido.toInt();
    Serial.println(valorComando); 
    comandoLido = "";
    comandoCompleto = false;
  }
  
  lePotAcionaServo(servo1, controle1);
  lePotAcionaServo(servo2, controle2);
  //lePotAcionaServo(servo3, controle3);
  servo3.write(valorComando);
  
  delay(15);
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

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    comandoLido += inChar;
    if (inChar == '\n') {
      comandoCompleto = true;
    } 
  }
}

