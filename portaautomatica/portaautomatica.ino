#include <Servo.h>
Servo Servo1;

const int servoPin = 9;

const int trigPin = 10;
const int echoPin = 11;

const int nleituras = 5;

long leituras[nleituras];
int total, media = 0;

unsigned long tempPa = 0;
const long intervalo = 3000;

int medirdist();

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Servo1.attach(servoPin);
  Serial.begin(115200);

  for(int i = 0; i < nleituras; i++){
    leituras[i] = 0;
  }
}

void loop() {
  unsigned long tempAt = millis();
  //Servo1.write(angle);
  
  if((tempAt - tempPa) >= intervalo){
    tempPa = tempAt;
    //Serial.println(medirdist()); //teste sensor sem a media das distancias
    for(int i = 0; i <= nleituras; i++){
      total = total + medirdist();
    }
    media = total / nleituras;
    total = 0;

    if(media < 10){
      
      Serial.print("Aberto ");
      Serial.print("Distancia: ");
      Servo1.write(90);
      Serial.println(media);
    }else{
      Serial.print("Fechado ");
      Serial.print("Distancia: ");
      Serial.println(media);
      delay(2000);// tempo de seguranca para evitar fechar em cima da pessoa
      Servo1.write(0);
      
    }

    media = 0;
    

  }  
}

int medirdist(){
    long duracao;
    int distancia;
  /* Medir distancia*/
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    duracao = pulseIn(echoPin, HIGH);

    distancia = duracao * 0.034 / 2; //duracao * velocidade do som divido pela metade do caminho;
    return distancia;
}
