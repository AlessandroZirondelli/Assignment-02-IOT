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
    bool addCatalog(Catalog* catalog); // Aggiungo un catalogo alla machine coffee
    Catalog* getCatalog(); //Ritorno il catalogo

    //Metodi per il controllo dello stato della macchina
    bool isStart(); 
    bool isSelect();
    bool isMaking();
    bool isWait();
    bool isSelfTest();
    bool isAssistance();

    //Metodi per settare lo stato della macchina
    void setStart();
    void setSelect();
    void setMaking();
    void setWait();
    void setSelfTest();
    void setAssistance();

    //Metodi per settare la tipologia d'errore della macchina
    void setErrorRefill(); //Se non ci sono prodotti disponilbili si setta a "Refill"
    void setErrorNone(); // Se non ci sono errori si setta a "None"
    void setTemperatureAlert(); //Se la temperatura è fuori norma si setta a "Temperature"
 
    //Metodi per controllare la tipologia d'errore della macchine
    bool isErrorRefill();
    bool isErrorNone();
    bool isTemperatureAlert();

    
    void incNumSelfTest(); // Incrememnta di uno il contatore che tiene conto di quanti SelfTest sono stati eseguiti
    int getNumSelfTest();   //Ritorna il numero di selftest eseguiti
    ManagerSensors* getManagerSensonrs();  // Manager dei sensori
    ManagerActuators* getManagerActuators(); // Manager degli attuatori
    int selectedProduct; //identify which product is selected

    void setSelectedProduct(int val);
    int getSelectedProduct(); 

private:
    enum { START, SELECT, MAKING, WAIT,SELFTEST, ASSISTANCE } state; // Stati della macchina
    enum {NONE, REFILL,TEMPERATURE} alert; //Tipologia d'errore della macchina
    Catalog* catalog;
    ManagerSensors* mngSensors;
    ManagerActuators* mngActuators;
    int numSelfTest; // Contatore che tiene il conto di quanti selfTest sono stati eseguiti

};

#endif
