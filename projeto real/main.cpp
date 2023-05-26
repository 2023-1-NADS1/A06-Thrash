#include <WiFi.h> // As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento
#include <HTTPClient.h>  // As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento

// As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento
// As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento
// As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento
// As bibliotecas não estão inclusas nesse commit, se precisar, pode baixá-las para teste de funcionamento

// Defina as credenciais da sua rede WiFi
const char* ssid = "vamos inserir o wifi";
const char* senha = "vamos inserir a senha do wifi";

// Defina o endereço do servidor HTTP
const char* servidor_http = "servidor";
const int porta_http = 80;
const char* rota_http = "/enviar-dados";

// Definindo as portas do ESP32 que serão usadas para o pino de disparo e o pino de eco do sensor ultrassônico
const int pinoDisparo = 14;
const int pinoEco = 12;

// Definindo a velocidade do som em cm/us como uma constante. Isso é usado para calcular a distância.
#define VELOCIDADE_SOM 0.034

// Altura total da lixeira em cm.
#define ALTURA_LIXEIRA 50

// Variáveis ​​para armazenar a duração do sinal de eco, a distância calculada e o nível do lixo
long duracao;
int distanciaCm;
int nivelLixo;
int percentualNivelLixo;

void configurar_wifi() {
  delay(10);
  WiFi.begin(ssid, senha);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi..");
  }

  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  configurar_wifi();
  pinMode(pinoDisparo, OUTPUT); 
  pinMode(pinoEco, INPUT); 
}

void loop() {
  // Restante do código para medir a distância e o nível de lixo

  // Depois de calcular a distância e o nível do lixo, envie os dados para o servidor HTTP
  String url = String(servidor_http) + String(rota_http) + "?nivelLixo=" + String(nivelLixo) + "&percentualNivelLixo=" + String(percentualNivelLixo);

  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();

  if (httpResponseCode == HTTP_CODE_OK) {
    Serial.println("Dados enviados com sucesso para o servidor HTTP");
  } else {
    Serial.print("Falha ao enviar dados para o servidor HTTP. Código de resposta: ");
    Serial.println(httpResponseCode);
  }

  http.end();

  delay(5000);  // Espere 5 segundos antes de enviar novamente
}
