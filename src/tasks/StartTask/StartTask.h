#ifndef __STARTTASK__
#define __STARTTASK__

#include "./tasks/Task.h"
#include "./machine.h"

class StartTask : public Task{

public: 
    StartTask(Machine* machine);
    void tick();

private:
    enum{INIT,IDLE,CHECK,ERROR,SLEEP} state;
    Machine * machine;
    Pir* pir;
    unsigned long int time;
};
#endif