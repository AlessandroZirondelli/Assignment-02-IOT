#include "selectionProductTask.h"
#include "machine.h"
#include "config.h"
#include "ProductListed.h"
#include "./actuators/ManagerActuatorsImpl.h"
#include "./sensors/ManagerSensorsImpl.h"


selectionProductTask::selectionProductTask(Machine* pMachine) {
    this -> state = IDLE;

    this -> pMachine = pMachine;
    this->pProduct = new ProductListed();

    this -> pPotSugar = this->pMachine->getManagerSensonrs()->getPot();
    this->pButtonUP = this->pMachine->getManagerSensonrs()->getButtonUp();
    this->pButtonDOWN = this->pMachine->getManagerSensonrs()->getButtonDown();
    this->pButtonMAKE = this->pMachine->getManagerSensonrs()->getButtonMake();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();
};

void selectionProductTask::tick() { //this is the task where you select the product you want
    switch (state){
        case IDLE: { //initialization
            this->timeStart = millis();
            this->currentPos = 0;
            this->state = SELECT;
            break;
        }
        
        case SELECT: { //switch from IDLE to SELECT only if any button is pressed or the time has passed
            if(!(this->pButtonDOWN->isPressed())||(!(this->pButtonUP->isPressed()))){ 
                unsigned long current = millis();
                if(((current-timeStart)/1000) > T_BUTTON){ //if no buttons are pressed before 5 seconds
                    this->state = IDLE; 
                    this->pMachine->setStart(); 
                    break;
                }
                Serial.println("Not pressed button");
            } else{ //the buttons are pressed 
                if(this->pMachine->getCatalog()->getTotalDisponibility()==0) { //if there isn't any products
                    this->state = IDLE;
                    this->pMachine->setAssistance();
                    this->pMachine->isErrorRefill();
                } else {
                    
                    if(this->pButtonUP->isPressed()) { //if first button is pressed

                        if(currentPos == 0 ) { 
                            if(pProduct[1].getQuantity()<=0) { //if the quantity of the specific product is not available
                                String menu = pProduct[2].getName(); 
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); //show still later product
                                currentPos = 2; //actual pos of product see in the menu
                            } else {
                                String menu = pProduct[1].getName(); //if the quantity of the specific product is available, show the next product
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); //show the name of product
                                currentPos = 1;
                            }
                        }

                        if(currentPos == 1 ) {
                                if(pProduct[2].getQuantity()<=0) { //if the quantity of the specific product is not available
                                String menu = pProduct[0].getName();
                                this->pDisplay->clear();
                                this->pDisplay->print(menu);
                                currentPos = 0;
                            } else {
                                String menu = pProduct[2].getName(); //show the next product
                                this->pDisplay->clear();
                                this->pDisplay->print(menu); 
                                currentPos = 2;
                            }
                        }

                        if(currentPos == 2 ) {
                                if(pProduct[0].getQuantity()<=0) { //if the quantity of the specific product is not available
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

                    if (this->pButtonDOWN->isPressed()) { //if second button is pressed

                        if(currentPos == 0 ) {
                            if(pProduct[2].getQuantity()<=0) { //if the quantity of the specific product is not available
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
                                if(pProduct[0].getQuantity()<=0) { //if the quantity of the specific product is not available
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
                                if(pProduct[0].getQuantity()<=0) { //if the quantity of the specific product is not available
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

                    this->pPotSugar->getPercentage(); //get the percentage of sugar

                    if(this->pButtonMAKE->isPressed()) { //after the button MAKE is pressed, start the make of product
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