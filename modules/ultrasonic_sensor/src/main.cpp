#include <Arduino.h>

int trig = 4;
int echo = 6;
int time;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = (time / 2) / 29.1;

  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(500);
}