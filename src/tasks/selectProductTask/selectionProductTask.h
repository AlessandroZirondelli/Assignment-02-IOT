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

public:
    selectionProductTask(Machine* pMachine);
    void tick();

};

#endif