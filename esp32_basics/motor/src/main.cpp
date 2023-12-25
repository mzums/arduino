/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Arduino.h>

// Motor A
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Motor B
int motor2Pin1 = 25;
int motor2Pin2 = 33;
int enable2Pin = 32;

// Motor C
int motor3Pin1 = 2;
int motor3Pin2 = 4;
int enable3Pin = 15;

// Motor D
int motor4Pin1 = 17;
int motor4Pin2 = 16;
int enable4Pin = 5;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle1 = 200;
int dutyCycle2 = 200;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);  // Dodane piny dla silnika C
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enable3Pin, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);  // Dodane piny dla silnika D
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enable4Pin, OUTPUT);
  
  // configure LED PWM functionalities for both motors
  //ledcSetup(pwmChannel1, freq, resolution);
  //ledcSetup(pwmChannel2, freq, resolution);
  
  // attach the channels to the GPIOs to be controlled
  //ledcAttachPin(enable1Pin, pwmChannel1);
  //ledcAttachPin(enable2Pin, pwmChannel2);

  Serial.begin(115200);
}

void loop() {

  digitalWrite(enable1Pin, HIGH);  // Włącz silnik 1
  digitalWrite(enable2Pin, HIGH);  // Włącz silnik 2
  digitalWrite(enable3Pin, HIGH);  // Włącz silnik 3
  digitalWrite(enable4Pin, HIGH);  // Włącz silnik 4


  // Move the DC motors forward at maximum speed
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
  //delay(2000);

  // Stop the DC motors
  /*digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);

  // Move DC motors backwards at maximum speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  delay(2000); 

  // Stop the DC motors
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);

  // Move DC motors forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW); 
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW); */
  /*while (dutyCycle1 <= 255 || dutyCycle2 <= 255) {
    //ledcWrite(pwmChannel1, dutyCycle1);
    //ledcWrite(pwmChannel2, dutyCycle2);
    Serial.print("Motor 1 Duty Cycle: ");
    Serial.print(dutyCycle1);
    Serial.print("\t Motor 2 Duty Cycle: ");
    Serial.println(dutyCycle2);
    dutyCycle1 = dutyCycle1 + 5;
    dutyCycle2 = dutyCycle2 + 5;
    delay(500);
  }
  dutyCycle1 = 200;
  dutyCycle2 = 200;*/
}
