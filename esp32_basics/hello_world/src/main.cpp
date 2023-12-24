#include <Arduino.h>

const int ledPin = 18;

void setup() {
  // initialize digital pin GPIO18 as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on
  delay(500);             // wait for 500 milliseconds
  digitalWrite(ledPin, LOW);  // turn the LED off
  delay(500);             // wait for 500 milliseconds
}
