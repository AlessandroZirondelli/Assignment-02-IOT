#include "SelfTask.h"
#include "machine.h"
#include "config.h"
#include "./actuators/temp/TempSensorLM35.h"
#include "./actuators/servo/servo_motor_impl.h"

#define TCHECK 180 // seconds
#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 
#define GAPROTATION 5


 SelfTask::SelfTask(Machine* machine) {
     this -> machine = machine;
     this -> tempSensor = new TempSensorLM35(TMP_PIN);
     this -> servoMotor = new ServoMotorImpl(SERVO_PIN);
     //this -> display = new Display();
     this -> state = IDLE;
 };

 void SelfTask::tick(){
    switch (state){
        case IDLE: { //need to check if it's possibile to do a self-test
            if(this->machine->isStart()){
                this->machine->setSelfTest();
                this->state = CHECK;
            }   
        }

        case SIMULATION: {
            int currentAngle = this->servoMotor->getAnglePosition();
            if(currentAngle < 180){
                this->servoMotor->setPosition(currentAngle+GAPROTATION);
            } else if(currentAngle >= 180){
                this->servoMotor->setPosition(0);
                this->state = CHECK;
            }
        }

        case CHECK: {
            if(tempSensor->getTemperature() > TEMPMAX || tempSensor->getTemperature() < TEMPMIN){
                this->state = ERROR;
            } else {
                this->machine->setStart();
            }
        }
        
        case ERROR: {
            //print on display LCD "Assistance required";
            //this->machine->setAssistance();
            //this->display->print("Assistance required");
        }
    }
 };

