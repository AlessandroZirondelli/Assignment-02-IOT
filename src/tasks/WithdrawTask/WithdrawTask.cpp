#include "machine.h"
#include "config.h"

#include "WithdrawTask.h"


 WithdrawTask::WithdrawTask(Machine* machine) {
     this -> machine = machine;
     //this -> sonar = new Sonar();
 };

 void WithdrawTask::tick(){
     switch (state){
         case IDLE: {
             if(this->machine->isWait()){
                 this->state = WAIT;
             }
         }

         case WAIT: {}

         case REMOVAL: {}
     }
 };



