#include <Arduino.h>

int counter = 0;

void setup()
{
  Serial.print("hello");
  /*pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);*/
}

void loop()
{
  /*counter = 0;
  Serial.print("?");
  analogWrite(5, 0);
  analogWrite(6, 0);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);*/
  for (counter = 1; counter <= 255; counter += 1) {
    Serial.print("hi");
    /*analogWrite(5, counter);
    analogWrite(6, counter);*/
    delay(100); // Wait for 100 millisecond(s)
  }
}