#ifndef __POT__
#define __POT__

class Potentiometer {
 
public: 
  Potentiometer(int pin);
  int getLevel();   //return level of sugar

private:
  int pin;

};

#endif
