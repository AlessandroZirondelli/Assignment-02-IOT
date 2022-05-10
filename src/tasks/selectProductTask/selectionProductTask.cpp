#include "selectionProductTask.h"
#include "machine.h"
#include "config.h"
#include "ProductListed.h"
#include "./actuators/ManagerActuatorsImpl.h"
#include "./sensors/ManagerSensorsImpl.h"


selectionProductTask::selectionProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;
    this-> pProduct = new ProductListed();
    this -> pPotSugar = this->pMachine->getManagerSensonrs()->getPot();
    this->pButtonUP = this->pMachine->getManagerSensonrs()->getButtonUp();
    this->pButtonDOWN = this->pMachine->getManagerSensonrs()->getButtonDown();
    this->pButtonMAKE = this->pMachine->getManagerSensonrs()->getButtonMake();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();
    this->currentPos = 0;
};

void selectionProductTask::nextSelection(){
    currentPos++;
    if(currentPos>=3){
        currentPos=0;
    }
}
void selectionProductTask::prevSelection(){
    currentPos--;
    if(currentPos<=1){
        currentPos=2;
    }
    
}
void selectionProductTask::tick() { //this is the task where you select the product you want
    switch (state){
        case IDLE: { //initialization
            this->timeStart = millis();
            this->currentPos = 0;
            this->state = SELECT;
            //this->pDisplay->print(this->pMachine->getCatalog()->getProducts()); //printo sul display il primo prodotto
            break;
        }
        
        case SELECT: { 
            if(!this->pButtonMAKE->isPressed()){ //if user doesn't press make button for T_BUTTON time , system return on START state
                unsigned long int current = millis();
                if(current-timeStart>=T_BUTTON){
                    this->state=IDLE;
                    this->pMachine->setStart();
                    break;
                }
            }   
            else if (this->pButtonMAKE->isPressed()){ // if button make is pressed
                this->pMachine->setMaking(); //
                this->state = IDLE;
                break; 
            }
            else{ 
                if(this->pButtonDOWN->isPressed()){
                    this->nextSelection();
                    this->timeStart=millis(); //reset time , so the counter will count again 5 seconds
                    //print new product through access array with position
                }
                if(this->pButtonUP->isPressed()){
                    this->prevSelection();
                    this->timeStart=millis();//reset time , so the counter will count again 5 seconds
                    //print new product through access array with position currentPos
                } 
            } 
        }
    }
    
}