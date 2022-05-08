#include <Arduino.h>
#include "machine.h"
#include "scheduler.h"
#include "config.h"
#include "./tasks/SelfTestTask/SelfTask.h"
#include "./tasks/WithdrawTask/WithdrawTask.h"
#include "./sensors/pir/pir.h"
#include "./tasks/StartTask/StartTask.h"
#include "./tasks/CommunicationTask/CommunicationPcTask.h"
 Pir* pir;
Scheduler* sched;

void setup() {
  //Pir* pir = new Pir(PIT_PIN);
  //pir->calibrate(); 
  sched = new Scheduler();
  sched -> init(50);

  Serial.begin(9600);
  Machine* mac = new Machine();
  Catalog* catalog = new Catalog();
  
  ProductListed* productInput[] = {new ProductListed(new Product("Chocolate"),40),
                                   new ProductListed(new Product("Tea"),30),
                                   new ProductListed(new Product("Coffee"),50)}; 
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
  //taskSelfTest->init(500); // periodo selftest,
  //sched->addTask(taskSelfTest);
  //taskWithdraw->init(4000);
  //sched->addTask(taskWithdraw);

  //mac->setWait();
  //sched->addTask(taskWithdraw);

  //taskStartTask->init(2000);
  //sched->addTask(taskStartTask);
  taskCommunication->init(500);
  sched->addTask(taskCommunication);


}

void loop() {

  sched->schedule();
   
}