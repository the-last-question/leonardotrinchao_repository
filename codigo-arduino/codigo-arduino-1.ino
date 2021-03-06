//Arduino Principal

#include <SoftwareSerial.h>

#define tmp 4000
#define echoPin 2	//Definindo que a porta ECHO está na porta 2
#define trigPin 3	//Definindo que a porta TRIG está na porta 3
#define vermelho 12
#define azul 10
#define verde 9

float tempo=0;	//Definindo a variável de duração
float distancia=0;	//Definindo a variável de distancia

void led_vermelho(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}

void led_verde(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}

void led_amarelo(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

void setup()
{
  pinMode(echoPin, INPUT);	//INPUT = Recebe
  pinMode(trigPin, OUTPUT);	//OUTPUT = Envia
  Serial.begin(9600);	//P/ comunicação serial
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);	//Eleva o sinal pra possibilitar o envio do sinal ultrassônico 
  delayMicroseconds(10);	//Por 10 ms
  digitalWrite(trigPin, LOW);
  
  tempo = pulseIn(echoPin, HIGH); //Captura a duração do pulso em um pino
  distancia = tempo*(0.017175);	//Valor provido do calculo da velocidade de propagação do som
  
  //Serial.println(distancia);	//Passando as info's pro Serial
  //Serial.println("cm");
  delay(800);
  
  //MÁXIMA = 330cm | MÍNIMA = 3cm
  if(distancia >= 3 && distancia < 110){
    led_vermelho();
    Serial.print("REGIAO 3: ");
    Serial.println(distancia);
  }
  else if(distancia >= 110 && distancia < 220){
    led_amarelo();
    Serial.print("REGIAO 2: ");
    Serial.println(distancia);
  }
  else if(distancia >= 220){
    led_verde();
    Serial.print("REGIAO 1: ");
    Serial.println(distancia);
  }
  delay(tmp);
}
