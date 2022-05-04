#include "SelfTask.h"
#include "machine.h"

#define TCHECK 180 // seconds
#define TEMPMIN 17 // Celsius degrees 
#define TEMPMAX 24 // Celsius degrees 


 SelfTask::SelfTask(Machine* machine) {
     this-> machine = machine;
 };

