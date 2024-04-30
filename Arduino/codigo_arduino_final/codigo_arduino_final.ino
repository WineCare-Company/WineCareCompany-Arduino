#include "DHT.h"
#define dht_type DHT11

int dht_pin = A0;
DHT dht_1 = DHT(dht_pin, dht_type);

void setup() {
  Serial.begin(9600);
  dht_1.begin();
}

void loop() {
  float umidade = dht_1.readHumidity();
  float temperatura = dht_1.readTemperature();
  float UmidadeMin = 60;
 float UmidadeMax = 80;
 float TemperaturaMin = 15;
 float TemperatuaMax = 20;
  if(isnan(temperatura) or isnan(umidade)){
    Serial.println("Erro ao ler"); 
  } else {
    serial.print(UmidadeMin);
    Serial.print(umidade);
    Serial.print(UmidadeMax);
    Serial.print(",");
    Serial.print(TemperaturaMin);
    Serial.print(temperatura);
    Serial.println(TemperaturaMax);
  }
  delay(2000);
}