#include "CommunicationPcTask.h"
#include "MsgService.h"
#include "Arduino.h"

/**
 * Initialize state update
 * */
CommunicationPcTask::CommunicationPcTask(Machine* machine) : machineCoffee(machine){
    state = UPDATE;
    MsgService.init();
}
void CommunicationPcTask::tick(){

    String qtnProd = String(0); // var that contain quantity of a product
    Catalog* catalog = machineCoffee->getCatalog(); 
    this->productsList =  machineCoffee->getCatalog()->getProducts(); // Take array of products

    switch(this->state){
        case UPDATE: //Send data for refresh GUI
            
            if(machineCoffee->isAssistance()){ // Send the state of machine. the message is composed of two parts: the first one is the string "State " and the second one the state of machine 
                MsgService.sendMsg("State Assistance");
            }else if(machineCoffee->isStart()){
               MsgService.sendMsg("State Idle"); 
            }else{
                MsgService.sendMsg("State Working");   
            }
            for(int i = 0; i<3; i++){
                qtnProd = String(catalog->getQtnProduct((*productsList[i]).getProduct()->getName())); // Take quantity of a product from catalog
                MsgService.sendMsg((*productsList[i]).getProduct()->getName() + " " + qtnProd); // Send a message with the name of product and quantity
            }
            MsgService.sendMsg("SelfTest " + String(machineCoffee->getNumSelfTest())); // Send number of executed self-test until now
            
            this->state = CHECK;
            break;

        case CHECK: //Send a message with the type of error 
            if(machineCoffee->isErrorNone()){ //It is sent a message with "Alert None" if there isnt an error
                MsgService.sendMsg("Alert None");
                this->state = UPDATE;
            }if(machineCoffee->isErrorRefill()){ // It is sent a message with "Alert Refill" if the machien must be refilled
                MsgService.sendMsg("Alert Refill");
                this->state = COMMUNICATION;
            }if(machineCoffee->isTemperatureAlert()){ // It is sent a message with "Alert Temperature" if the temperature is out of bound
                MsgService.sendMsg("Alert Temperature");
                this->state = COMMUNICATION;
            }
            break;  

        case COMMUNICATION: //If there is an error the machine wait a message from PC
            if(MsgService.isMsgAvailable()) {
                Msg* msg = MsgService.receiveMsg();    
                if (msg->getContent().equals("refilled")){ // If it is received "refilled" all the products' quantity are set to max value
                    
                    machineCoffee->setErrorNone();
                    machineCoffee->getCatalog()->setQtnProduct("Chocolate",MAX_QTN_CHOCOLATE); //Set the quantity of chocolate
                    machineCoffee->getCatalog()->setQtnProduct("Coffee",MAX_QTN_COFFEE); // Set the quantity of coffee
                    machineCoffee->getCatalog()->setQtnProduct("Tea",MAX_QTN_TEA); // Set the quantity of tea
                    machineCoffee->setStart();
                    this->state = UPDATE;
                }
                if (msg->getContent() == "unbroken"){ // If it is received "unbroken" the machine is set to state of "Start"
                   
                    machineCoffee->setErrorNone();
                    machineCoffee->setStart();
                    this->state = UPDATE;
                }
                delete msg;
            }
            break;
    }
}










