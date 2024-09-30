#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BUTTON_PIN 2
#define LED_COUNT 10

int ledPins[LED_COUNT] = {27, 26, 22, 21, 20, 19, 18, 17, 16, 28};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int buttonState = 0;
int lastButtonState = 0;
int clickCount = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Clicks: 0");
  display.display();
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && lastButtonState == LOW) {
    clickCount++;
    if (clickCount == 11) {
      clickCount = 0;
    }
    updateDisplay();
    updateLEDBar();
    delay(50);
  }

  lastButtonState = buttonState;
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Clicks: " + String(clickCount));
  display.display();
}

void updateLEDBar() {
  for (int i = 0; i < LED_COUNT; i++) {
    if (i < clickCount) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
