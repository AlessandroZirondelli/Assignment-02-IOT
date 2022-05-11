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
#include "functions.h"

Scheduler* sched;
int periodsTask[]={START_PERIOD,SELECT_PERIOD,MAKE_PERIOD,WITHDRAW_PERIOD,SELFTEST_PERIOD,COMMUNICATION_PERIOD};
void setup() {
  sched = new Scheduler();

  int schedPeriod = calculateGCD(periodsTask,6);
  sched -> init(schedPeriod);

  Serial.begin(9600);
  Machine* mac = new Machine();
  Catalog* catalog = new Catalog();
  
  // array that contains product in the machine
  ProductListed* productInput[] = {new ProductListed(new Product("Chocolate"),MAX_QTN_CHOCOLATE),
                                   new ProductListed(new Product("Tea"),MAX_QTN_TEA),
                                   new ProductListed(new Product("Coffee"),MAX_QTN_COFFEE)}; 
  int lengthInput = sizeof(productInput)/sizeof(productInput[0]); //Mantain the size of array productInput
 
  for(int i = 0 ; i<lengthInput; i++){
    bool res = catalog -> addProduct(productInput[i]); // Add products to catalog
    if(res == false){
      mac->getManagerActuators()->getDisplay()->print("Max product reached");
    }
  }
  mac -> addCatalog(catalog); 


  Task* taskSelfTest = new SelfTask(mac);
  Task* taskWithdraw = new WithdrawTask(mac);
  Task* taskStartTask = new StartTask(mac);
  Task* taskCommunication = new CommunicationPcTask(mac);
  Task* taskSelect = new selectionProductTask(mac);
  Task* taskMakeProduct = new makeProductTask(mac);
  
  taskStartTask->init(START_PERIOD);
  sched->addTask(taskStartTask);

  taskSelect->init(SELECT_PERIOD);
  sched->addTask(taskSelect);

  taskMakeProduct->init(MAKE_PERIOD);
  sched->addTask(taskMakeProduct);

  taskWithdraw->init(WITHDRAW_PERIOD);
  sched->addTask(taskWithdraw);

  taskSelfTest->init(SELFTEST_PERIOD);
  sched->addTask(taskSelfTest);

  taskCommunication->init(COMMUNICATION_PERIOD);
  sched->addTask(taskCommunication);


  
}

void loop() {
  sched->schedule();
}