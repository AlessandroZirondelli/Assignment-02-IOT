#ifndef __PIR__
#define __PIR__

#include "../PresenceSensor.h"

class Pir: public PresenceSensor {
 
public: 
  Pir(int pin);
  bool isDetected(); // Ritorna true se viene rilevato una persona
  void calibrate(); // Calibra il sensore

private:
  int pin;

};

#endif
