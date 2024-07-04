#include "Joint.h"

float limit = 1;
float Kp = 1.8  ;
const int maxSpeed = 255; // Maximum speed for the motor
const int minSpeed = 80;  // Minimum speed for the motor

Joint::Joint(int in1, int in2, int in3, int in4, int en1, int en2, EncoderType type)
    : motor(in1, in2, in3, in4, en1, en2), encoder(type)
{
}

void Joint::MoveCCWAngle(float angle, int speed) const
{
  // Serial.print(angle);
  // Serial.print("-----");
  // Serial.println(speed);
  switch (encoder.getEncoderType())
  {
  case EncoderType::as5600:
    float ref = encoder.readEncoder();
    if ((ref + angle) > 360.0)
    {
      angle = ref + angle - 360.0;
    }
    else
    {
      angle = ref + angle;
    }
    angle-=10;
    Serial.print(ref);
    Serial.print("--CCW---");
    Serial.println(angle);

    while (!((ref <= (angle + limit)) && (ref >= (angle - limit))))
    {
      ref = encoder.readEncoder();
      float error = angle - ref;
      int motorSpeed = Kp * abs(error);
      if (motorSpeed > speed)
      {
        motorSpeed = speed;
      }
      else if (motorSpeed < minSpeed)
      {
        motorSpeed = minSpeed;
      }
      // Serial.print("Speed");
      // Serial.println(motorSpeed);
      motor.MotorBackward(motorSpeed);
    }
    motor.MotorStop();
    break;
  case EncoderType::NoEncoder:
    motor.MotorBackward(speed);
    break;
  }
}

void Joint::MoveCWAngle(float angle, int speed) const
{
  // Serial.print(angle);
  // Serial.print("-----");
  // Serial.println(speed);
  switch (encoder.getEncoderType())
  {
  case EncoderType::as5600:
    float ref = encoder.readEncoder();
    if ((ref - angle) < 0)
    {
      angle = 360.0 - (angle - ref);
    }
    else
    {
      angle = ref - angle;
    }
    angle+=5;
    Serial.print(ref);
    Serial.print("--CW---");
    Serial.println(angle);

    while (!((ref <= (angle + limit)) && (ref >= (angle - limit))))
    {
      ref = encoder.readEncoder();
      float error = angle - ref;
      int motorSpeed = Kp * abs(error);
      if (motorSpeed > speed)
      {
        motorSpeed = speed;
      }
      else if (motorSpeed < minSpeed)
      {
        motorSpeed = minSpeed;
      }
      // Serial.print("Speed");
      // Serial.println(motorSpeed);
      motor.MotorForward(motorSpeed);
    }
    motor.MotorStop();
    break;
  case EncoderType::NoEncoder:
    motor.MotorForward(speed);
    break;
  }
}

float Joint::getFeedback() const
{
  return encoder.readEncoder();
}

void Joint::Stop() const
{
  motor.MotorStop();
}