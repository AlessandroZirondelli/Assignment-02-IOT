#include "makeProductTask.h"
#include "machine.h"
#include "product.h"

#include "./sensors/button/ButtonImpl.h"
#include "./actuators/display/display.h"
#include "./actuators/servo/servo_motor_impl.h"
#include "config.h"

#define TMAKING 10 //sec
#define GAPROTATION 5

#define MSG_START "Making a "
#define MSG_COMPLETE " is ready"

makeProductTask::makeProductTask(Machine* pMachine) {
    this -> state = IDLE;
    this -> pMachine = pMachine;
    this-> pProduct = pProduct;
    this->pServoMotor = new ServoMotorImpl(SERVO_PIN);
    pDisplay->setup();

    this -> pDisplay = new Display(0x27,16,2);
    
};

void makeProductTask::tick() {
    switch (state){
        case IDLE: {
            if(this->pMachine->isSelect()){
                this->pMachine->setMaking();
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
            if (currentTimeMake - timeStartMake > TMAKING) {

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