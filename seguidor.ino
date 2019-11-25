/*DECLARAÇÃO DE VARIAVEIS*/
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7; 


#define Sensor_direita 12
#define Sensor_esquerda 13
 
bool sens_direita, sens_esquerda;
 
void setup() {
 Serial.begin(9600);
 Serial.println("Lendo dados do sensor...");
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 //pinMode(MotorA_PWM, OUTPUT);
 //pinMode(MotorB_PWM, OUTPUT);
 pinMode(Sensor_direita, INPUT);
 pinMode(Sensor_esquerda, INPUT);
 delay(1000);
 
}

void frente(){
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
}

void esquerda(){
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
}

void direita(){
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
}
void parar(){
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
}
void fim(){
   while(1);
}

void loop() {
   //Define o sentido de rotação dos motores

  //Leituras dos Sensores
  sens_direita = digitalRead(Sensor_direita);
  sens_esquerda = digitalRead(Sensor_esquerda);
  Serial.print(sens_direita);
  Serial.print(" || ");
  Serial.println(sens_esquerda);
 
  //Rodando os motores dependendo das leituras
if(sens_direita == false && sens_esquerda == false){
  Serial.print("Frente");
  frente();
}
if(sens_direita == false && sens_esquerda == true){
  Serial.print("Direita");
  direita();
  delay(50);
}
if(sens_direita == true && sens_esquerda == false){
  Serial.print("Esqueda");
  esquerda();
  delay(50);
}
if(sens_direita == true && sens_esquerda == true){
  Serial.print("Parar");
  parar();
  fim();
}
}
