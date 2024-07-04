#include <Joint.h>
#define IN1 7
#define IN2 8
#define IN3 2
#define IN4 4
#define EN2 9
#define EN1 5

Joint joint(IN1, IN2, IN3, IN4, EN1, EN2, EncoderType::as5600);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int angle = Serial.parseInt();
    int speed = Serial.parseInt();
    Serial.read();
    if (speed > 0) {
      joint.MoveCWAngle(angle, speed);
    } else if (speed < 0) {
      speed = speed * -1;
      joint.MoveCCWAngle(angle, speed);
    } else {
      joint.Stop();
    }
  }
  Serial.println(joint.getFeedback());
}
