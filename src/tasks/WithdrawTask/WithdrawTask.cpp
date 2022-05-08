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
     //this -> time = 0;
     
 };

 void WithdrawTask::tick(){
     switch (state){
         case IDLE: {
             
             if(this->machine->isWait()){
                 Serial.println("Mi attivo");
                 this->state = WAIT;
                 this->time = millis();
             }
             break;
         }

         case WAIT: {
             float distance = this -> sonar -> getDistance();
             Serial.print("Distanza");
             Serial.println(distance);
             unsigned long int curr = millis();
             unsigned long int difference =(curr-time)/1000;
             Serial.println(difference);
             if(distance < DISTANCE  ||  difference >= 5 ){
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



