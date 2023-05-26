
# Projeto de Sensor Ultrassônico com ESP32

Este projeto utiliza um sensor ultrassônico HC-SR04 e um microcontrolador ESP32 para medir distâncias. O código foi desenvolvido e testado tanto em um ambiente de simulação (Wokwi) quanto em um ambiente de hardware real.

## Simulação vs Realidade

Existem algumas diferenças importantes entre a execução do código em uma simulação e a execução do código em um ambiente de hardware real.

1. **Simulação de Hardware**: No ambiente de simulação, o hardware é representado virtualmente. Isso significa que alguns aspectos do hardware, como ruído elétrico ou características físicas dos componentes, não são representados. No ambiente real, esses fatores podem ter um impacto e precisam ser considerados.

2. **Resistores**: Na simulação do Wokwi, os resistores são ignorados na simulação de circuitos analógicos. No ambiente real, os resistores são componentes críticos que são usados para, por exemplo, reduzir a tensão no pino ECHO do sensor ultrassônico HC-SR04 de 5V para 3,3V para evitar danificar o microcontrolador ESP32【34†source】.

3. **Funcionalidade pulseIn()**: Na simulação do Wokwi, a função pulseIn() não funciona exatamente como na realidade porque o ambiente de simulação não consegue reproduzir a emissão e o retorno do pulso ultrassônico. Na realidade, a função pulseIn() mede o tempo que leva para o sinal ultrassônico emitido pelo sensor retornar, permitindo assim calcular a distância até o objeto detectado.

4. **Pinagem**: Os números dos pinos usados na simulação podem não corresponder aos números dos pinos usados no projeto real, pois a pinagem pode variar entre diferentes modelos de ESP32. No código fornecido, a pinagem foi configurada especificamente para o ESP32 DevKitC - ESP-WROOM-32D, que é o utilizado no projeto real.

## Hardware Real

No ambiente de hardware real, o sensor HC-SR04 está conectado ao ESP32 da seguinte maneira:

- O pino VCC do sensor é conectado ao pino 5V do ESP32.
- O pino GND do sensor é conectado a um pino GND do ESP32.
- O pino ECHO do sensor é conectado ao pino 12 do ESP32.
- O pino TRIG do sensor é conectado ao pino 14 do ESP32.

Além disso, um resistor é usado para reduzir a tensão do pino ECHO do sensor, de 5V para 3.3V, para evitar danos ao ESP32.
