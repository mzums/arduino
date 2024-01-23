#include <Arduino.h>

int IRSensor1 = PB9;
int IRSensor2 = PB13;
int LED1 = PB8;
int LED2 = PB12;

void setup(){
  Serial.begin(115200);
  Serial.println("Serial Working");
  pinMode(IRSensor1, INPUT);
  pinMode(IRSensor2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop(){
  int sensorStatus1 = digitalRead(IRSensor1);
  int sensorStatus2 = digitalRead(IRSensor2);
  Serial.println(sensorStatus1);

  if (sensorStatus1 == HIGH) {
    digitalWrite(LED1, HIGH);
    Serial.println("Motion Detected!");
  } else {
    digitalWrite(LED1, LOW);
    Serial.println("Motion Ended!");
  }
  if (sensorStatus2 == HIGH) {
    digitalWrite(LED2, HIGH);
    Serial.println("Motion Detected!");
  } else {
    digitalWrite(LED2, LOW);
    Serial.println("Motion Ended!");
  }
}
