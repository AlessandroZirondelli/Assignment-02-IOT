#ifndef __POT__
#define __POT__

class Potentiometer {
 
public: 
  Potentiometer(int pin);
  
  float getValue();
  
  int getPercentage();

private:
  int pin;

};

#endif
