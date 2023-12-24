#include <Arduino.h>

int sensor_A0 = A0;    // podłączenie od A0 na czujniku do A0 na Arduino
int sensor_D0 = 2;     // podłączenie od D0 na czujniku do pinu 2 na Arduino
int A0_value;        // zmienna dla wartości A0
int D0_value;        // zmienna dla wartości A0
 
void setup() {
  Serial.begin(9600);   // uruchomienie monitora szeregowego
 pinMode(2, INPUT);    // ustawienie pinu 2 jako wejście
 
}
 
void loop() {
 
 A0_value = analogRead(sensor_A0);      // pobranie wartości z A0
 D0_value = digitalRead(sensor_D0);     // pobranie wartości z D0
 
 Serial.print("D0: ");                    // wyświetlenie na monitorze szeregowym
 Serial.print(D0_value);
 Serial.print("  --  A0: ");
 Serial.println(A0_value);
 delay(200);                              // opóźnienie pomiędzy kolejnymi odczytami
 } 