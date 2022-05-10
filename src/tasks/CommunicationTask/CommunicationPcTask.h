#ifndef __COMMUNICATIONPC__
#define __COMMUNICATIONPC__

#include "./tasks/Task.h"
#include "machine.h"


class CommunicationPcTask : public Task{

public: 
    CommunicationPcTask(Machine* machine);
    void tick();

private:
    enum{UPDATE,CHECK,COMMUNICATION}state;
    Machine* machineCoffee;
    ProductListed** productsList;
};
#endif