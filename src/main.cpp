#include <Arduino.h>
#include <Servo.h>

Servo meuServo1;
Servo meuServo2;
Servo meuServo3;
Servo meuServo4;

void setup() {
  Serial.begin(9600);
  meuServo1.attach(9); // Conecte o fio de sinal do servo no Pino 9
  meuServo2.attach(10);
  meuServo3.attach(11);
  meuServo4.attach(12);
  meuServo1.write(0);  // Posição inicial
  meuServo2.write(0);  // Posição inicial
  meuServo3.write(0);  // Posição inicial
  meuServo4.write(0);  // Posição inicial
}

void loop() {
  if (Serial.available() > 0) {
    char sinal = Serial.read();

    if (sinal == 'F') {
      meuServo1.write(180); // Ângulo para abrir (ajuste se necessário)
      meuServo2.write(180);
      meuServo3.write(180);
      meuServo4.write(180);
    } 
    else if (sinal == 'A') {
      meuServo1.write(0);   // Ângulo para fechar
      meuServo2.write(0);
      meuServo3.write(0);
      meuServo4.write(0);
    }
    else if (sinal == 'U') {
      meuServo1.write(180);
      meuServo2.write(0);
      meuServo3.write(0);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'D') {
      meuServo1.write(180);
      meuServo2.write(180);
      meuServo3.write(0);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'T') {
      meuServo1.write(180);
      meuServo2.write(180);
      meuServo3.write(180);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'P') {
      meuServo1.write(180);
      meuServo2.write(0);
      meuServo3.write(0);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'S') {
      meuServo1.write(0);
      meuServo2.write(180);
      meuServo3.write(0);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'E') {
      meuServo1.write(0);
      meuServo2.write(0);
      meuServo3.write(180);
      meuServo4.write(0);   // Ângulo para fechar
    }
    else if (sinal == 'Q') {
      meuServo1.write(0);
      meuServo2.write(0);
      meuServo3.write(0);
      meuServo4.write(180);   // Ângulo para fechar
    }
    else if (sinal == 'G') {
      meuServo1.write(0);
      meuServo2.write(0);
      meuServo3.write(0);
      meuServo4.write(0);
      delay(500);
      meuServo1.write(180);
      delay(500);
      meuServo2.write(180);
      delay(500);
      meuServo3.write(180);
      delay(500);
      meuServo4.write(180);
      delay(500); 
      meuServo4.write(0);
      delay(500);
      meuServo3.write(0);
      delay(500);
      meuServo2.write(0);
      delay(500);
      meuServo1.write(0);
      delay(500);
    }
  }
}