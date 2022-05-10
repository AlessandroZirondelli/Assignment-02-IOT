#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "tasks/Task.h"

#define MAX_TASKS 30

class Scheduler {
  
  int basePeriod; //  periodo dello scheduler
  int nTasks;
  Task* taskList[MAX_TASKS];  //Array che contengono i task

public:
  Scheduler();
  void init(int basePeriod);  
  virtual bool addTask(Task* task);  //Aggiungo al task
  virtual void schedule();
};

#endif
