#include <Arduino.h>
#include <DHT.h>
#define DHT11_PIN 2
#define DHTTYPE DHT11

dht DHT;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}