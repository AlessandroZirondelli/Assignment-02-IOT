#ifndef __MAKEPRODUCT_TASK__
#define __MAKEPRODUCT_TASK__

#include "tasks/Task.h"
#include "machine.h"

#include "product.h"

#include "actuators/display/display.h"
#include "actuators/servo/servo_motor.h"

class makeProductTask: public Task {

private:
    
    enum { IDLE, START, MAKE, COMPLETE } state;

    Machine* pMachine;
    Product* pProduct;
    Display* pDisplay;
    ServoMotor* pServoMotor; 

public:
    makeProductTask(Machine* pMachine);
    void tick();
    
};

#endif