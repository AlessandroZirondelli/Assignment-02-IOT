#include "ManagerSensorsImpl.h"
#include "temp/TempSensorLM35.h"
#include "config.h"
#include "Arduino.h"

ManagerSensorsImpl::ManagerSensorsImpl(){
  temp = new TempSensorLM35(TMP_PIN);
  pir = new Pir(PIR_PIN);
  pir->calibrate();
  //pot = new Potentiometer(POT_PIN);
  //buttonUp
  //buttonDown
  //buttonMake
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



