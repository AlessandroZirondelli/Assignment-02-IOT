#include "SelfTask.h"
#include "machine.h"
#include "config.h"
#include "./sensors/temp/TempSensorLM35.h"
#include "./actuators/servo/servo_motor_impl.h"



#define GAPROTATION 30

 SelfTask::SelfTask(Machine* machine) {
     this -> machine = machine;
     this ->tempSensor = this->machine->getManagerSensonrs()->getTemp();
     this ->servoMotor = this ->machine->getManagerActuators()->getServo();
     this -> display = this -> machine->getManagerActuators()->getDisplay();
     this -> state = IDLE;
     this -> time = millis();
 };

 void SelfTask::tick(){
    
    switch (state){
        case IDLE: { //need to check if it's possibile to do a self-test
            unsigned long curr = millis();
            if(this->machine->isStart()){
                 if( ((curr-this->time)/1000) >= T_CHECK){ // if TCHECK time is passed 
                    this->servoMotor->setPosition(0);
                    this->machine->setSelfTest();
                    this->state = SIMULATION;
                    this->time = millis();
                 }
            }  
            break;
        }

        case SIMULATION: {//move servo motor
            int currentAngle = this->servoMotor->getAnglePosition();
            if(currentAngle < 180){
                this->servoMotor->setPosition(currentAngle+GAPROTATION);
            } else if(currentAngle >= 180){
                this->servoMotor->setPosition(0); //reset position 
                this->state = CHECK;
            }
            this -> machine -> incNumSelfTest();
            break;
        }

        case CHECK: {
            float temp = tempSensor->getTemperature();
            if( temp > TEMPMAX || temp < TEMPMIN){ //temperature not in range
                this->state = ERROR;
            } else { //temperature in range
                this->machine->setStart();
                this->state = IDLE;
            }
            break;
        }
        
        case ERROR: {
            //print on display LCD "Assistance required";
            this->display->print("Assistance required");
            this->machine->setAssistance();
            this->machine->setTemperatureAlert();
            this->state = IDLE;
            break;
        }
    }
 };

