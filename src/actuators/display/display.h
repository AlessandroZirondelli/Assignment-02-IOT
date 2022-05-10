#ifndef __DISPLAY__
#define __DISPLAY__

#define WIDTH  20
#define HEIGHT  4

#include "LiquidCrystal_I2C.h"

class Display {

private:
    int address = 0x27; //I2C
    int column = 0;
    int row = 0;
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(address, WIDTH, HEIGHT);

public: 
    Display(int address, int width, int height);
    void setup();
    void clear();
    void print(String message);
    void setCursor(int row, int column);
    
};

#endif




