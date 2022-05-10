#include "ManagerActuatorsImpl.h"
#include "./actuators/display/display.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "Arduino.h"
#include "config.h"


ManagerActuatorsImpl::ManagerActuatorsImpl(){
  this->servo = new ServoMotorImpl(SERVO_PIN);
  this -> sonar = new Sonar(ECHO_PIN,TRIG_PIN,MAX_TIME);
  this -> servo ->on();

  this->display = new Display(0x27, 20, 4);
  this->display ->setup();
  this->display->setCursor(2,1);
}


ServoMotor* ManagerActuatorsImpl:: getServo(){
  return this ->servo;
}
Sonar* ManagerActuatorsImpl:: getSonar(){
  return this ->sonar;
}
Display* ManagerActuatorsImpl:: getDisplay(){
  return this ->display;
}