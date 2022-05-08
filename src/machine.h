#ifndef __MACHINE__
#define __MACHINE__
#include "Product.h"
#include "ProductListed.h"
#include "catalog.h"
#include "./sensors/ManagerSensors.h"
#include "./actuators/ManagerActuators.h"


class Machine {
    
public:
    Machine();
    void init();
    bool addCatalog(Catalog* catalog);
    Catalog* getCatalog();
    bool isStart();
    bool isSelect();
    bool isMaking();
    bool isWait();
    bool isSelfTest();
    bool isAssistance();

    void setStart();
    void setSelect();
    void setMaking();
    void setWait();
    void setSelfTest();
    void setAssistance();

    void setErrorRefill();
    void setErrorNone();
    void setTemperatureAlert();

    bool isErrorRefill();
    bool isErrorNone();
    bool isTemperatureAlert();
    ManagerSensors* getManagerSensonrs();
    ManagerActuators* getManagerActuators();

private:
    enum { START, SELECT, MAKING, WAIT,SELFTEST, ASSISTANCE } state;
    enum {NONE, REFILL,TEMPERATURE} alert; 
    Catalog* catalog;
    ManagerSensors* mngSensors;
    ManagerActuators* mngActuators;

};

#endif
