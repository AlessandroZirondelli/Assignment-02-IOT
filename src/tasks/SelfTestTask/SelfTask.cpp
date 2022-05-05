#include "SelfTask.h"
#include "machine.h"
#include "config.h"
#include "./actuators/temp/TempSensorLM35.h"
#include "./actuators/servo/servo_motor_impl.h"

#define TCHECK 180 // seconds
#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 
#define GAPROTATION 30


 SelfTask::SelfTask(Machine* machine) {
     this -> machine = machine;
     this -> tempSensor = new TempSensorLM35(TMP_PIN);
     this -> servoMotor = new ServoMotorImpl(SERVO_PIN);
     this -> servoMotor ->on();
     //this -> display = new Display();
     this -> state = IDLE;
 };

 void SelfTask::tick(){
    switch (state){
        case IDLE: { //need to check if it's possibile to do a self-test
            if(this->machine->isStart()){
                this->servoMotor->setPosition(0);
                this->machine->setSelfTest();
                this->state = SIMULATION;
                Serial.println("Sono in idle");
            }   
            break;
        }

        case SIMULATION: {
            Serial.println("Sono in simulation");
            int currentAngle = this->servoMotor->getAnglePosition();
            if(currentAngle < 180){
                this->servoMotor->setPosition(currentAngle+GAPROTATION);
            } else if(currentAngle >= 180){
                this->servoMotor->setPosition(0);
                this->state = CHECK;
            }
            Serial.print("Angolo ");
            Serial.println(currentAngle);
            break;
        }

        case CHECK: {
            Serial.println("Sono in check");
            float temp = tempSensor->getTemperature();
            if( temp > TEMPMAX || temp < TEMPMIN){
                this->state = ERROR;
            } else {
                this->machine->setStart();
                this->state = IDLE;
            }
            Serial.print("Temp");
            Serial.println(temp);
            break;
        }
        
        case ERROR: {
            //print on display LCD "Assistance required";
            //this->display->print("Assistance required");
            this->machine->setAssistance();
            this->state = IDLE;
            Serial.println("Assistance required");
            break;
        }
    }
 };

