// ************************************
// Código projeto teatro marionetes
// desenvolvido por Lucas Meng
// versão 2.0
// ************************************

// *** inclusão de biblioteca
#include <VarSpeedServo.h>

// *** definições dos pinos utilizados
#define BOTAO1_PIN A0
#define BOTAO2_PIN A1
#define BOTAO3_PIN A2
#define BOTAO4_PIN A3
#define BOTAO5_PIN A4
#define BOTAO6_PIN A5
#define RESET_PIN 2
#define SERVO1_PIN 8
#define SERVO2_PIN 7
#define SERVO3_PIN 6
#define SERVO4_PIN 5
#define SERVO5_PIN 4
#define SERVO6_PIN 3

// definições de constantes
#define DEBOUNCE_TIME 200
#define SERVO_SPEED 130
#define SERVO_MOVEMENT_DELAY 280

// declaração dos servos
VarSpeedServo servo_1;
VarSpeedServo servo_2;
VarSpeedServo servo_3;
VarSpeedServo servo_4;
VarSpeedServo servo_5;
VarSpeedServo servo_6;

//declaração dos estados dos botões
byte lastButtonState1 = LOW;
byte lastButtonState2 = LOW;
byte lastButtonState3 = LOW;
byte lastButtonState4 = LOW;
byte lastButtonState5 = LOW;
byte lastButtonState6 = LOW;

// declaração dos ângulos iniciais dos servos
int servoState1 = 0;
int servoState2 = 0;
int servoState3 = 0;
int servoState4 = 0;
int servoState5 = 0;
int servoState6 = 0;

// declaração do timer de debounce dos botões
unsigned long debounce_timer = 0; 

void setup()
{
  //Definição dos pinmodes dos inputs
  pinMode(BOTAO1_PIN, INPUT);
  pinMode(BOTAO2_PIN, INPUT);
  pinMode(BOTAO3_PIN, INPUT);
  pinMode(BOTAO4_PIN, INPUT);
  pinMode(BOTAO5_PIN, INPUT);
  pinMode(BOTAO6_PIN, INPUT);
  pinMode(RESET_PIN, INPUT);

  //Definição dos pinmodes dos outputs
  servo_1.attach(SERVO1_PIN);
  servo_2.attach(SERVO2_PIN);
  servo_3.attach(SERVO3_PIN);
  servo_4.attach(SERVO4_PIN);
  servo_5.attach(SERVO5_PIN);
  servo_6.attach(SERVO6_PIN);

  //Reset inicial da posição dos servos
  servo_1.slowmove(0, SERVO_SPEED);
  servo_2.slowmove(0, SERVO_SPEED);
  servo_3.slowmove(0, SERVO_SPEED);
  servo_4.slowmove(0, SERVO_SPEED);
  servo_5.slowmove(0, SERVO_SPEED);
  servo_6.slowmove(0, SERVO_SPEED);

  delay(SERVO_MOVEMENT_DELAY);

  servo_1.detach();
  servo_2.detach();
  servo_3.detach();
  servo_4.detach();
  servo_5.detach();
  servo_6.detach();
}


void loop()
{
  //Leitura dos estados dos inputs
  byte buttonState1 = digitalRead(BOTAO1_PIN);
  byte buttonState2 = digitalRead(BOTAO2_PIN);
  byte buttonState3 = digitalRead(BOTAO3_PIN);
  byte buttonState4 = digitalRead(BOTAO4_PIN);
  byte buttonState5 = digitalRead(BOTAO5_PIN);
  byte buttonState6 = digitalRead(BOTAO6_PIN);
  byte buttonState7 = digitalRead(RESET_PIN);
  
  //Se o botão 1 for apertado:
  if (buttonState1 != lastButtonState1) {
    if (millis() > debounce_timer) {
      lastButtonState1 = buttonState1;
      if (buttonState1 == HIGH) {
        servoState1 = (servoState1 == 90) ? 0: 90;
        servo_1.attach(SERVO1_PIN);
        servo_1.slowmove(servoState1, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_1.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão 2 for apertado:
  if (buttonState2 != lastButtonState2) {
    if (millis() > debounce_timer) {
      lastButtonState2 = buttonState2;
      if (buttonState2 == HIGH) {
        servoState2 = (servoState2 == 90) ? 0: 90;
        servo_2.attach(SERVO2_PIN);
        servo_2.slowmove(servoState2, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_2.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão 3 for apertado:
  if (buttonState3 != lastButtonState3) {
    if (millis() > debounce_timer) {
      lastButtonState3 = buttonState3;
      if (buttonState3 == HIGH) {
        servoState3 = (servoState3 == 90) ? 0: 90;
        servo_3.attach(SERVO3_PIN);
        servo_3.slowmove(servoState3, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_3.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão 4 for apertado:
  if (buttonState4 != lastButtonState4) {
    if (millis() > debounce_timer) {
      lastButtonState4 = buttonState4;
      if (buttonState4 == HIGH) {
        servoState4 = (servoState4 == 90) ? 0: 90;
        servo_4.attach(SERVO4_PIN);
        servo_4.slowmove(servoState4, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_4.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão 5 for apertado:
  if (buttonState5 != lastButtonState5) {
    if (millis() > debounce_timer) {
      lastButtonState5 = buttonState5;
      if (buttonState5 == HIGH) {
        servoState5 = (servoState5 == 90) ? 0: 90;
        servo_5.attach(SERVO5_PIN);
        servo_5.slowmove(servoState5, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_5.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão 6 for apertado:
  if (buttonState6 != lastButtonState6) {
    if (millis() > debounce_timer) {
      lastButtonState6 = buttonState6;
      if (buttonState6 == HIGH) {
        servoState6 = (servoState6 == 90) ? 0: 90;
        servo_6.attach(SERVO6_PIN);
        servo_6.slowmove(servoState6, SERVO_SPEED);
        delay(SERVO_MOVEMENT_DELAY);
        servo_6.detach();
      }
      debounce_timer = millis() + DEBOUNCE_TIME;
    }
  }
  
  //Se o botão reset for apertado:
  if (buttonState7 == HIGH) {
    servoState1 = 0;
    servoState2 = 0;
    servoState3 = 0;
    servoState4 = 0;
    servoState5 = 0;
    servoState6 = 0;

    servo_1.attach(SERVO1_PIN);
    servo_2.attach(SERVO2_PIN);
    servo_3.attach(SERVO3_PIN);
    servo_4.attach(SERVO4_PIN);
    servo_5.attach(SERVO5_PIN);
    servo_6.attach(SERVO6_PIN);

    //Reset inicial da posição dos servos
    servo_1.slowmove(0, SERVO_SPEED);
    servo_2.slowmove(0, SERVO_SPEED);
    servo_3.slowmove(0, SERVO_SPEED);
    servo_4.slowmove(0, SERVO_SPEED);
    servo_5.slowmove(0, SERVO_SPEED);
    servo_6.slowmove(0, SERVO_SPEED);

    delay(SERVO_MOVEMENT_DELAY);

    servo_1.detach();
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
    servo_6.detach();
  }
}