// ************************************
// Código projeto teatro marionetes
// desenvolvido por Lucas Meng
// versão 2.0
// ************************************

// *** inclusão de biblioteca
#include <VarSpeedServo.h>

// *** definições das frequências das notas musicais
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// *** definições dos pinos utilizados
#define BOTAO1_PIN A0
#define BOTAO2_PIN A1
#define BOTAO3_PIN A2
#define BOTAO4_PIN A3
#define BOTAO5_PIN A4
#define BOTAO6_PIN A5
#define RESET_PIN 2
#define BUZZER_INPUT_PIN 10
#define BUZZER_OUTPUT_PIN 9
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
// declaração do estado do botão do buzzer
byte apertado = LOW;

// declaração dos ângulos iniciais dos servos
int servoState1 = 0;
int servoState2 = 0;
int servoState3 = 0;
int servoState4 = 0;
int servoState5 = 0;
int servoState6 = 0;

// declaração do timer de debounce dos botões
unsigned long debounce_timer = 0; 

// declaração da melodia e variáveis da musica
int melody[] = {
    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, REST,8, //1
    NOTE_G5,4, REST,4, NOTE_G4,2,
    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4};

    int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    int tempo = 185;

    int wholenote = (60000 * 4) / tempo;
    int divider = 0, noteDuration = 0;

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
  pinMode(BUZZER_INPUT_PIN, INPUT);
  digitalWrite(BUZZER_INPUT_PIN, HIGH);

  //Definição dos pinmodes dos outputs
  pinMode(BUZZER_OUTPUT_PIN, OUTPUT);
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
  byte buttonState8 = digitalRead(BUZZER_INPUT_PIN);
  
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
  
  //Se o botão do buzzer for apertado:
  if (buttonState8 == LOW && apertado == LOW) {
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

      // calculates the duration of each note
        divider = melody[thisNote + 1];
      if (divider > 0) {
        // regular note, just proceed
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        // dotted notes are represented with negative durations!!
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
      }

      // we only play the note for 90% of the duration, leaving 10% as a pause
      tone(BUZZER_OUTPUT_PIN, melody[thisNote], noteDuration * 0.9);

      // Wait for the specief duration before playing the next note.
      delay(noteDuration);

      // stop the waveform generation before the next note.
      noTone(BUZZER_OUTPUT_PIN);
    }
    
    apertado = HIGH;
  }
  else {
    apertado = LOW;
  }
}