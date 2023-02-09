#include <dht.h>

//pin relay
#define Rele1 13
//pin sensore temperatura dht11 sul sensore c'è una S per il segnale
#define Temp 12

dht temp; //inizializzo l'oggetto per il sensore

void setup() {
  Serial.begin(9600);
  
  pinMode(Rele1, OUTPUT);
  
  pinMode(8, OUTPUT);     //alimentazione ventola
  digitalWrite(8, HIGH);
}

void loop() {

  temp.read11(Temp);          //leggo la temperatura dal sensore
  int t = temp.temperature;   //inserisco il valore in una variabile
  Serial.println(t);

  //controllo se è maggiore di 27 Celsius allora accendo la ventola attraverso il relay per 5 sec
  if(t >= 27){
    digitalWrite(Rele1, HIGH);
    delay(5000);
    digitalWrite(Rele1, LOW);
  }
  delay(1000);

}
