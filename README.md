# Porta Automática

Um porta automática feita usando o Arduino uno R3 um servo motor de 180º e um sensor ultrasonico HC-SR04.

![Montagem](portaautomatica/montagemporta.png)


# Como funciona

A porta vai se abrir com base na distância que o sensor ultrasonico medir se a distância for menor que a que estive no código o servo abrirá a porta, senão fechará ou permanecera fechada e ao transicionar de aberto para fechado ele terá um delay por segurança para não fechar emcima da pessoa.
