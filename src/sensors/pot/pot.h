#ifndef __POT__
#define __POT__

class Potentiometer {
 
public: 
  Potentiometer(int pin);

  float getValue(); // Ritorna il valore del potenziometro
  int getPercentage();

private:
  int pin;

};

#endif
