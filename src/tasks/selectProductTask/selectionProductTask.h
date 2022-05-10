#ifndef __SELECTPRODUCT_TASK__
#define __SELECTPRODUCT_TASK__

#include "tasks/Task.h"
#include "machine.h"

#include "sensors/pot/pot.h"
#include "sensors/button/Button.h"
#include "actuators/display/display.h"

class selectionProductTask: public Task {

private:
    
    enum { IDLE, SELECT } state;

    Machine* pMachine;
    Potentiometer* pPotSugar;
    Button* pButtonUP; 
    Button* pButtonDOWN;
    Button* pButtonMAKE; 
    Display* pDisplay;
    ProductListed** productsList;
    
    unsigned long int timeStart;
    unsigned int currentPos;

    void nextSelection(); //next selection when user press on Button down
    void prevSelection(); //prev selection when user press on Button up

public:
    selectionProductTask(Machine* pMachine);
    void tick();

};

#endif