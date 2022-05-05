#include "machine.h"
#include <Arduino.h>

Machine::Machine(){
    state = START;
    this->catalog = new Catalog();
}
void Machine::init(){
    /*metterer nel main
    numProd = 3;
    productList[0] = new Product("Chocolate",40);
    productList[1] = new Product("Coffee",50);
    productList[2] = new Product("Tea",60);
*/
}

    
    bool Machine::addCatalog(Catalog* catalog){
        this-> catalog = catalog;
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


