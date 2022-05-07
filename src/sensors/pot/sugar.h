#ifndef __SUGAR__
#define __SUGAR__

#include "./sensors/pot/pot.h"

class Sugar: public Potentiometer {

    public:
    Sugar(int pin);
    int getPercentage();

};
#endif