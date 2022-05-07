#ifndef __MANAGERACTUATORSIMPL__
#define __MANAGERACTUATORSIMPL__

#include "./ManagerActuators.h"

class ManagerActuatorsImpl : public ManagerActuators {

public:
  ServoMotor* getServo();
  Sonar* getSonar();
  Display* getDisplay();
  ManagerActuatorsImpl();

private:
  ServoMotor* servo;
  Sonar* sonar;
  Display* display;
};


#endif

