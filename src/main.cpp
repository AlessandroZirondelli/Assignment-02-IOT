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
  sched -> init(100);

  Serial.begin(9600);
  Machine* mac = new Machine();
  Catalog* catalog = new Catalog();
  
  ProductListed* productInput[] = {new ProductListed(new Product("Chocolate"),MAX_QTN_CHOCOLATE),
                                   new ProductListed(new Product("Tea"),MAX_QTN_TEA),
                                   new ProductListed(new Product("Coffee"),MAX_QTN_COFFEE)}; 
  int lengthInput = sizeof(productInput)/sizeof(productInput[0]);
  for(int i = 0 ; i<lengthInput; i++){
    bool res = catalog -> addProduct( productInput[i]);
    if(res == false){
      Serial.print("Max product reached");
    }
  }
  mac -> addCatalog(catalog);


  Task* taskSelfTest = new SelfTask(mac);
  Task* taskWithdraw = new WithdrawTask(mac);
  Task* taskStartTask = new StartTask(mac);
  Task* taskCommunication = new CommunicationPcTask(mac);
  Task* taskSelect = new selectionProductTask(mac);
  Task* taskMakeProduct = new makeProductTask(mac);
  
  //taskSelfTest->init(500); // periodo selftest,
  //sched->addTask(taskSelfTest);

  //taskWithdraw->init(4000);
  //sched->addTask(taskWithdraw);

  //mac->setWait();
  //sched->addTask(taskWithdraw);

  taskStartTask->init(2000);
  //sched->addTask(taskStartTask);
<<<<<<< HEAD
  
  taskCommunication->init(1000);
  //sched->addTask(taskCommunication);

  taskSelect->init(1000);
  //sched->addTask(taskSelect);

  taskMakeProduct->init(1000);
  sched->addTask(taskMakeProduct);

=======
  taskCommunication->init(500);
  sched->addTask(taskCommunication);

>>>>>>> master
}

void loop() {

 sched->schedule();
   
}