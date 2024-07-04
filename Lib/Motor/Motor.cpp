#include "Motor.h"
#include <Arduino.h>
Motor::Motor(int in1, int in2, int in3, int in4, int en1, int en2) : IN1(in1),IN2(in2),IN3(in3),IN4(in4),EN1(en1),EN2(en2)
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
}

void Motor::MotorForward(int speed)
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN1, speed);
    analogWrite(EN2, speed);
}

void Motor::MotorBackward(int speed)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1, speed);
    analogWrite(EN2, speed);
}

void Motor::MotorStop()
{
    int speed = 0;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN1, speed);
    analogWrite(EN2, speed);
}

Motor::~Motor()
{
}