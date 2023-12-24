#include <Arduino.h>

int first = 2;
int last = 6;
int speed = 400;
int value = HIGH;
int btn1 = LOW;
bool led;

void setup() {
  Serial.begin(115200);
  for (int i = first; i <= last; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  for (int i = first; i <= last; i++) {
    digitalWrite(i, value);
    delay(speed);
    if(btn1 != HIGH) led = false;
  }
  value = !value;
  if (!led) {
    while (!led) {
      Serial.println(btn1);
      if (btn1 != HIGH) led = true;
      delay(10);
    } 
  }
}