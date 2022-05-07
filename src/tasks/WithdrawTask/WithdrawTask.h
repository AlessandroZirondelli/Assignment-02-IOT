#ifndef __WITHDRAW__
#define __WITHDRAW__

#include "./tasks/Task.h"
#include "./machine.h"
#include "./actuators/sonar/Sonar.h"
#include "./actuators/servo/servo_motor.h"


class WithdrawTask : public Task{

public: 
    WithdrawTask(Machine* machine);
    void tick();

private:
    enum{IDLE,WAIT,REMOVAL} state;
    Machine * machine;
    ServoMotor * servo;
    Sonar * sonar;
};
#endif