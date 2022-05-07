#ifndef __MANAGERSENSORS__
#define __MANAGERSENSORS__

#include "./sensors/temp/TempSensor.h"
#include "./sensors/pir/pir.h"
#include "./sensors/pot/pot.h"
#include "./sensors/button/Button.h"


class ManagerSensors {

public:
    virtual TempSensor* getTemp() = 0;
    virtual Pir* getPir() = 0;
    virtual Potentiometer* getPot() = 0;
    virtual Button* getButtonUp() = 0;
    virtual Button* getButtonDown() = 0;
    virtual Button* getButtonMake() = 0;

};


#endif

