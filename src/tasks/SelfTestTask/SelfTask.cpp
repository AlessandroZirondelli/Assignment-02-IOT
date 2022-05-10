#include "SelfTask.h"
#include "machine.h"
#include "config.h"
#include "./sensors/temp/TempSensorLM35.h"
#include "./actuators/servo/servo_motor_impl.h"

#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 
#define GAPROTATION 30


 SelfTask::SelfTask(Machine* machine) {
     this -> machine = machine;
     this ->tempSensor = this->machine->getManagerSensonrs()->getTemp();
     this ->servoMotor = this ->machine->getManagerActuators()->getServo();
     //this -> display = new Display();
     this -> state = IDLE;
     this -> time = 0;
 };

 void SelfTask::tick(){
    
    switch (state){
        case IDLE: { //need to check if it's possibile to do a self-test
            unsigned long curr = millis();
            Serial.println((curr-this->time)/1000);
            if(this->machine->isStart()){
                 if( ((curr-this->time)/1000) >= T_CHECK){ // if TCHECK time is passed 
                    this->servoMotor->setPosition(0);
                    this->machine->setSelfTest();
                    this->state = SIMULATION;
                    this->time = millis();
                    //display.print("Sono in idle");
                    Serial.println("Sono in idle"); 
                 }
            }  
            break;
        }

        case SIMULATION: {
            int currentAngle = this->servoMotor->getAnglePosition();
            if(currentAngle < 180){
                this->servoMotor->setPosition(currentAngle+GAPROTATION);
            } else if(currentAngle >= 180){
                this->servoMotor->setPosition(0);
                this->state = CHECK;
            }
            this -> machine -> incNumSelfTest();
            break;
        }

        case CHECK: {
            float temp = tempSensor->getTemperature();
            if( temp > TEMPMAX || temp < TEMPMIN){
                this->state = ERROR;
            } else {
                this->machine->setStart();
                this->state = IDLE;
            }
            break;
        }
        
        case ERROR: {
            //print on display LCD "Assistance required";
            //this->display->print("Assistance required");
            this->machine->setAssistance();
            this->machine->setTemperatureAlert();
            this->state = IDLE;
            Serial.println("Assistance required");
            break;
        }
    }
 };

