#include <Wire.h> // Biblioteca necessária para comunicação I2C
#include <LiquidCrystal_I2C.h> // Biblioteca necessária para usar o display LCD

// Inicializando o display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço I2C do display LCD é 0x27, e ele possui 16 colunas e 2 linhas

// Pinos para o sensor ultrassônico
const int pinoDisparo = 14; // Pino de disparo do sensor ultrassônico
const int pinoEco = 12; // Pino de eco do sensor ultrassônico

// Pino para o sensor PIR (Presença)
const int pinoPIR = 13; // Pino do sensor de presença (PIR)

// Pino para o módulo de som (Buzzer)
const int pinoBuzzer = 15; // Pino do buzzer (módulo de som)

// Constantes
#define VELOCIDADE_SOM 0.034 // Velocidade do som em cm/us
#define ALTURA_LIXEIRA 50 // Altura da lixeira em cm
#define LIMITE_SUPERIOR 85 // Limite de preenchimento da lixeira em %

// Variáveis
long duracao; // Duração do pulso do sensor ultrassônico
int distanciaCm; // Distância medida pelo sensor ultrassônico
int nivelLixo; // Nível de lixo na lixeira
int percentualNivelLixo; // Percentual de preenchimento da lixeira
bool temAlguemPerto = false; // Variável que irá guardar se tem alguém perto ou não

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  
  // Configura os pinos como entrada ou saída
  pinMode(pinoDisparo, OUTPUT); // Pino de disparo do sensor ultrassônico como saída
  pinMode(pinoEco, INPUT); // Pino de eco do sensor ultrassônico como entrada
  pinMode(pinoPIR, INPUT); // Pino do sensor de presença como entrada
  pinMode(pinoBuzzer, OUTPUT); // Pino do buzzer como saída
  
  // Inicia o display LCD
  lcd.begin(16, 2); 
}

void loop() {
  // Lê o valor do sensor PIR
  temAlguemPerto = digitalRead(pinoPIR);
  
  // Se alguém estiver perto, realiza a medição do nível de lixo
  if(temAlguemPerto){
    digitalWrite(pinoDisparo, LOW); // Gera um pulso de disparo do sensor ultrassônico
    delayMicroseconds(2);
    digitalWrite(pinoDisparo, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinoDisparo, LOW);
  
    duracao = pulseIn(pinoEco, HIGH); // Mede a duração do pulso do eco
    distanciaCm = duracao * VELOCIDADE_SOM / 2; // Converte a duração do pulso em distância
  
    nivelLixo = ALTURA_LIXEIRA - distanciaCm; // Calcula o nível de lixo
    percentualNivelLixo = (nivelLixo * 100) / ALTURA_LIXEIRA; // Calcula o percentual de preenchimento da lixeira

    lcd.clear(); // Limpa o display LCD
    lcd.setCursor(0, 0); // Posiciona o cursor no início da primeira linha
    lcd.print("Nivel atual do"); // Escreve no display
    lcd.setCursor(0, 1); // Posiciona o cursor no início da segunda linha

    // Caso o nível de lixo esteja acima do limite superior, aciona o alerta sonoro
    if (percentualNivelLixo > LIMITE_SUPERIOR) {
      lcd.print("lixo: ");
      lcd.print(percentualNivelLixo);
      lcd.print("%");
      lcd.setCursor(0, 3);
      lcd.print("Retire o lixo!");

      // Aviso sonoro
      digitalWrite(pinoBuzzer, HIGH); // Liga o buzzer
      delay(1000); // Mantém o buzzer ligado por 1 segundo
      digitalWrite(pinoBuzzer, LOW); // Desliga o buzzer
    } else {
      lcd.print("lixo: ");
      lcd.print(percentualNivelLixo);
      lcd.print("%");
      lcd.setCursor(0, 3);
      lcd.print("Nao precisa retirar!"); // Informa que a lixeira não precisa ser esvaziada
    }

    delay(5000); // Espera 5 segundos antes de realizar a próxima medição
  }
}
