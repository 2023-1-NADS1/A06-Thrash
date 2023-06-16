#define TRIGGER_PIN 12   // Pino de trigger do sensor ultrassônico
#define ECHO_PIN 14      // Pino de echo do sensor ultrassônico
#define BUZZER_PIN 32    // Pino do active buzzer

const int DISTANCE_THRESHOLD = 14;      // Distância limite em cm
const int SIREN_CHANNEL = 0;            // Canal da sirene na biblioteca ledc
const int SIREN_DELAY = 50;             // Atraso entre as frequências da sirene em ms

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  ledcSetup(SIREN_CHANNEL, 5000, 8);  // Configuração do canal da sirene para 8 bits de resolução e frequência de 5 kHz
  ledcAttachPin(BUZZER_PIN, SIREN_CHANNEL);  // Associa o pino do buzzer ao canal da sirene
}

void loop() {
  // Dispara o pulso ultrassônico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Mede a duração do pulso de eco
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calcula a distância em cm
  float distance = duration * 0.034 / 2;

  // Verifica se a distância está abaixo do limite
  if (distance < DISTANCE_THRESHOLD) {
    // Ativa o efeito de sirene
    for (int frequency = 100; frequency <= 2000; frequency += 100) {
      ledcWriteTone(SIREN_CHANNEL, frequency);
      delay(SIREN_DELAY);
    }

    // Desativa a sirene
    ledcWrite(SIREN_CHANNEL, 0);
  }

  // Exibe a distância no console
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(900);  // Aguarda 500 milissegundos antes de realizar a próxima medição
}
