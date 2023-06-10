#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinoDisparo = 14;
const int pinoEco = 12;

#define VELOCIDADE_SOM 0.034
#define ALTURA_LIXEIRA 50
#define LIMITE_SUPERIOR 85

long duracao;
int distanciaCm;
int nivelLixo;
int percentualNivelLixo;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
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

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Nível atual do");
  
  lcd.setCursor(0, 1);

  if (percentualNivelLixo < LIMITE_SUPERIOR) {
    lcd.print("lixo: ");
    lcd.print(percentualNivelLixo);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Não precisa retirar ainda!");
  } else {
    lcd.print("lixo: ");
    lcd.print(percentualNivelLixo);
    lcd.print("%");
    lcd.setCursor(0, 3);
    lcd.print("Retire o lixo!");
  }

  delay(5000);
}
