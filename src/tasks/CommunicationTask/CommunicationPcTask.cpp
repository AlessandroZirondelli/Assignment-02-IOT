#include "CommunicationPcTask.h"

CommunicationPcTask::CommunicationPcTask(Machine* machine) : machineCoffee(machine){
    state = UPDATE;

}
void CommunicationPcTask::tick(){
    switch (state){
        case UPDATE:
            
            
            state = CHECK;
            break;
        case CHECK:
            int qtnDisponibilty = machineCoffee -> getCatalog()->getTotalDisponibility();
            if(qtnDisponibilty == 0){
                machineCoffee ->setErrorRefill();
                state = COMMUNNICATION;
            }
            break;  
        case COMMUNNICATION:
            
            break;
        default:
            break;
        }
}










