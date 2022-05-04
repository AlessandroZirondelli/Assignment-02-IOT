#include <Arduino.h>
#include "machine.h"
#include "scheduler.h"
#include "./sensors/pot/pot.h"
#include "./tasks/SelfTestTask/SelfTask.h"

Scheduler* sched;
void setup() {
 // Potentiometer* pot = new Potentiometer(A0);
  sched = new Scheduler();
  sched -> init(10);

  Serial.begin(9600);
  Machine* mac = new Machine();
  Product* productInput[] = {new Product("Chocolate",4),new Product("Coffee",5), new Product("Tea",4)}; 
  int lengthInput = sizeof(productInput)/sizeof(productInput[0]);
  for(int i = 0 ; i<lengthInput; i++){
    bool res = mac -> addProduct( productInput[i]);
    if(res == false){
      Serial.print("Max product reached");
    }
  }
  Task* taskSelfTest = new SelfTask(mac);
  taskSelfTest->init(5000); // periodo selftest,
  sched->addTask(taskSelfTest);
  
}

void loop() {
  //Serial.print(pot->getValue());
  sched->schedule();
}