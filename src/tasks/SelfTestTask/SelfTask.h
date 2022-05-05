#ifndef __SELFTASK__
#define __SELFTASK__

#include "./tasks/Task.h"
#include "./machine.h"
#include "./actuators/temp/TempSensor.h"
#include "./actuators/servo/servo_motor.h"
#include "./actuators/display/display.h"

class SelfTask : public Task{

public: 
    SelfTask(Machine* machine);
    void tick();

private:
    enum{IDLE,SIMULATION,CHECK,ERROR} state;
    TempSensor * tempSensor;
    ServoMotor * servoMotor;
    Machine * machine;
    Display * display;

};
#endif