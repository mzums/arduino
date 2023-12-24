#include <Arduino.h>

int btn1, btn2;
bool led;
String text = "";

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT);
  digitalWrite(2, LOW);
  led = false;
}

void loop() {
  btn1 = digitalRead(3);
  btn2 = digitalRead(4);

  if (btn1 == LOW) led = true;
  if (btn2 == HIGH) led = false;

  if (Serial.available() > 0) {
    text = Serial.readStringUntil('\n');
    Serial.println(text);
    if (text.equals("on")) led = true;
    else if (text.equals("off")) led = false;
  }

  if (led) digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);

  //Serial.println(btn1);
}