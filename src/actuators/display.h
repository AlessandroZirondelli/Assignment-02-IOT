#ifndef __DISPLAYIMPL__
#define __DISPLAYIMPL__

#define WIDTH  16
#define HEIGHT  2

#include "LiquidCrystal_I2C.h"

class display {

private:
    int address = 0x27; //I2C
    int column = 0;
    int row = 0;
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(address, WIDTH, HEIGHT);

public: 
    display(int address, int width, int height);
    void setup();
    void clear();
    void print(String message);
    void selectLine(int row, int column);
    
};

#endif




