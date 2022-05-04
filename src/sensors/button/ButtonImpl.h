#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "sensors/button/Button.h"

//classe senza implementazione
class ButtonImpl: public Button {
 
public: 
  ButtonImpl(int pin);
  bool isPressed();

private:
  int pin;

};

#endif