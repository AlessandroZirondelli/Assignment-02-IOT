#ifndef __SERVO_MOTOR__
#define __SERVO_MOTOR__

class ServoMotor {

public:
  virtual void on() = 0;
  virtual void setPosition(int angle) = 0;
  virtual void off() = 0;
  virtual int getAnglePosition() = 0;
};

#endif
