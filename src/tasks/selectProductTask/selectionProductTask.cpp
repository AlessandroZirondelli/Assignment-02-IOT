#include "selectionProductTask.h"
#include "machine.h"
#include "config.h"
#include "ProductListed.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"


selectionProductTask::selectionProductTask(Machine* pMachine) {
    this -> state = IDLE;

    this -> pMachine = pMachine;
    this-> pProduct = pProduct;
    this->pProduct = new ProductListed();
    //this -> pPotSugar = new ;
    
    this->pButtonUP = this->pMachine->getManagerSensonrs()->getButtonUp();
    this->pButtonDOWN = this->pMachine->getManagerSensonrs()->getButtonDown();
    this->pButtonMAKE = this->pMachine->getManagerSensonrs()->getButtonMake();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();
};

void selectionProductTask::tick() {
    switch (state){
        case IDLE: {
            if(this->pMachine->isStart()){
                this->pMachine->setSelect();
                this->state = SELECT;
                this->timeStart = millis();
                this->currentPos = 0;
            }
            break;
        }
        
        case SELECT: {

            if(!(this->pButtonDOWN->isPressed())&&(!(this->pButtonUP->isPressed()))&&(!(this->pButtonMAKE->isPressed()))){ 
                unsigned long current = millis();
                if(((current-timeStart)/1000) > T_BUTTON){ 
                    this->state = IDLE;
                    this->pMachine->setStart();
                    break;
                }
                Serial.println("Not pressed button");
            } else{ 
                //sono nel caso che premono i pulsanti
                if(this->pMachine->getCatalog()->getTotalDisponibility()==0) { //no prodotti
                    this->state = IDLE;
                    this->pMachine->setAssistance();
                    this->pMachine->isErrorRefill();
                } else {
                    
                    if(this->pButtonUP->isPressed()) {

                        if(currentPos == 0 ) {
                            if(pProduct[1].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[2].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 2;
                            } else {
                                String menu = pProduct[1].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 1;
                            }
                        }

                        if(currentPos == 1 ) {
                                if(pProduct[2].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[0].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 0;
                            } else {
                                String menu = pProduct[2].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 2;
                            }
                        }

                        if(currentPos == 2 ) {
                                if(pProduct[0].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[1].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 1;
                            } else {
                                String menu = pProduct[0].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 0;
                            }
                        }

                    }

                    if (this->pButtonDOWN->isPressed()) {

                        if(currentPos == 0 ) {
                            if(pProduct[2].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[1].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 1;
                            } else {
                                String menu = pProduct[2].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 2;
                            }
                        }

                        if(currentPos == 1 ) {
                                if(pProduct[0].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[2].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 2;
                            } else {
                                String menu = pProduct[0].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 0;
                            }
                        }

                        if(currentPos == 2 ) {
                                if(pProduct[0].getQuantity()<=0) { //quantità non disponibile del prodotto
                                String menu = pProduct[1].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 1;
                            } else {
                                String menu = pProduct[0].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 0;
                            }
                        }

                    }

                    if(this->pButtonMAKE->isPressed()) {
                        pProduct[currentPos].getProduct();
                        this->state = IDLE;
                        this->pMachine->setMaking();
                    }
                }
                break;

            }

            break;
        }
    }
    
}