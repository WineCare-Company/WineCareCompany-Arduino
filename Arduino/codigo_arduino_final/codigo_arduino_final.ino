#include "DHT.h"  // Inclui a biblioteca DHT para usar com o sensor de temperatura e umidade

#define dht_type DHT11  // Define o tipo de sensor DHT como DHT11

int dht_pin = A0;  // Define o pino analógico A0 como a entrada do sensor DHT
DHT dht_1(dht_pin, dht_type);  // Cria um objeto DHT chamado dht_1, associado ao pino dht_pin e ao tipo dht_type

void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial a 9600 bps
  dht_1.begin();  // Inicia o sensor DHT
  Serial.println("umidade,temperatura,UmidadeMin,UmidadeMax,TemperaturaMin,TemperaturaMax");
}

void loop() {
  float umidade = dht_1.readHumidity();  // Lê a umidade do ar e armazena na variável 'umidade'
  float temperatura = dht_1.readTemperature();  // Lê a temperatura do ar e armazena na variável 'temperatura'

  // Define os limites desejados para umidade e temperatura
  float UmidadeMin = 60;
  float UmidadeMax = 80;
  float TemperaturaMin = 15;
  float TemperaturaMax = 20;
  
  if (isnan(temperatura) || isnan(umidade)) {  // Verifica se os valores de temperatura ou umidade são inválidos
    Serial.print("Falha ao ler do sensor DHT11");  // Exibe mensagem de erro no monitor serial
  } else {
    // Envia os dados com rótulos descritivos para o monitor serial
    Serial.print("Umidade Minima: ");
    Serial.print(UmidadeMin);
    Serial.print(", Umidade Atual: ");
    Serial.print(umidade);
    Serial.print(", Umidade Maxima: ");
    Serial.print(UmidadeMax);
    Serial.print(", Temperatura Minima: ");
    Serial.print(TemperaturaMin);
    Serial.print(", Temperatura Atual: ");
    Serial.print(temperatura);
    Serial.print(", Temperatura Maxima: ");
    Serial.println(TemperaturaMax);
  }
  delay(2000);  // Pausa a execução do loop por 2 segundos
}
