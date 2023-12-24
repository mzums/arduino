#include <Arduino.h>

int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  digitalWrite(RedPin, 191);
  digitalWrite(GreenPin, 0);
  digitalWrite(BluePin, 50);
}