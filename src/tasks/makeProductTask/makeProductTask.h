#ifndef __MAKEPRODUCT_TASK__
#define __MAKEPRODUCT_TASK__

#include "tasks/Task.h"
#include "machine.h"
#include "ProductListed.h"
#include "actuators/display/display.h"
#include "actuators/servo/servo_motor.h"

class makeProductTask: public Task {

private:
    
    enum { IDLE, START, MAKE, COMPLETE } state;

    Machine* pMachine;
    ProductListed** productsList;
    Display* pDisplay;
    ServoMotor* pServoMotor; 
    
    unsigned long timeStartMake;
    int posProdMaking;
  

public:
    makeProductTask(Machine* pMachine);
    void tick();
    
};

#endif