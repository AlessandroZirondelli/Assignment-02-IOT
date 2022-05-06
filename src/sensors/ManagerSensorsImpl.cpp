#include "ManagerSensorsImpl.h"
#include "temp/TempSensorLM35.h"
#include "config.h"
#include "Arduino.h"

ManagerSensorsImpl::ManagerSensorsImpl(){
  temp = new TempSensorLM35(TMP_PIN);
} 



