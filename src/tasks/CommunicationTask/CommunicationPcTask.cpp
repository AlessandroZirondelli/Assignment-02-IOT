#include "CommunicationPcTask.h"
#include "MsgService.h"
CommunicationPcTask::CommunicationPcTask(Machine* machine) : machineCoffee(machine){
    state = UPDATE;
    MsgService.init();

}
void CommunicationPcTask::tick(){
    int qtnDisponibilty = 0;
    switch (state){
        case UPDATE:
            
            
            state = CHECK;
            break;
        case CHECK:
            qtnDisponibilty = machineCoffee -> getCatalog()->getTotalDisponibility();
            if(qtnDisponibilty == 0){
                machineCoffee ->setErrorRefill();
                state = COMMUNICATION;
            }
            break;  
        case COMMUNICATION:
            Serial.print("Comunicazione");
            if (MsgService.isMsgAvailable()) {
                Msg* msg = MsgService.receiveMsg();    
                if (msg->getContent() == "refilled"){
                  //  machineCoffee
                    //MsgService.sendMsg("pong");
                }
                if (msg->getContent() == "unbroken"){
                    
                    //MsgService.sendMsg("pong");
                }
            
            
                delete msg;
            }
            break;
       
        }
}










