# ⏰ Relógio Digital com PIC18F4550

Este projeto implementa um **relógio digital** utilizando o microcontrolador **PIC18F4550**, exibindo as horas no formato **HH:MM:SS** em **6 displays de 7 segmentos** multiplexados. O sistema realiza a contagem automática das 24 horas e reinicia após 23:59:59.

![image](https://github.com/user-attachments/assets/1aa3da36-48fb-4cb5-87cd-b4e804e0e2e0)

## 🔧 Funcionalidades

- Contagem de tempo no formato **HH:MM:SS**
- **Multiplexação** de 6 displays de 7 segmentos
- **Botão de reset** para reiniciar a contagem a partir de 00:00:00
- **Botão de pausa/resume** para controlar a execução do relógio
- **Botões de ajuste individual**:
  - Dezena e unidade das **horas**
  - Dezena e unidade dos **minutos**
  - Dezena dos **segundos**
- Implementação baseada em **interrupção do timer0**

## 🛠️ Tecnologias e Componentes

- Microcontrolador: **PIC18F4550**
- Displays: **6x 7 segmentos cátodo comum**
- Botões: **7 botões push-button**
- Linguagem: **C**
- Compilador: **CCS C Compiler**
- Ambiente de desenvolvimento: MPLAB X ou CCS IDE

## 📷 Demonstração

> [Vídeo](https://www.linkedin.com/posts/thiago-de-sena-developer_sistemasembarcados-microcontroladores-pic18f4550-activity-7338991131319230464-XRJ6?utm_source=share&utm_medium=member_desktop&rcm=ACoAACpYVukBohxwtwywUm6Qfh3NmcSkoVMBxIs) 


## 📂 Estrutura do Código

### Interrupção `timer0`
A contagem é realizada em tempo real com base na interrupção do `timer0`. O sistema alterna a exibição entre os 6 dígitos para manter o consumo de energia e otimizar o uso de pinos.

### Variáveis de controle
```c
num5,num4 -> Horas
num3,num2 -> Minutos
num1,num  -> Segundos
```

## Desenvolvedores

[<img src="https://avatars.githubusercontent.com/u/110785400?v=4" width=115><br><sub>Thiago De Sena</sub>](https://www.linkedin.com/in/thiago-de-sena-ab5b09179/)
