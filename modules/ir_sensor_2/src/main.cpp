#include <Arduino.h>

int IRSensor = 10; // connect IR sensor module to Arduino pin D9
int LED = 13; // connect LED to Arduino pin 13

void setup(){
  Serial.begin(115200); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
}

void loop(){
  int sensorStatus = digitalRead(IRSensor); // Read the state of the GPIO pin
  Serial.println(sensorStatus);

  if (sensorStatus == HIGH) {
    digitalWrite(LED, LOW); // Turn off the onboard LED
    Serial.println("Motion Detected!"); // Print "Motion Detected!" on the serial monitor window
  } else {
    digitalWrite(LED, HIGH); // Turn on the onboard LED
    Serial.println("Motion Ended!"); // Print "Motion Ended!" on the serial monitor window
  }

  delay(1000); // Delay for 1 second (optional, to avoid too rapid serial prints)
}
