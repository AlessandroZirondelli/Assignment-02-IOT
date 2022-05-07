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
                 Serial.println("Mi attivo");
                 this->state = WAIT;
                 
             }
             break;
         }

         case WAIT: {
             float distance = this -> sonar -> getDistance();
             Serial.print("Distanza");
             Serial.println(distance);
             if(distance < DISTANCE ){
                 this -> state = REMOVAL;
             }
            break;
         }

         case REMOVAL: {
             Serial.print("Sono in removal");
             this->servo->setPosition(0);
             this -> state = IDLE;
             this ->machine->setStart();
             break;
         }
     }
 };



