#include <WiFi.h>  
#include <HTTPClient.h>  

const char* ssid = "vamos inserir o wifi";  
const char* senha = "vamos inserir a senha do wifi";  

const char* servidor_http = "servidor";  
const int porta_http = 80;  
const char* rota_http = "/enviar-dados";  

const int pinoDisparo = 14;  
const int pinoEco = 12;  

#define VELOCIDADE_SOM 0.034  
#define ALTURA_LIXEIRA 50  

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
  digitalWrite(pinoDisparo, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoDisparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoDisparo, LOW);

  duracao = pulseIn(pinoEco, HIGH);

  distanciaCm = duracao * 0.034 / 2;

  nivelLixo = ALTURA_LIXEIRA - distanciaCm;
  percentualNivelLixo = (nivelLixo * 100) / ALTURA_LIXEIRA;

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

  delay(5000); // Espere 5 segundos antes de enviar novamente
}
