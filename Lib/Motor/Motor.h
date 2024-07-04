#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
class Motor
{
private:
    int IN1;
    int IN2;
    int IN3;
    int IN4;
    int EN1;
    int EN2;
public:
    Motor(int in1, int in2, int in3, int n4, int en1, int en2);
    void MotorForward(int speed);
    void MotorBackward(int speed);
    void MotorStop();
    ~Motor();
};






#endif