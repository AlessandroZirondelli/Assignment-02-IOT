#include "userInteraction.h"
#include "Arduino.h"
#include "sensors/button/ButtonImpl.h"
#include <avr/sleep.h>

// used to avoid loosing decimals 
//#define PRECISION_MULTIPLIER 1000000

//void wakeUp(){}

UserInteraction::UserInteraction(){
  pPotSugar = new Potentiometer(POT_PIN);
  pPir = new Pir(PIR_PIN);
  pButtonUP = new ButtonImpl(BT_UP_PIN);  
  pButtonDOWN = new ButtonImpl(BT_DOWN_PIN);
  pButtonMAKE = new ButtonImpl(BT_MAKE_PIN);

  //attachInterrupt(digitalPinToInterrupt(PIR_PIN), wakeUp, RISING); 
}

void UserInteraction::calibrate(){
  pPir->calibrate();
}

/*
void UserInteraction::sleep(){
    pLed1->switchOff();
    pLed2->switchOff();
    delay(100);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
    sleep_enable();
    sleep_mode();  
    reset();
}
*/
bool UserInteraction::bUP(){
  return pButtonUP->isPressed();
}

bool UserInteraction::bDWON(){
  return pButtonDOWN->isPressed();
}

bool UserInteraction::detectedPresence(){
  return pPir->isDetected();
}


//Potentiometer* UserInteraction::getSurgar ??

/*
void UserConsole::notifySleeping(){
  MsgService.sendMsg("ex:zz");
}

void UserConsole::notifyReady(){
  MsgService.sendMsg("ex:ok");
}

void UserConsole::notifyCalibrating(){
  MsgService.sendMsg("ex:ca");
}

void UserConsole::notifyStarted(TTrackFreq freq){
  MsgService.sendMsg(String("ex:on:")+freq);
}

void UserConsole::notifyError(){
  MsgService.sendMsg("ex:er");
}

void UserConsole::notifyCompleted(){
  MsgService.sendMsg("ex:co");
}

void UserConsole::notifyNewData(long time, double pos, double vel, double acc){
  MsgService.sendMsg(String("ex:nd:")+time+":"+(pos*PRECISION_MULTIPLIER)+":"+(vel*PRECISION_MULTIPLIER)+":"+(acc*PRECISION_MULTIPLIER));
}

TTrackFreq UserConsole::getSelectedFreq(){
  float value = pPot->getValue();  
  if (value < 0.25){
    return FREQ_1HZ;
  } else if (value < 0.5){
    return FREQ_5HZ;    
  } else if (value < 0.75){
    return FREQ_25HZ;    
  } else {
    return FREQ_50HZ;    
  }
}
  
bool UserConsole::isUserOK(){
  if (MsgService.isMsgAvailable()){
    Msg* msg = MsgService.receiveMsg();
    if (msg != NULL){
      delete msg;
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
*/