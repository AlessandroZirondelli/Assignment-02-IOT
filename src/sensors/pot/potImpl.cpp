#include "pot.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
float Potentiometer::getValue(){
  float val = analogRead(pin);
  return val;
}

int Potentiometer::getPercentage() {
    return map(this->getValue(), 0, 1023, 0, 100);
}
