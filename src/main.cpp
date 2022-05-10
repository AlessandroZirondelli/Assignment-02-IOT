#include <Arduino.h>
#include "machine.h"
#include "scheduler.h"
#include "config.h"
#include "./tasks/SelfTestTask/SelfTask.h"
#include "./tasks/WithdrawTask/WithdrawTask.h"
#include "./tasks/StartTask/StartTask.h"
#include "./tasks/CommunicationTask/CommunicationPcTask.h"
#include "./tasks/selectProductTask/selectionProductTask.h"
#include "./tasks/makeProductTask/makeProductTask.h"

Scheduler* sched;

void setup() {
  sched = new Scheduler();
  sched -> init(10);

  Serial.begin(9600);

  Machine* mac = new Machine();
  Catalog* catalog = new Catalog();
  
  // arary che contiene i prodotti con relativa quantità
  ProductListed* productInput[] = {new ProductListed(new Product("Chocolate"),MAX_QTN_CHOCOLATE),
                                   new ProductListed(new Product("Tea"),MAX_QTN_TEA),
                                   new ProductListed(new Product("Coffee"),MAX_QTN_COFFEE)}; 
  int lengthInput = sizeof(productInput)/sizeof(productInput[0]); // Lunghezza array che contiene i prodotti
 
  for(int i = 0 ; i<lengthInput; i++){
    bool res = catalog -> addProduct(productInput[i]); // Aggiungo i prodotti al catalogo
    if(res == false){
      Serial.print("Max product reached");
    }
  }
  mac -> addCatalog(catalog); // Aggiungo il catalogo all'oggetto Machine


  Task* taskSelfTest = new SelfTask(mac);
  Task* taskWithdraw = new WithdrawTask(mac);
  Task* taskStartTask = new StartTask(mac);
  Task* taskCommunication = new CommunicationPcTask(mac);
  Task* taskSelect = new selectionProductTask(mac);
  Task* taskMakeProduct = new makeProductTask(mac);
  
  taskStartTask->init(40);
  //sched->addTask(taskStartTask);

 

  taskSelect->init(40);
//  sched->addTask(taskSelect);

  taskMakeProduct->init(40);
  //sched->addTask(taskMakeProduct);

  taskWithdraw->init(40);
  //sched->addTask(taskWithdraw);

  taskSelfTest->init(100);
  //sched->addTask(taskSelfTest);

  taskCommunication->init(100);
  sched->addTask(taskCommunication);

}

void loop() {
  sched->schedule();
}