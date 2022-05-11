#ifndef __PIR__
#define __PIR__

#include "../PresenceSensor.h"

class Pir: public PresenceSensor {
 
public: 
  Pir(int pin);
  bool isDetected(); // Return true if user is detected
  void calibrate(); // Sensor calibration

private:
  int pin;

};

#endif
