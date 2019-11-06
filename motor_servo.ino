//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : Carlos Jr

#include <Servo.h>
// Cria servomotor
Servo myservo; 

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int SERVO = 9;

  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 myservo.attach(SERVO);
 myservo.write(90);
 Serial.begin(9600);
}

void loop(){

  frente();
  delay(1000);
  parar();
  myservo.write(180);
  delay(500);
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  fim();
}

void frente()
{
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void parar(){
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
}
void fim(){
  while(1);
}
