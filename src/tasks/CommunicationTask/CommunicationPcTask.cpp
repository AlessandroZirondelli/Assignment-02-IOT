#include "CommunicationPcTask.h"
#include "MsgService.h"
#include "Arduino.h"

/**
 * Inizializzo lo stato iniziale ad UPDATE e il manager per la gestione della comunicazione
 * */
CommunicationPcTask::CommunicationPcTask(Machine* machine) : machineCoffee(machine){
    state = UPDATE;
    MsgService.init();

}
void CommunicationPcTask::tick(){
    
    
    String qtnProd = String(0); // variabile stringa che conterrà la quantità di un prodotto
    String* nameProduct[3] = {new String("Chocolate"),new String("Tea"), new String("Coffee")}; // Array nome prodotti
    Catalog* catalog = machineCoffee->getCatalog(); 

    switch(this->state){
        case UPDATE: //In questa fase invio dati per l'aggiornamento della GUI
            
            if(machineCoffee->isAssistance()){ // invio stringa -> "State " + statomachineCoffee; in base in quale stato si trova la macchina del caffee
                MsgService.sendMsg("State Assistance");
            }else if(machineCoffee->isStart()){
               MsgService.sendMsg("State Idle"); 
            }else{
                MsgService.sendMsg("State Working");   
            }
            for(int i = 0; i<3; i++){
                qtnProd = String(catalog->getQtnProduct(*nameProduct[i]));
                MsgService.sendMsg(*nameProduct[i] + " " + qtnProd ); // Invio il nome del prodotto con la relativa quantità
            }
            MsgService.sendMsg("SelfTest " + String(machineCoffee->getNumSelfTest())); // Invio il numero di self-test eseguiti fino ad adesso
            
            this->state = CHECK;
            break;

        case CHECK: //Invio una stringa chce descrive se la macchina è in errore o meno e se sì indica la tipologia di errore
            
            if(machineCoffee->isErrorNone()){ // Si verifica se la macchina non è in errore
                MsgService.sendMsg("Alert None");
                this->state = UPDATE;
            }if(machineCoffee->isErrorRefill()){ // Si verifica se i prodotti sono tutti finiti
                MsgService.sendMsg("Alert Refill");
                this->state = COMMUNICATION;
            }if(machineCoffee->isTemperatureAlert()){ // Si verifica se la macchina ha avuto una temperatura anomala
                MsgService.sendMsg("Alert Temperature");
                this->state = COMMUNICATION;
            }
            break;  

        case COMMUNICATION: // Se la macchina è in uno stato d'errore si aspetta un input dal pc per fare il refill dei prodotto o per essere resettato allo stato di "Start"
            if (MsgService.isMsgAvailable()) {
                Msg* msg = MsgService.receiveMsg();    
                if (msg->getContent().equals("refilled")){ // Se il pc manda un segnale di "refilled" si riforniscono tutti i prodotti con la max quantità possibile
                    
                    machineCoffee->setErrorNone();
                    machineCoffee->getCatalog()->setQtnProduct("Chocolate",MAX_QTN_CHOCOLATE); //Risetto max quantità per cioccolato
                    machineCoffee->getCatalog()->setQtnProduct("Coffee",MAX_QTN_COFFEE); // Risetto max quantità per coffee
                    machineCoffee->getCatalog()->setQtnProduct("Tea",MAX_QTN_TEA); // Risetto max quantità per tea
                    machineCoffee->setStart();
                    this->state = UPDATE;
                }
                if (msg->getContent() == "unbroken"){ // Se il pc manda un segnale di "unbroken" il pc si mette in stato "Start" per poter ripartire
                   
                    machineCoffee->setErrorNone();
                    machineCoffee->setStart();
                    this->state = UPDATE;
                }
                delete msg;
            }
            break;
    }
}










