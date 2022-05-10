#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "tasks/Task.h"

#define MAX_TASKS 30

class Scheduler {
  
  int basePeriod; //  period of scheduler
  int nTasks;
  Task* taskList[MAX_TASKS];  //Array that mantain tasks

public:
  Scheduler();
  void init(int basePeriod);  
  virtual bool addTask(Task* task); 
  virtual void schedule();
};

#endif
