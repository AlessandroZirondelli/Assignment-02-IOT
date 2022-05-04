#ifndef __SELECTPRODUCT_TASK__
#define __SELECTPRODUCT_TASK__

#include "tasks/Task.h"
#include "machine.h"

#include "sensors/pot/pot.h"
#include "sensors/pir/Pir.h"
#include "sensors/button/Button.h"
#include "actuators/display/display.h"
#include "actuators/servo/servo_motor.h"

#define TIMEOUT 

class selectionProductTask: public Task {

private:
    
    enum { IDLE, SELECT } state;

    Machine* pMachine;
    Potentiometer* pPotSugar;
    Pir* pPir;
    Button* pButtonUP; 
    Button* pButtonDOWN;
    Button* pButtonMAKE; 
    Display* pDisplay;
    ServoMotor* pServoMotor; 

public:
    selectionProductTask(Machine* pMachine, Potentiometer* pPotSugar, Pir* pPir, Button* pButtonUP, Button* pButtonDOWN, Button* pButtonMAKE, Display* pDisplay, ServoMotor* pServoMotor );
    void tick();
    //metodi
};

#endif