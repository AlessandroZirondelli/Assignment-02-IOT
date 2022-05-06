#ifndef __MANAGERSENSORSIMPL__
#define __MANAGERSENSORSIMPL__

#include "./ManagerSensors.h"

class ManagerSensorsImpl : public ManagerSensors {


public:
    TempSensor* getTemp();
    Pir* getPir();
    Potentiometer* getPot();
    Button* getButtonUp();
    Button* getButtonDown();
    Button* getButtonMake();
    ManagerSensorsImpl();

private:
    TempSensor * temp;
    Pir* pir;
    Potentiometer* pot;
    Button* buttonUp;
    Button* buttonDown;
    Button* buttonMake;


};

#endif
