#ifndef __USER_INTERACTION__
#define __USER_INTERACTION__

#include "sensors/pot/pot.h"
#include "sensors/pir/Pir.h"
#include "sensors/button/Button.h"
#include "actuators/display/display.h"
#include "actuators/servo/servo_motor.h"
#include "Machine.h"
//#include "config.h"

class UserInteraction {

private:
  Potentiometer* pPotSugar;
  Pir* pPir;
  Button* pButtonUP; 
  Button* pButtonDOWN;
  Button* pButtonMAKE; 
  Display* pDisplay;
  ServoMotor* pServoMotor;

public:
  UserInteraction();

  void sleep();
  
  bool bUP();
  bool bDWON();
  bool bMAKE();

  bool detectedPresence();

/*
  void notifyCalibrating();
  void notifySleeping();
  void notifyReady();
  void notifyStarted(TTrackFreq freq);
  void notifyNewData(long time, double pos, double vel, double acc);
  void notifyCompleted();
  void notifyError();
*/

  bool isUserOK();  
  void calibrate();



};

#endif