#include "makeProductTask.h"
#include "machine.h"
#include "ProductListed.h"
#include "./actuators/ManagerActuatorsImpl.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "config.h"


#define MSG_START "Making a "
#define MSG_COMPLETE " is ready"

#define MAX_ROTATION 180 //degree
makeProductTask::makeProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;

    this ->productsList = this->pMachine->getCatalog()->getProducts();
    this->posProdMaking = this->pMachine->getSelectedProduct();
    this ->pServoMotor = this ->pMachine->getManagerActuators()->getServo();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();
    this->gapRotation =  1;
    this->gapRotationTime = T_MAKING / MAX_ROTATION; // time in seconds to do an angle of 1 degree
};

void makeProductTask::tick() { //this is the task where you make the product 
    switch (state){
        case IDLE: { //initialization
            if (this->pMachine->isMaking()){  
                this->pServoMotor->setPosition(0);
                this->state = START;
            }
            break;
        }
        
        case START: { 
            this->pDisplay->clear();
            this->pDisplay->print( MSG_START + (*productsList[posProdMaking]).getProduct()->getName()); //print the name of the product when the making process starts
            this->state = MAKE;
            this->timeStartMake=millis();
            this->timeToRotate=millis();
            break;
        }

        case MAKE: {
            unsigned long currentTimeMake = millis(); 
            
            if (((currentTimeMake - timeStartMake)/1000) < T_MAKING) { // making, check if it's passed time to finish make product 
                unsigned long currentTimeToRotate= millis();
                if(((currentTimeToRotate-timeToRotate)/1000) >= this->gapRotationTime ){ //check if passed enough time to move servo of one degree
                    int currentPos =  this->pServoMotor->getAnglePosition();
                    this->pServoMotor->setPosition(currentPos + this->gapRotation);
                    this->timeToRotate=millis();
                }

            }else{ //finish making
                this->state=COMPLETE;
            }
            break;
        }

        case COMPLETE: {
            this->pDisplay->clear(); 
            this->pDisplay->print((*productsList[posProdMaking]).getProduct()->getName()+ MSG_COMPLETE); //print complete message
            this->pMachine->setWait();
            this->state = IDLE;
            
            break;
        }
    }
    
}