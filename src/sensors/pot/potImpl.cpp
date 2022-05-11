#include "pot.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
int Potentiometer::getLevel() { //return the level of sugar
float val = analogRead(pin); 
    return map(val, 0, 1023, 0, 5);
}
