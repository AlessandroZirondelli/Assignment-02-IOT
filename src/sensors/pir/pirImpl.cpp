#include "pir.h"
#include "Arduino.h"

Pir::Pir(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);     
} 
  
bool Pir::isDetected(){
  return digitalRead(pin) == HIGH; //Ritorna true se è stato rilevato qualcuno
}

void Pir::calibrate(){
	delay(10000); // Calibrazione
}


