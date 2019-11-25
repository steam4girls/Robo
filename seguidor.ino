/*DECLARAÇÃO DE VARIAVEIS*/
int IN1 = 4;
int IN2 = 5;
int MotorA_PWM = 3;
int IN3 = 6;
int IN4 = 7; 
int MotorB_PWM = 9;  

#define Sensor_direita 12
#define Sensor_esquerda 13
 
bool direita, esquerda;
 
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
  
}
 
void loop() {
   //Define o sentido de rotação dos motores
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(MotorA_PWM, 250);
  analogWrite(MotorB_PWM, 250); 
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  Serial.print(direita);
  Serial.print(" || ");
  Serial.println(esquerda);
 
  //Rodando os motores dependendo das leituras
 if(direita == false && esquerda == false){
 analogWrite(MotorA_PWM, 250);
 analogWrite(MotorB_PWM, 250);
 Serial.print("Frente");

 } else if(direita == false && esquerda == true){
 //delay(400);
 analogWrite(MotorA_PWM, 250);
 analogWrite(MotorB_PWM, 200);
 Serial.print("Direita");
 //delay(400);
 }else if(direita == true && esquerda == false){
 //delay(400);
 analogWrite(MotorA_PWM, 200);
 analogWrite(MotorB_PWM, 250);
 //delay(400);
 Serial.print("Esqueda");
 
 }else if(direita == true && esquerda == true){
 analogWrite(MotorA_PWM, 0);
 analogWrite(MotorB_PWM, 0);
 Serial.print("Parar");
 while(1);
 }

}
