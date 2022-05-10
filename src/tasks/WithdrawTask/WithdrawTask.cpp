#include "machine.h"
#include "config.h"
#include "WithdrawTask.h"
#include "./actuators/sonar/Sonar.h"
#include "./actuators/servo/servo_motor_impl.h"


 WithdrawTask::WithdrawTask(Machine* machine) {
     this -> machine = machine;
     this -> sonar = this->machine->getManagerActuators()->getSonar();
     this -> servo = this->machine->getManagerActuators()->getServo();
     this -> state = IDLE;
     
 };

 void WithdrawTask::tick(){
     switch (state){
         case IDLE: {
             
             if(this->machine->isWait()){
                 this->state = WAIT;
                 this->time = millis();
             }
             break;
         }

         case WAIT: {
             float distance = this -> sonar -> getDistance();
             unsigned long int curr = millis();
             unsigned long int difference =(curr-time)/1000;
             if(distance < DISTANCE  ||  difference >= T_TIMEOUT ){
                 this -> state = REMOVAL;
             }
            break;
         }

         case REMOVAL: {
             this->servo->setPosition(0);
             this -> state = IDLE;
             this ->machine->setStart();
             break;
         }
     }
 };



