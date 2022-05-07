#ifndef __MANAGERACTUATORS__
#define __MANAGERACTUATORS__

#include "./servo/servo_motor.h"
#include "./sonar/Sonar.h"
#include "./actuators/display/display.h"

class ManagerActuators {

public:
  virtual ServoMotor* getServo() = 0;
  virtual Sonar* getSonar() = 0;
  virtual Display* getDisplay() = 0;

};


#endif

