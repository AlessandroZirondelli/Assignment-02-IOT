#include "sensors/button/ButtonImpl.h"
#include "Arduino.h"

//classe con implementazione
ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;    
  pinMode(pin, INPUT); 
}

bool ButtonImpl::isPressed(){
  return digitalRead(pin) == HIGH;
}