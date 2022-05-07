#include "ManagerActuatorsImpl.h"
#include "./actuators/display/display.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "Arduino.h"
#include "config.h"


ManagerActuatorsImpl::ManagerActuatorsImpl(){
  this->servo = new ServoMotorImpl(SERVO_PIN);
  //this->display = new Display();
  //this -> sonar = new Sonar();
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