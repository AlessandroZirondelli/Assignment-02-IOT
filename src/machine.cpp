#include "machine.h"
#include <Arduino.h>
#include "./actuators/ManagerActuatorsImpl.h"
#include "./sensors/ManagerSensorsImpl.h"

Machine::Machine(){
    state = START;
    this->catalog = new Catalog();
    this->mngActuators = new ManagerActuatorsImpl();
    this->mngSensors = new ManagerSensorsImpl();
    this->numSelfTest = 0;
    alert = NONE;
    selectedProduct = -1; // if no product is selected , it's set to -1. Also its value is position of product in list of catalog.
    
}

    
bool Machine::addCatalog(Catalog* catalog){
    this-> catalog = catalog;
    return true;
}
Catalog* Machine::getCatalog(){
    return catalog;
}
bool Machine::isStart(){
    return state == START;
}
bool Machine::isSelect(){
    return state == SELECT;
}
bool Machine::isMaking(){
    return state == MAKING;
}
bool Machine::isWait(){
    return state == WAIT;
}
bool Machine::isSelfTest(){
    return state == SELFTEST;
}
bool Machine::isAssistance(){
    return state == ASSISTANCE;
}

void Machine::setStart(){
    state = START;
}
void Machine::setSelect(){
    state = SELECT;
}
void Machine::setMaking(){
    state = MAKING;
}
void Machine::setWait(){
    state = WAIT;
}
void Machine::setSelfTest(){
    state = SELFTEST;
}
void Machine::setAssistance(){
    state = ASSISTANCE;
}
void Machine::setErrorRefill(){
    alert = REFILL;
}
void Machine::setErrorNone(){
    alert = NONE;
}
void Machine::setTemperatureAlert(){
    alert = TEMPERATURE;
}
bool Machine::isErrorRefill(){
    return alert == REFILL;
}
bool Machine::isErrorNone(){
    return alert == NONE;
}
bool Machine::isTemperatureAlert(){
    return alert == TEMPERATURE;
}

ManagerActuators* Machine::getManagerActuators(){
    return this->mngActuators;
}

ManagerSensors* Machine::getManagerSensonrs(){
    return this->mngSensors;
}
void Machine::incNumSelfTest(){
    this->numSelfTest++;
}
int Machine::getNumSelfTest(){
    return this->numSelfTest;
}

int Machine::getSelectedProduct(){
    return this->selectedProduct;
}

void Machine::setSelectedProduct(int val){
    this->selectedProduct = val;
}
