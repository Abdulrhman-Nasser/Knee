#ifndef JOINT_H
#define JOINT_H
#include <Motor.h>
#include "Encoder.h"
class Joint {
private:
  Motor motor;
  Encoder encoder;
public:
  Joint(int in1, int in2, int in3, int in4, int en1, int en2,EncoderType type);
  void MoveCCWAngle(float angle, int speed) const;
  void MoveCWAngle(float angle, int speed) const;
  float getFeedback() const;
  void Stop() const;
};

#endif