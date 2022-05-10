#include "pot.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
float Potentiometer::getValue(){
  float val = analogRead(pin); //return of the value of the potentiometer
  return val;
}

int Potentiometer::getPercentage() { //return the percentage of sugar
    return map(this->getValue(), 0, 1023, 0, 100);
}
