// Definindo as portas do ESP32 que serão usadas para o pino de disparo e o pino de eco do sensor ultrassônico
const int pinoDisparo = 18;
const int pinoEco = 19;

// Definindo a velocidade do som em cm/us como uma constante. Isso é usado para calcular a distância.
#define VELOCIDADE_SOM 0.034

// Variáveis ​​para armazenar a duração do sinal de eco e a distância calculada
long duracao;
int distanciaCm;

void setup() {
  // Inicializa a comunicação serial com uma taxa de transmissão de 115200
  Serial.begin(115200);

  // Configura o pino de disparo como saída e o pino de eco como entrada
  pinMode(pinoDisparo, OUTPUT); 
  pinMode(pinoEco, INPUT); 
}

void loop() {
  // Limpa o pino de disparo, coloca-o em estado baixo
  digitalWrite(pinoDisparo, LOW);
  // Aguarda 2 microssegundos
  delayMicroseconds(2);

  // Coloca o pino de disparo em estado alto por 10 microssegundos
  digitalWrite(pinoDisparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoDisparo, LOW);

  // Lê o pino de eco, a função pulseIn() retorna o tempo de viagem da onda sonora em microssegundos
  /* OBS: Por conta de limitações do Wokwi, não há como detectar objetos com o pulso sonoro, visto que
  é apenas um simulador virtual.
  Um meio de testar isso é trocar o "pulseIn(pinoEco, HIGH)" por um valor fixo, como por exemplo, 3500,
  que irá retornar a distância 59.
  Fique à vontade para alterar na variável abaixo
  | | | | | | | | | | | | | | | | 
  V V V V V V V V V V V V V V V V  */
  
  duracao = pulseIn(pinoEco, HIGH);

  // Calcula a distância em cm com base na velocidade do som e no tempo de viagem
  distanciaCm = duracao * VELOCIDADE_SOM/2;

  // Imprime a distância em cm no monitor serial
  Serial.print("Distância (cm): ");
  Serial.println(distanciaCm);

  // Aguarda 10 milissegundos antes da próxima leitura
  delay(10);
}