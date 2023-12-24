#include <Arduino.h>
#include <Servo.h>

//Left
const int MotorPin1 = 5;
const int MotorPin2 = 6;
//Right
const int MotorPin3 = 10;
const int MotorPin4 = 9;

const int LightPin = 7;

int trig = 12;
int echo = 11;
int time;
int distance;

int servoPin = 2; // pin sterujący Arduino

Servo servo;

int servoAngle = 0; // pozycja startowa serwa w stopniach

void setup() {
    pinMode(MotorPin1, OUTPUT);
    pinMode(MotorPin2, OUTPUT);
    pinMode(MotorPin3, OUTPUT);
    pinMode(MotorPin4, OUTPUT);

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(LightPin, OUTPUT);

    Serial.begin(9600);
    servo.attach(servoPin);

    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, HIGH);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, HIGH);
}

void loop() {

    digitalWrite(trig, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trig, LOW);

    time = pulseIn(echo, HIGH);
    distance = (time / 2) / 29.1;

    Serial.print(distance);
    Serial.print(" cm");
    Serial.println();

    for(int servoAngle = 0; servoAngle < 180; servoAngle+=1) {
        servo.write(servoAngle);
        delay(10);
    }
    for(int servoAngle = 180; servoAngle > 0; servoAngle-=1) {
        servo.write(servoAngle);
        delay(10);
    }

    //if (distance > 30) {
        digitalWrite(LightPin, LOW);
        digitalWrite(MotorPin2, HIGH);
        digitalWrite(MotorPin4, HIGH);
    //}
    /*else {
        digitalWrite(LightPin, HIGH);
        digitalWrite(MotorPin2, LOW);
        digitalWrite(MotorPin4, LOW);
    }*/
}