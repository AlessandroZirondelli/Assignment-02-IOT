#include "TempSensorLM35.h"
#include "Arduino.h"

#define VCC ((float)5)

TempSensorLM35::TempSensorLM35(int p) : pin(p){
} 
  
float TempSensorLM35::getTemperature(){
  int value = analogRead(pin);
  float voltage = (value /1024.0) * 5.0;
  float temp = (voltage - 0.5) * 100;
  return temp;
}
