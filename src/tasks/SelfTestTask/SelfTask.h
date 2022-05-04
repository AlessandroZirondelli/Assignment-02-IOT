#ifndef __SELFTASK__
#define __SELFTASK__

#include "../Task.h"
#include "machine.h"
//#include ""

#define TCHECK 180 // seconds
#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 


class SelfTask : public Task{

public: 
    SelfTask(Machine machine);
    void tick();

private:
    enum{IDLE,CHECK,ERROR};
    //TempSensor tempSensor;

    
};
#endif