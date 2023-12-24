#include <Arduino.h>

int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int r = analogRead(A0);
  float light = map(r, 0, 1023, 0, 100);
  Serial.println(light);

  digitalWrite(RedPin, 191);
  digitalWrite(GreenPin, 0);
  digitalWrite(BluePin, 50);

  if (light < 1) {
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, HIGH);
  }
  else if (light < 5) {
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, HIGH);
    digitalWrite(BluePin, LOW);
  }
  else {
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, LOW);
  }
}