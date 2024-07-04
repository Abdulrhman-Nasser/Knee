#ifndef ENCODER_H
#define ENCODER_H
#include <AS5600.h>
enum EncoderType {
  NoEncoder,
  as5600,
  somethingelse
};
class Encoder {
private:
  AS5600 as5600;
  EncoderType Type;
public:
  Encoder(EncoderType type = EncoderType::NoEncoder);
  float readEncoder() const;
  EncoderType getEncoderType() const;
};

#endif