#include "CommunicationPcTask.h"
#include "MsgService.h"
CommunicationPcTask::CommunicationPcTask(Machine* machine) : machineCoffee(machine){
    state = UPDATE;
    MsgService.init();

}
void CommunicationPcTask::tick(){
    int qtnDisponibilty = 0;
    
    String num = String(0);
    int i =0;
    String* stringa[3] = {new String("Chocolate"),new String("Tea"), new String("Coffee")};
    Catalog* catalog1 = machineCoffee->getCatalog();

    switch(this->state){
        case UPDATE:
           // Msg* msg = MsgService.receiveMsg(); 
            if(machineCoffee->isAssistance()){
                MsgService.sendMsg("State Assistance");
            }else if(machineCoffee->isStart()){
               MsgService.sendMsg("State Idle"); 
            }else{
                MsgService.sendMsg("State Working"); 
                 
            }
            //char* stringa[3] = {"Chocolate","Tea","Coffee"};
         

            for(int i = 0; i<3; i++){
                int qtn = catalog1->getQtnProduct(*stringa[i]);
                num = String(qtn);
                
                MsgService.sendMsg(*stringa[i] + " " + num ); 
                 //Serial.println(*stringa[i] + " " + num);
            }
              MsgService.sendMsg("SelfTest " + String(machineCoffee->getNumSelfTest())); 
              // Serial.println("SelfTest " + String(machineCoffee->getNumSelfTest()));
            machineCoffee->addNumSelfTest();
          //  delete msg;
        

       
       
            this->state = CHECK;
            
            break;
        case CHECK:
            
            //qtnDisponibilty = machineCoffee -> getCatalog()->getTotalDisponibility();
            qtnDisponibilty = 1;
            if(qtnDisponibilty == 0){
                //machineCoffee ->setErrorRefill();
                
                this->state = COMMUNICATION;
            }else{
                this->state = UPDATE;
            }
             //Serial.println("Check");
            break;  
        case COMMUNICATION:
         /*   Serial.print("Comunicazione");
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
            }*/
            // Serial.println("COMMUNICATION");
            this->state = UPDATE;
            break;
        
       
        }
}










