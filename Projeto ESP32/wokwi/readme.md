# Projeto de Sensor Ultrassônico com ESP32 no Wokwi

Este README descreve o projeto simulado no Wokwi, uma plataforma online de simulação de hardware. O projeto é uma simulação de um sensor ultrassônico HC-SR04 conectado a um ESP32. A simulação demonstra como medir a distância entre o sensor e um objeto, com a distância sendo exibida na saída serial.

## Componentes

- ESP32 Padrão do Wokwi
- Sensor ultrassônico HC-SR04
- Jumpers
- Resistor Padrão do Wokwi

## Conexões

As conexões entre os componentes na simulação são as seguintes:

- Alimentação do sensor HC-SR04 (VCC) conectada ao 3V3 do ESP32.
- Terra do sensor HC-SR04 (GND) conectado ao GND do ESP32.
- Pino ECHO do sensor HC-SR04 conectado ao GPIO 19 do ESP32.
- Pino TRIG do sensor HC-SR04 conectado ao GPIO 18 do ESP32.

## Código

O código para a simulação no Wokwi está disponível no link: [https://wokwi.com/projects/365748885542761473](https://wokwi.com/projects/365748885542761473)

## Diferenças em relação ao projeto real

A principal diferença entre a simulação no Wokwi e o projeto real está na alimentação do sensor ultrassônico. Na simulação, o sensor é alimentado pela saída de 3.3V do ESP32. No entanto, no projeto real, o sensor é alimentado pela saída de 5V do ESP32.

Além disso, no projeto real, o pino ECHO do sensor retorna um sinal de 5V. Como o ESP32 opera a 3.3V, esse sinal precisa ser reduzido para evitar danos ao microcontrolador. Para fazer isso, é usado um resistor para reduzir a tensão do sinal de ECHO de 5V para 3.3V.
