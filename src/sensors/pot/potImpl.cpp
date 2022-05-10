#include "pot.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
float Potentiometer::getValue(){
  float val = analogRead(pin); // Ritorna il valore del potenziometro
  return val;
}
