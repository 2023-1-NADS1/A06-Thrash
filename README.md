# FECAP - Fundação de Comércio Álvares Penteado

<p align="center">
<a href= "https://www.fecap.br/"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRhZPrRa89Kma0ZZogxm0pi-tCn_TLKeHGVxywp-LXAFGR3B1DPouAJYHgKZGV0XTEf4AE&usqp=CAU" alt="FECAP - Fundação de Comércio Álvares Penteado" border="0"></a>
</p>

# Lixeira com sensor de nível de lixo

## Thrash

## Integrantes: 
- Nathan
- Thiago
- Jean
- Pedro
- Demétrio
- Mauro

## Professores Orientadores: 

- Professor Victor
- Professor Adriano

## Descrição

O Sistema de Monitoramento de Lixeiras é uma solução inovadora que combina tecnologia de Internet das Coisas (IoT) e microcontroladores para gerenciar eficientemente a coleta de resíduos. O núcleo do sistema é o microcontrolador ESP32, que é equipado com um sensor ultrassônico para medir a distância até o lixo na lixeira. A distância medida é então usada para calcular o nível atual de lixo, que é expresso como um percentual da altura total da lixeira.

Uma vez calculado, o nível do lixo é enviado via Wi-Fi para um servidor HTTP. Isso permite o monitoramento remoto do nível de lixo, facilitando o planejamento de coletas de lixo e prevenindo a superlotação de lixeiras. A implementação desse sistema pode trazer eficiências significativas para empresas de gestão de resíduos e cidades inteligentes, melhorando a gestão de resíduos e contribuindo para um ambiente mais limpo e sustentável.



O projeto é um Sistema de Monitoramento de Lixeiras baseado em IoT usando o microcontrolador ESP32. O objetivo do sistema é medir o nível de lixo dentro de uma lixeira e enviar essas informações para um servidor HTTP. O ESP32 é equipado com um sensor ultrassônico que mede a distância até o lixo, que é então usada para calcular o nível de lixo na lixeira. Esse nível de lixo é então enviado para um servidor HTTP para monitoramento e análise. O sistema pode ser útil para empresas de gestão de resíduos e cidades inteligentes, permitindo a coleta eficiente de lixo e a redução do excesso de resíduos.
<br><br>

## 🛠 Estrutura de Pastas

O repositório está organizado nas seguintes pastas principais:

- `wokwi/`: Esta pasta contém a versão simulada do projeto, que é destinada a ser executada na plataforma Wokwi. Ela inclui todos os arquivos necessários para a simulação e pode conter algumas alterações para se adaptar ao ambiente de simulação.

- `projeto_real/`: Esta pasta contém os arquivos que estão sendo realmente usados no ESP32 físico. Estes são os arquivos do projeto que são executados fora do ambiente controlado de simulação.

Cada uma dessas pastas contém seus próprios arquivos de código e recursos, e cada uma é independente uma da outra. Isso permite que você trabalhe na versão simulada e na versão física do projeto de forma independente, sem interferir uma na outra.

## 🛠 Instalação

Não é necessária instalação, os softwares utilizados e libs estão no próximo tópico!
Favor, caso deseje testar o projeto, siga os passos citados lá.

## 💻 Configuração para Desenvolvimento

Para trabalhar com este projeto, você precisará das seguintes ferramentas:

1. **IDE do Arduino**: Esta é a interface de desenvolvimento usada para programar o ESP32. Você pode baixá-lo [aqui](https://www.arduino.cc/en/software).

2. **Placa ESP32**: Você precisará ter a placa ESP32 física para testar seu código. Está disponível em várias lojas online.

3. **Bibliotecas Arduino**: As bibliotecas "WiFi.h" e "HTTPClient.h" são necessárias para este projeto. Eles podem ser instalados através do gerenciador de bibliotecas do IDE do Arduino. Vá para "Sketch" > "Incluir Biblioteca" > "Gerenciar Bibliotecas..." e então procure e instale essas bibliotecas.

Agora, para executar um conjunto de testes automatizado, você precisará de uma biblioteca de testes unitários como o ArduinoUnit. Para instalá-lo, siga as mesmas etapas acima e procure por "ArduinoUnit". Uma vez instalado, você pode escrever testes para várias partes do seu código e executá-los usando a função "Test::run()". 

Por favor, observe que este projeto não inclui um conjunto de testes predefinido, então você precisará escrever seus próprios testes para as funções e características específicas que deseja testar.

Por fim, para carregar o código para o ESP32, você precisará conectar o ESP32 ao seu computador via USB, selecionar a placa ESP32 e a porta correta no IDE do Arduino e então clicar no botão "Carregar" para carregar o código para o ESP32.

Esses passos devem ser os mesmos para a maioria das plataformas, incluindo Windows, macOS e Linux, uma vez que o IDE do Arduino é uma aplicação multiplataforma.

## 🗃 Histórico de lançamentos

* 0.0.1 - 26/05/2022
    * Trabalho em andamento

## 📋 Licença/License

O projeto ainda está em desenvolvimento, por isso ainda não tem uma licença associada. Futuras atualizações definirão a licença sob a qual o projeto será disponibilizado.

## 🎓 Referências

- [Documentação oficial do ESP32]
- [Biblioteca WiFi para ESP32]
- [Biblioteca HTTPClient para ESP32]







