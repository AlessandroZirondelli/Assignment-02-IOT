#include "selectionProductTask.h"
#include "machine.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"
#include "config.h"

#define TIMEOUT 5 //SECONDS

selectionProductTask::selectionProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;

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
                //aggiorna lcd
            } else if (this->pButtonDOWN->isPressed()) {
                //aggiorna lcd
            }

            break;
        }
    }
    
}