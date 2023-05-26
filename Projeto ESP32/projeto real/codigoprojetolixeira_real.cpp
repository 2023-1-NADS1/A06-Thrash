// Definindo as portas do ESP32 que serão usadas para o pino de disparo e o pino de eco do sensor ultrassônico
const int trigPin = 14;  // Conectado ao pino TRIG do sensor
const int echoPin = 12;  // Conectado ao pino ECHO do sensor

// Definindo a velocidade do som em cm/us como uma constante. Isso é usado para calcular a distância.
#define SOUND_SPEED 0.034

// Variáveis ​​para armazenar a duração do sinal de eco e a distância calculada
long duracao;
int distanciaCm;

void setup() {
  // Inicializa a comunicação serial com uma taxa de transmissão de 115200
  Serial.begin(115200);

  // Configura o pino de disparo como saída e o pino de eco como entrada
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() {
  // Limpa o pino de disparo, coloca-o em estado baixo
  digitalWrite(trigPin, LOW);
  // Aguarda 2 microssegundos
  delayMicroseconds(2);

  // Coloca o pino de disparo em estado alto por 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o pino de eco, a função pulseIn() retorna o tempo de viagem da onda sonora em microssegundos
  duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância em cm com base na velocidade do som e no tempo de viagem
  distanciaCm = duracao * SOUND_SPEED / 2;

  // Imprime a distância em cm no monitor serial
  Serial.print("Distância (cm): ");
  Serial.println(distanciaCm);

  // Aguarda 10 milissegundos antes da próxima leitura
  delay(10);
}
