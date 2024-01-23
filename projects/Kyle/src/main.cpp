#include <Arduino.h>
#include <Servo.h>

//Left
const int MotorPin5 = 4;
const int MotorPin6 = 13;

const int MotorPin1 = 5;
const int MotorPin2 = 6;
//Right
const int MotorPin3 = 10;
const int MotorPin4 = 9;

const int MotorPin7 = A1;
const int MotorPin8 = A0;

const int LightPin = 7;

int trig = 12;
int echo = 11;
int time;
int distance;

int servoPin = 8; // pin sterujący Arduino

Servo servo;

int servoAngle = 0; // pozycja startowa serwa w stopniach

void setup() {
    pinMode(MotorPin1, OUTPUT);
    pinMode(MotorPin2, OUTPUT);
    pinMode(MotorPin3, OUTPUT);
    pinMode(MotorPin4, OUTPUT);
    pinMode(MotorPin5, OUTPUT);
    pinMode(MotorPin6, OUTPUT);
    pinMode(MotorPin7, OUTPUT);
    pinMode(MotorPin8, OUTPUT);

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(LightPin, OUTPUT);

    Serial.begin(115200);
    servo.attach(servoPin);

    /*digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, HIGH);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, HIGH);*/
    digitalWrite(MotorPin5, LOW);
    digitalWrite(MotorPin6, HIGH);
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
        delay(5);
    }
    for(int servoAngle = 180; servoAngle > 0; servoAngle-=1) {
        servo.write(servoAngle);
        delay(5);
    }

    //if (distance > 30) {
        digitalWrite(LightPin, LOW);
        digitalWrite(MotorPin2, HIGH);
        digitalWrite(MotorPin4, HIGH);
        digitalWrite(MotorPin6, HIGH);
        digitalWrite(MotorPin8, HIGH);
    //}
    /*else {
        digitalWrite(LightPin, HIGH);
        digitalWrite(MotorPin2, LOW);
        digitalWrite(MotorPin4, LOW);
    }*/
}