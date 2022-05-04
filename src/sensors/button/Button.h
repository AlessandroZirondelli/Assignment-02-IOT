#ifndef __BUTTON__
#define __BUTTON__

//classe astratta
class Button {
 
public: 
  virtual bool isPressed() = 0;
  virtual void setup() = 0;
};

#endif
