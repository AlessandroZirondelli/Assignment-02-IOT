#include "ManagerSensorsImpl.h"
#include "temp/TempSensorLM35.h"
#include "./sensors/button/ButtonImpl.h"
#include "config.h"
#include "Arduino.h"

ManagerSensorsImpl::ManagerSensorsImpl(){
  temp = new TempSensorLM35(TMP_PIN);
  pir = new Pir(PIR_PIN);
  pir->calibrate();
  //pot = new Potentiometer(POT_PIN);

  buttonUp = new ButtonImpl(BTNUP_PIN);
  buttonDown = new ButtonImpl(BTNDOWN_PIN);
  buttonMake = new ButtonImpl(BTNMAKE_PIN);
} 

TempSensor* ManagerSensorsImpl ::  getTemp(){
  return this-> temp;
}

Pir* ManagerSensorsImpl :: getPir(){
  return this -> pir;
}
Potentiometer* ManagerSensorsImpl :: getPot(){
  return this -> pot;
}
Button* ManagerSensorsImpl :: getButtonUp(){
  return this -> buttonUp;
}
Button* ManagerSensorsImpl :: getButtonDown(){
  return this -> buttonDown;
}
Button* ManagerSensorsImpl :: getButtonMake(){
  return this -> buttonMake;
}



