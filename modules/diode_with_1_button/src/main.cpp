#include <Arduino.h>

int btn1;
bool led;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  btn1 = digitalRead(3);
  if (btn1 == LOW) led = true;
  if (led) digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);

  //Serial.println(btn1);
}