#include "makeProductTask.h"
#include "machine.h"
#include "product.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "config.h"

#define TMAKING 10 //sec

#define MSG_START "Making a "
#define MSG_COMPLETE " is ready"

makeProductTask::makeProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;
    this-> pProduct = pProduct;

    //this -> pPotSugar = new ;
    this -> pDisplay = new Display(0x27,16,2);
    pDisplay->setup();
};

void makeProductTask::tick() {
    switch (state){
        case IDLE: {
            if(this->pMachine->isStart()){
                this->pMachine->setMaking();
                this->state = START;
            }
            break;
        }
        
        case START: {
            this->pDisplay->print( MSG_START + this->pProduct->getName());
            this->state = MAKE;
            break;
        }

        case MAKE: {
            //gira il motore
            //passa il tempo
            break;
        }

        case COMPLETE: {
            this->pDisplay->clear();
            this->pDisplay->print(this->pProduct->getName() + MSG_COMPLETE);
            this->pMachine->setWait();
            this->state = IDLE;
            break;
        }
    }
    
}