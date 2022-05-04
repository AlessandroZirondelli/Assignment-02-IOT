#ifndef __SELFTASK__
#define __SELFTASK__

#include "./tasks/Task.h"
#include "./machine.h"
#include "./actuators/sonar/Sonar.h"


class WithdrawTask : public Task{

public: 
    WithdrawTask(Machine* machine);
    void tick();

private:
    enum{IDLE,WAIT,REMOVAL} state;
    Machine * machine;
    Sonar * sonar;
};
#endif