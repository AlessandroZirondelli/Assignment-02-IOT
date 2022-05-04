#ifndef __SELFTASK__
#define __SELFTASK__

#include "./tasks/Task.h"
#include "./machine.h"
#include "./actuators/temp/TempSensor.h"
#include "./actuators/servo/servo_motor.h"



class SelfTask : public Task{

public: 
    SelfTask(Machine* machine);
    void tick();

private:
    enum{IDLE,CHECK,ERROR};
    TempSensor * tempSensor;
    ServoMotor * servoMotor;
    Machine * machine;
};
#endif