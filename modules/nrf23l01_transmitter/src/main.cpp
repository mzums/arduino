/*#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Ustawienia modułu nRF24L01
const uint8_t cePin = 9;  // CE Pin
const uint8_t csPin = 10; // CSN Pin

RF24 radio(cePin, csPin);  // CE, CSN

// Adres, przez który dwa moduły komunikują się ze sobą.
const byte address[6] = "00001";

void setup() {
  SPI.begin();  // Inicjalizacja SPI
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.begin(115200);
  Serial.println("Hello, World!");
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(4, 23);  // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
}
void loop() {
  const char text[] = "HOW YOU DOIN"; //message
  radio.write(&text, sizeof(text));
  delay(1000);
}

