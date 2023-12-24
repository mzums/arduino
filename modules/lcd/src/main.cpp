#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String text = "BUAHAHAHAHA!!! ";
String empty = "                ";
int i = 16;

byte smile[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.print("I will kill you!");
  /*lcd.setCursor(13, 1);
  lcd.write(byte(0));
  lcd.createChar(0, smile);*/
}

void loop() {
  lcd.setCursor(i, 1);
  lcd.print(text);
  delay(300);
  if (i > 0)
    i--;
  else if (i == 0) {
    i = 16;
    lcd.setCursor(0, 1);
    lcd.print(empty);
  }
}