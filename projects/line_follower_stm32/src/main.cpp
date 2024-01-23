#include <Arduino.h>

int IRSensor1 = PB9;
int IRSensor2 = PB13;
int LEDL = PB8;
int LEDR = PB12;

// Motor A
int motor1Pin1 = PA1;
int motor1Pin2 = PA2;
int enable1Pin = PA0;

// Motor B
int motor2Pin1 = PA4;
int motor2Pin2 = PA3;
int enable2Pin = PA5;

// Motor C
int motor3Pin1 = PB2;
int motor3Pin2 = PB1;
int enable3Pin = PB10;

// Motor D
int motor4Pin1 = PB0;
int motor4Pin2 = PA7;
int enable4Pin = PA6;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Working");
  pinMode(IRSensor1, INPUT);
  pinMode(IRSensor2, INPUT);
  pinMode(LEDL, OUTPUT);
  pinMode(LEDR, OUTPUT);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enable3Pin, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enable4Pin, OUTPUT);
}

/*void loop() {
  int sensorStatusL = digitalRead(IRSensor1);
  int sensorStatusR = digitalRead(IRSensor2);
  Serial.println(sensorStatusL);

    digitalWrite(LEDL, HIGH);
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
}*/

void spinL() {
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void spinR() {
  digitalWrite(enable3Pin, HIGH);
  digitalWrite(enable4Pin, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}

void NspinL() {
  digitalWrite(enable1Pin, LOW);
  digitalWrite(enable2Pin, LOW);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void NspinR() {
  digitalWrite(enable3Pin, LOW);
  digitalWrite(enable4Pin, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}

void loop() {
  int sensorStatusL = digitalRead(IRSensor1);
  int sensorStatusR = digitalRead(IRSensor2);
  Serial.println(sensorStatusL);

  if (sensorStatusL == LOW && sensorStatusR == LOW) {
    digitalWrite(LEDL, LOW);
    digitalWrite(LEDR, LOW);
    spinL();
    spinR();
    //NspinL();
  }
  else if (sensorStatusL == LOW) {
    digitalWrite(LEDL, LOW);
    digitalWrite(LEDR, HIGH);
    NspinL();
    spinR();
    /*digitalWrite(enable1Pin, HIGH);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);*/
  }
  else if (sensorStatusR == LOW) {
    digitalWrite(LEDL, HIGH);
    digitalWrite(LEDR, LOW);
    NspinL();
    spinL();
    /*digitalWrite(enable1Pin, HIGH);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);*/
  }
  else {
    digitalWrite(LEDL, HIGH);
    digitalWrite(LEDR, HIGH);
    NspinL();
    NspinR();
  }
}
