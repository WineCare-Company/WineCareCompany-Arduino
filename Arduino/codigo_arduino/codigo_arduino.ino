#include "DHT.h" // Inclui a biblioteca DHT para lidar com o sensor DHT

#define dht_type DHT11 // Define o tipo de sensor DHT utilizado, neste caso o DHT11

int dht_pin = A0; // Define o pino analógico A0 como o pino de entrada de dados do sensor DHT
DHT dht_1 = DHT(dht_pin, dht_type);// Inicializa o sensor DHT com o pino definido e o tipo


void setup() { // Função setup que configura o microcontrolador
  
  Serial.begin(9600); // Inicializa a comunicação serial com uma taxa de 9600 bauds
  dht_1.begin();  // Inicializa o sensor DHT
}


void loop() { // Função loop que é executada repetidamente

  float umidade = dht_1.readHumidity();   // Lê a umidade do sensor DHT e armazena na variável umidade
  float temperatura = dht_1.readTemperature(); // Lê a temperatura do sensor DHT e armazena na variável temperatura
  
  if (isnan(temperatura) or isnan(umidade)) { // Verifica se as leituras de temperatura ou umidade são números inválidos (NaN)
    Serial.println("Erro ao ler"); // Imprime uma mensagem de erro no monitor serial se não conseguir ler os dados
  } else { // Caso contrário, imprime a umidade seguida de uma vírgula e a temperatura
    Serial.print(umidade);
    Serial.print(",");
    Serial.println(temperatura); 
  }
  delay(2000); // Pausa a execução por 2000 milissegundos (2 segundos)
}
