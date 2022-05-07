#include "StartTask.h"
#include "machine.h"
#include "config.h"
#include "Arduino.h"

#include "./avr/sleep.h"
#include "./avr/power.h"

 StartTask::StartTask(Machine* machine) {
     this -> machine = machine;
     this -> pir = this->machine->getManagerSensonrs()->getPir();
     this->state = INIT;
     //attachInterrupt(digitalPinToInterrupt(PIR_PIN),wakeUp,RISING); TO INSERT
 };

 void StartTask::tick(){
     switch(state){
        case INIT: {
            if(this->machine->isStart()){
                Serial.println("Welcome");  
                this->state = IDLE;
            }
            break; 
        }

        case IDLE: {
            if(this->machine->isStart()){
                Serial.println("Ready");
                this->state = CHECK;
                this->time = millis();
            }
            break;
        }

        case CHECK: {
            Serial.println("Sono in check");
            if(this->machine->getCatalog()->getTotalDisponibility()==0){ //if there aren't any products
                this->state=ERROR;
                Serial.println("Prodotti terminati");
                break;
            }
            if(!(this->pir->isDetected())){ //if user is not detected by pir
                unsigned long current = millis();
                if(((current-time)/1000) > T_TIMEOUT){ //if time timeout passed , go to sleep mode
                    this->state = SLEEP;
                    break;
                }
                Serial.println("Not detected  user");
            } else{ //if user is detected by pir
                //this->time = millis(); //reset counting time for T_IDLE
                this->state = IDLE;
                this->machine->setSelect();
                Serial.println("Detected user");
                break;
            }
            break;
        }

        case ERROR: {
            this->machine->setErrorRefill();
            this->machine->setAssistance();
            break;
        }

        case SLEEP:{
            
            /*set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            sleep_disable();*/
            Serial.println("SONO IN SLEEP E DEVO DORMIRE 5 sec");
            delay(5000);//to delete. It's only a test
            this->state = IDLE;

        }


     }

 };

