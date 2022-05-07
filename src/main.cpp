#include <Arduino.h>
#include "machine.h"
#include "scheduler.h"
#include "config.h"
#include "./tasks/SelfTestTask/SelfTask.h"
#include "./tasks/WithdrawTask/WithdrawTask.h"
#include "./sensors/pir/pir.h"


Scheduler* sched;
void setup() {
  //Pir* pir = new Pir(PIT_PIN);
  //pir->calibrate(); 
  sched = new Scheduler();
  sched -> init(10);

  Serial.begin(9600);
  Machine* mac = new Machine();
  Catalog* catalog = new Catalog();
  
  ProductListed* productInput[] = {new ProductListed(new Product("Chocolate"),1),
                                   new ProductListed(new Product("Tea"),2),
                                   new ProductListed(new Product("Coffee"),3)}; 
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
  //taskSelfTest->init(500); // periodo selftest,
  //sched->addTask(taskSelfTest);
  taskWithdraw->init(4000);
  sched->addTask(taskWithdraw);

  mac->setWait();
  sched->addTask(taskWithdraw);

}

void loop() {

  sched->schedule();
}