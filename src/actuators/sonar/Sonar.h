#ifndef __SONAR__
#define __SONAR__

#include "./actuators/ProximitySensor.h"

class Sonar: public ProximitySensor {

public:  
  Sonar(int echoPin, int trigPin, long maxTime);
  float getDistance();
  void setTemperature(float temp);  

private:
    float getSoundSpeed();
    float temperature;    
    int echoPin, trigPin;
    long timeOut;
};

#endif 
