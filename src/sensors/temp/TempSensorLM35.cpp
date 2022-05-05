#include "TempSensorLM35.h"
#include "Arduino.h"

#define VCC ((float)5)

TempSensorLM35::TempSensorLM35(int p) : pin(p){
} 
  
float TempSensorLM35::getTemperature(){
  int value = analogRead(pin);
  /*float valueInVolt = value*VCC/1023;  
  float valueInCelsius = valueInVolt/0.01;*/
  //float valueInCelsius = ((value * 0.00488) - 0.5) / 0.01;
  //valueInCelsius = (valueInCelsius -32)*0.55;
  float voltage = (value /1024.0) * 5.0;
  float temp = (voltage - 0.5) * 100;
  return temp;
}
