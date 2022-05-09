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
            
          //  delete msg;
        

       
       
            this->state = CHECK;
            
            break;
        case CHECK:
            
            //qtnDisponibilty = machineCoffee -> getCatalog()->getTotalDisponibility();
            qtnDisponibilty = 1;
            if(machineCoffee->isErrorNone()){
                MsgService.sendMsg("Alert None");
                this->state = UPDATE;
            }if(machineCoffee->isErrorRefill()){
                MsgService.sendMsg("Alert Refill");
                this->state = COMMUNICATION;
            }if(machineCoffee->isTemperatureAlert()){
                MsgService.sendMsg("Alert Temperature");
                this->state = COMMUNICATION;
            }
            
            
             //Serial.println("Check");
            break;  
        case COMMUNICATION:
           
            if (MsgService.isMsgAvailable()) {
                Msg* msg = MsgService.receiveMsg();    
                if (msg->getContent() == "refilled"){
                    machineCoffee->setErrorNone();
                    machineCoffee->getCatalog()->setQtnProduct("Chocolate",MAX_QTN_CHOCOLATE);
                    machineCoffee->getCatalog()->setQtnProduct("Coffee",MAX_QTN_COFFEE);
                    machineCoffee->getCatalog()->setQtnProduct("Tea",MAX_QTN_TEA);
                    machineCoffee->setStart();
                    //MsgService.sendMsg("pong");
                }
                if (msg->getContent() == "unbroken"){
                     machineCoffee->setErrorNone();
                    machineCoffee->setStart();
                    //MsgService.sendMsg("pong");
                }
            
            
                delete msg;
            }
            // Serial.println("COMMUNICATION");
            this->state = UPDATE;
            break;
        
       
        }
}










