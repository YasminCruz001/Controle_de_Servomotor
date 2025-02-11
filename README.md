# Controle de Servomotor por PWM
Yasmin Damasceno Cruz - TIC370101610  
Unidade 4 - Capítulo 7

Este projeto implementa o controle de um servomotor utilizando o módulo PWM do microcontrolador RP2040. A simulação foi realizada na plataforma Wokwi e integrada ao ambiente de desenvolvimento VSCode. Além do controle do servo, um LED RGB é utilizado para indicar o estado da movimentação do motor.

## Componentes Simulados

- 1x Raspberry Pi Pico W
- 1x Servomotor padrão (Wokwi)
- 1x LED RGB (GPIOs 11, 12 e 13)

## Configuração Inicial

1. Clone o repositório para sua máquina local:
   ```bash
   git clone <https://github.com/YasminCruz001/Controle_de_Servomotor.git>
   ```
2. Abra o projeto no VS Code.
3. Utilize o Wokwi para simular o comportamento do servomotor e do LED RGB.

## Funcionalidades do Projeto

### 1. Configuração do PWM
- O sinal PWM é gerado na **GPIO 22**, com frequência de **50Hz** (período de 20ms).

### 2. Controle de Posições Fixas
- O servomotor é posicionado em três ângulos distintos:
  - **180 graus** → Pulso de **2400µs** (aguarda 5s)
  - **90 graus** → Pulso de **1470µs** (aguarda 5s)
  - **0 graus** → Pulso de **500µs** (aguarda 5s)

### 3. Movimento Suave
- O servo realiza um movimento contínuo entre **0° e 180°**, com incremento de **±5µs** a cada **10ms**, garantindo transições suaves.

### 4. Indicação com LED RGB
- Durante a execução do código, o LED RGB alterna suas cores para indicar mudanças no movimento do servo.

## Requisitos Atendidos

✅ **Frequência do PWM**: Configurada para **50Hz** (período de 20ms).  
✅ **Posições Fixas**: Servo ajustado para **0°, 90° e 180°** com tempos de espera adequados.  
✅ **Movimentação Contínua**: Implementado deslocamento gradual entre 0° e 180°.  
✅ **LED RGB**: Alteração visual conforme a movimentação do servo.  
✅ **Simulação no Wokwi**: Código testado e validado no simulador.  

## Execução

1. Compile e carregue o código na placa Raspberry Pi Pico W.
2. Inicie a simulação no Wokwi.
3. Observe o movimento do servomotor e a alternância de cores do LED RGB.

## Vídeo Demonstrativo