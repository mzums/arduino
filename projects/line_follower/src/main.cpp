#include <Arduino.h>

// Motor A
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 14;
int pwmChannel1 = 0;

// Motor B
int motor2Pin1 = 25;
int motor2Pin2 = 33;
int enable2Pin = 32;
int pwmChannel2 = 1;

// Motor C
int motor3Pin1 = 2;
int motor3Pin2 = 4;
int enable3Pin = 15;
int pwmChannel3 = 2;

// Motor D
int motor4Pin1 = 17;
int motor4Pin2 = 16;
int enable4Pin = 5;
int pwmChannel4 = 3;

int ir1 = 18;
int ir2 = 19;

void setup() {
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

  ledcSetup(pwmChannel1, 30000, 8);
  ledcSetup(pwmChannel2, 30000, 8);
  ledcSetup(pwmChannel3, 30000, 8);
  ledcSetup(pwmChannel4, 30000, 8);

  ledcAttachPin(enable1Pin, pwmChannel1);
  ledcAttachPin(enable2Pin, pwmChannel2);
  ledcAttachPin(enable3Pin, pwmChannel3);
  ledcAttachPin(enable4Pin, pwmChannel4);

  Serial.begin(115200);
}

void loop() {
  int left_sensor = digitalRead(ir1);
  int right_sensor = digitalRead(ir2);

  if (left_sensor == HIGH) {
    serial.println("left");
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    digitalWrite(enable3Pin, LOW);
    digitalWrite(enable4Pin, LOW);
    
    ledcWrite(pwmChannel1, 250);
    ledcWrite(pwmChannel2, 250);
    ledcWrite(pwmChannel3, 0);
    ledcWrite(pwmChannel4, 0);
  } else if (right_sensor == HIGH) {
    serial.println("right");
    digitalWrite(enable1Pin, LOW);
    digitalWrite(enable2Pin, LOW);
    digitalWrite(enable3Pin, HIGH);
    digitalWrite(enable4Pin, HIGH);

    ledcWrite(pwmChannel1, 0);
    ledcWrite(pwmChannel2, 0);
    ledcWrite(pwmChannel3, 230);
    ledcWrite(pwmChannel4, 230);
  }
  else if (left_sensor == LOW && right_sensor == LOW) {
    serial.println("both");
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
    digitalWrite(enable3Pin, HIGH);
    digitalWrite(enable4Pin, HIGH);

    ledcWrite(pwmChannel1, 250);
    ledcWrite(pwmChannel2, 250);
    ledcWrite(pwmChannel3, 230);
    ledcWrite(pwmChannel4, 230);
  } 
}
