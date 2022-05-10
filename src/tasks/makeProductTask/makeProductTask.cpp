#include "makeProductTask.h"
#include "machine.h"
#include "ProductListed.h"
#include "./actuators/ManagerActuatorsImpl.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "config.h"

#define GAPROTATION 30

#define MSG_START "Making a "
#define MSG_COMPLETE " is ready"

makeProductTask::makeProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;

    this ->productsList = pMachine->getCatalog()->getProducts();
    this->posProdMaking = pMachine->getSelectedProduct();
    this ->pServoMotor = this ->pMachine->getManagerActuators()->getServo();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();

};

void makeProductTask::tick() { //this is the task where you make the product 
    switch (state){
        case IDLE: { //initialization
            if (this->pMachine->isMaking()){
                this->timeStartMake=millis();
                this->pServoMotor->setPosition(0);
                this->state = START;
            }
            break;
        }
        
        case START: { 
            this->pDisplay->clear();
            this->pDisplay->print( MSG_START + (*productsList[posProdMaking]).getProduct()->getName()); //print the name of the product when the making process starts
            this->state = MAKE;
            
            break;
        }

        case MAKE: {
            unsigned long currentTimeMake = millis(); 
            
            if (currentTimeMake - timeStartMake > T_MAKING) { //the process takes T_MAKING seconds to complete
                //currentTimeMake = millis();
                int currentAngle = this->pServoMotor->getAnglePosition();
                if(currentAngle < 180){
                    this->pServoMotor->setPosition(currentAngle + GAPROTATION); //the  process is simulated by a rotations of the motor
                } else if(currentAngle >= 180){
                    this->pServoMotor->setPosition(0);
                    this->state = COMPLETE;
                }                
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