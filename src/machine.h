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
    bool addCatalog(Catalog* catalog); // Add catalog to machine coffee
    Catalog* getCatalog(); 

    //Method for check the state of machine
    bool isStart(); 
    bool isSelect();
    bool isMaking();
    bool isWait();
    bool isSelfTest();
    bool isAssistance();

    //Methods to set the state of machine
    void setStart();
    void setSelect();
    void setMaking();
    void setWait();
    void setSelfTest();
    void setAssistance();

    //methods to set the error of machine
    void setErrorRefill(); //is set if there isnt products available
    void setErrorNone(); // is set if there isnt error
    void setTemperatureAlert(); //is set if there is a temperature problem
 
    //Methods for check the error of machine
    bool isErrorRefill();
    bool isErrorNone();
    bool isTemperatureAlert();

    
    void incNumSelfTest(); // Increment a counter that mantain how many SelfTest were perfomed
    int getNumSelfTest();   //Return counter of SelfTest
    ManagerSensors* getManagerSensonrs();  
    ManagerActuators* getManagerActuators(); 
    

    void setSelectedProduct(int val);
    int getSelectedProduct(); 
    void setSugarLevel(int val);
    int getSugarLevel(); 

private:
    enum { START, SELECT, MAKING, WAIT,SELFTEST, ASSISTANCE } state; //State of machine
    enum {NONE, REFILL,TEMPERATURE} alert; //Tipology of error
    Catalog* catalog;
    ManagerSensors* mngSensors;
    ManagerActuators* mngActuators;
    int numSelfTest; // Counter of selfTest
    int selectedProduct; //identify which product is selected
    int selectedSugar;
};

#endif
