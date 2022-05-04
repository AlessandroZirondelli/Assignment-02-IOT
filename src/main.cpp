#include <Arduino.h>
#include "machine.h"
 Machine* mac ;
void setup() {
  Serial.begin(9600);
  mac = new Machine();
 
}

void loop() {
  Serial.print( mac -> isStart());
  delay(1000);
}