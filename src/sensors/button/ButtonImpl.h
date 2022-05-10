#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "sensors/button/Button.h"

class ButtonImpl: public Button {
 
public: 
  ButtonImpl(int pin);
  bool isPressed(); //return when the button is pressed which means the pin is HIGH

private:
  int pin;

};

#endif