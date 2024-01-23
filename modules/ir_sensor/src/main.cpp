#include <Arduino.h>

int LED = 34; // connect LED to Arduino pin D34

void setup() {
  Serial.begin(115200);
  //Serial.println("Serial Working");
  pinMode(LED, OUTPUT);
}

void loop() {
  //Serial.println("hello");

  digitalWrite(LED, HIGH); // Turn on the LED
  delay(1000);

  digitalWrite(LED, LOW); // Turn off the LED
  delay(1000);
}
