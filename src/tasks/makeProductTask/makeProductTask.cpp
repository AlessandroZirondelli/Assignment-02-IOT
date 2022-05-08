#include "makeProductTask.h"
#include "machine.h"
#include "product.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "config.h"

#define GAPROTATION 5

#define MSG_START "Making a "
#define MSG_COMPLETE " is ready"

makeProductTask::makeProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;
    this-> pProduct = pProduct;
    
    this ->pServoMotor = this ->pMachine->getManagerActuators()->getServo();
    this->pDisplay = this->pMachine->getManagerActuators()->getDisplay();

    
};

void makeProductTask::tick() {
    switch (state){
        case IDLE: {
            if(this->pMachine->isMaking()){
                this->state = START;
            }
            break;
        }
        
        case START: {
            this->pDisplay->clear();
            this->pDisplay->print( MSG_START + this->pProduct->getName());
            this->state = MAKE;
            break;
        }

        case MAKE: {

            unsigned long timeStartMake=0;
            unsigned long currentTimeMake = millis(); 
            if (currentTimeMake - timeStartMake > T_MAKING) {

                //motore arriva a 180 fino a tempo tmaking

                currentTimeMake = millis();
                int currentAngle = this->pServoMotor->getAnglePosition();
                if(currentAngle < 180){
                    this->pServoMotor->setPosition(currentAngle+GAPROTATION);
                } else if(currentAngle >= 180){
                    this->pServoMotor->setPosition(0);
                    this->state = COMPLETE;
                }                
            }
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