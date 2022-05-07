#include "./sensors/pot/sugar.h"
//#include <map>

Sugar::Sugar(int pin) : Potentiometer(pin) {}

int Sugar::getPercentage() {
    //return map(this->getValue(), 0, 1023, 0, 100);
}