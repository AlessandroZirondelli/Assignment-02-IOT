#ifndef __STARTTASK__
#define __STARTTASK__

#include "./tasks/Task.h"
#include "./machine.h"
#include "./actuators/display/display.h"

class StartTask : public Task{

public: 
    StartTask(Machine* machine);
    void tick();
    static void wakeUp();

private:
    enum{INIT,IDLE,CHECK,ERROR,SLEEP} state;
    Machine * machine;
    Pir* pir;
    Display* display;
    unsigned long int time;
};
#endif