#include "StartTask.h"
#include "machine.h"
#include "config.h"
#include "Arduino.h"

#include <avr/sleep.h>
#include <avr/power.h>

 StartTask::StartTask(Machine* machine) {
     this -> machine = machine;
     this -> pir = this->machine->getManagerSensonrs()->getPir();
     this->state = INIT;
     this->display = this->machine ->getManagerActuators()->getDisplay();
     attachInterrupt(digitalPinToInterrupt(PIR_PIN),wakeUp,RISING); 
 };

 void StartTask::wakeUp(){

 }

 void StartTask::tick(){
     switch(state){
        case INIT: {
            if(this->machine->isStart()){
                display->print("Welcome");
                this->state = IDLE;
            }
            break; 
        }

        case IDLE: {
            if(this->machine->isStart()){
                display->print("Ready");
                this->state = CHECK;
                this->time = millis();
            }
            break;
        }

        case CHECK: {
            if(this->machine->getCatalog()->getTotalDisponibility()==0){ //if there aren't any products
                this->state=ERROR;
                break;
            }
            if(!(this->pir->isDetected())){ //if user is not detected by pir
                unsigned long current = millis();
                if(((current-time)/1000) > T_IDLE){ //if time timeout passed , go to sleep mode
                    this->state = SLEEP;
                    break;
                }
            } else{ //if user is detected by pir
                this->state = IDLE;
                this->machine->setSelect();
                break;
            }
            break;
        }

        case ERROR: { //alert error
            this->machine->setErrorRefill();
            this->machine->setAssistance();
            this->state = IDLE;
            this->display->print("Assistance required");
            break;
        }

        case SLEEP:{
            
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            sleep_disable();
            //Serial.println("SONO IN SLEEP E DEVO DORMIRE 5 sec");
            
            this->state = IDLE;

        }


     }

 };

