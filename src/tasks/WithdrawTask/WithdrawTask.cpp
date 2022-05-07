#include "machine.h"
#include "config.h"
#include "WithdrawTask.h"
#include "./actuators/sonar/Sonar.h"
#include "./actuators/servo/servo_motor_impl.h"


 WithdrawTask::WithdrawTask(Machine* machine) {
     this -> machine = machine;
     this -> sonar = new Sonar(ECHO_PIN,TRIG_PIN,10000);
     this -> servo = new ServoMotorImpl(SERVO_PIN);
     this -> servo -> on();
 };

 void WithdrawTask::tick(){
     switch (state){
         case IDLE: {
             if(this->machine->isWait()){
                 this->state = WAIT;
                 break;
             }
         }

         case WAIT: {
             float distance = this -> sonar -> getDistance();
             if(distance < 40 ){
                 this -> state = REMOVAL;
             }
            break;
         }

         case REMOVAL: {
             this->servo->setPosition(0);
             this -> state = IDLE;
             this ->machine->setStart();
         }
     }
 };



