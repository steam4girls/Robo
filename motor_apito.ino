//--------------------------------------------------------
// Programa : Controle dos motores do robo e servomotor
// Autor : Steam4Girls
//--------------------------------------------------------

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;


// Definicoes de outros pinos
int APITO = 8; 
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(APITO, OUTPUT);
 Serial.begin(9600);
}

void loop(){

  frente();
  delay(1000);
  parar();
  digitalWrite(APITO, HIGH);
  delay(500);
  digitalWrite(APITO, LOW);
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
