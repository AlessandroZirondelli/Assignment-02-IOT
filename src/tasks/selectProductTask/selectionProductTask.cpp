#include "selectionProductTask.h"
#include "machine.h"
#include "config.h"
#include "ProductListed.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"


#define TIMEOUT 5 //SECONDS

selectionProductTask::selectionProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;

    this-> pProduct = pProduct;
    //this -> pPotSugar = new ;
    this -> pButtonUP = new ButtonImpl(BTNUP_PIN);
    this -> pButtonDOWN = new ButtonImpl(BTNDOWN_PIN);
    this -> pButtonMAKE = new ButtonImpl(BTNMAKE_PIN);
    //this -> pDisplay = new DisplayImpl();
};

void selectionProductTask::tick() {
    switch (state){
        case IDLE: {
            if(this->pMachine->isStart()){
                this->pMachine->setSelect();
                this->state = SELECT;
            }
            break;
        }
        
        case SELECT: {
            

            if(this->pButtonUP->isPressed()) {

                if(this->pProduct->getQuantity()<=0) {
                    //quantità non disponibile
                    this->state = IDLE;
                    this->pMachine->setAssistance();

                }
                /*
                
                if(currentPos == 2)
                isselected(0) metodo x vedere se è selezionabileil prodotto, se è disponibile
                currentpos=0
                //diminuire quantità

                //actualPos

                */


            } 
            
            
            if (this->pButtonDOWN->isPressed()) {
                if(this->pProduct->getQuantity()<=0) {
                    //quantità non disponibile
                    
                }
            }


            /*
            unsigned long timeStartMake=0;
            unsigned long currentTimeMake = millis(); 
            if (currentTimeMake - timeStartMake > TIDLE) {            
                this->pMachine->
                //sleeping
            }
            */



            break;
        }
    }
    
}