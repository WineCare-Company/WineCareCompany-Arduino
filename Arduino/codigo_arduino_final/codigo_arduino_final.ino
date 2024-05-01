#include "DHT.h"  // Inclui a biblioteca DHT para usar com o sensor de temperatura e umidade

#define dht_type DHT11  // Define o tipo de sensor DHT como DHT11

int dht_pin = A0;  // Define o pino analógico A0 como a entrada do sensor DHT
DHT dht_1 = DHT(dht_pin, dht_type);  // Cria um objeto DHT chamado dht_1, associado ao pino dht_pin e ao tipo dht_type

void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial a 9600 bps
  dht_1.begin();  // Inicia o sensor DHT
}

void loop() {
  float umidade = dht_1.readHumidity();  // Lê a umidade do ar e armazena na variável 'umidade'
  float temperatura = dht_1.readTemperature();  // Lê a temperatura do ar e armazena na variável 'temperatura'
  float UmidadeMin = 60;  // Define o limite mínimo de umidade desejado
  float UmidadeMax = 80;  // Define o limite máximo de umidade desejado
  float TemperaturaMin = 15;  // Define o limite mínimo de temperatura desejado
  float TemperaturaMax = 20;  // Define o limite máximo de temperatura desejado
  
  if (isnan(temperatura) || isnan(umidade)) {  // Verifica se os valores de temperatura ou umidade não são números (NaN)
    Serial.println("Erro ao ler");  // Exibe mensagem de erro no monitor serial
  } else {
    Serial.print(UmidadeMin);  // Envia o limite mínimo de umidade para o monitor serial
    Serial.print(", ");
    Serial.print(umidade);  // Envia a umidade atual para o monitor serial
    Serial.print(", ");
    Serial.print(UmidadeMax);  // Envia o limite máximo de umidade para o monitor serial
    Serial.print(", ");
    Serial.print(TemperaturaMin);  // Envia o limite mínimo de temperatura para o monitor serial
    Serial.print(", ");
    Serial.print(temperatura);  // Envia a temperatura atual para o monitor serial
    Serial.println(TemperaturaMax);  // Envia o limite máximo de temperatura e inicia uma nova linha no monitor serial
  }
  delay(2000);  // Pausa a execução do loop por 2000 milissegundos (2 segundos)
}
