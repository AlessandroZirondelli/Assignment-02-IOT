#ifndef __PIR__
#define __PIR__

#include "../PresenceSensor.h"

class Pir: public PresenceSensor {
 
public: 
  Pir(int pin);
  bool isDetected();
  void calibrate();

private:
  int pin;

};

#endif
