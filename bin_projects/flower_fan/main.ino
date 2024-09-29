#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define POT_PIN 28
#define STEP_PIN 17  
#define DIR_PIN 16   
#define SERVO_PIN 27 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo myServo;

void setup() {
  Serial.begin(115200);
  
 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

 
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  
 
  myServo.attach(SERVO_PIN);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
 
  display.setCursor(0, 0);
  display.println("Potentiometer Level:");
  display.display();
}

void loop() {
 
  int potValue = analogRead(POT_PIN);
  Serial.println(potValue);
  
 
  int steps = map(potValue, 0, 1023, 0, 200);
  
 
  digitalWrite(DIR_PIN, (potValue > 512) ? HIGH : LOW);

 
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }

 
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  myServo.write(servoAngle);

 
  display.setCursor(0, 10);
  display.fillRect(0, 10, SCREEN_WIDTH, 54, BLACK);
  display.print("Level: ");
  display.print(map(potValue, 0, 1023, 0, 100));
  display.print("%");
  display.display();
  
 
  delay(100);
}
