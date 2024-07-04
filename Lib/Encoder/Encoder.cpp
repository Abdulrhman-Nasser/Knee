#include "Encoder.h"

Encoder::Encoder(EncoderType type)
  : Type(type) {

}

float Encoder::readEncoder() const
{
  switch (Type) {
  case EncoderType::NoEncoder:
    return 0;
    break;
  case EncoderType::as5600:
    return as5600.getScaledAngle();
    break;
  case EncoderType::somethingelse:
    return 0;
    break;
  }
}

EncoderType Encoder::getEncoderType() const
{
  return Type;
}