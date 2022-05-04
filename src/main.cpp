#include <Arduino.h>
#include "machine.h"

 Machine* mac ;
void setup() {
  Serial.begin(9600);
  mac = new Machine();
  Product* productInput[] = {new Product("Chocolate",4),new Product("Coffee",5), new Product("Tea",4)}; 
  int lengthInput = sizeof(productInput)/sizeof(productInput[0]);
 // Serial.print(lengthInput);
  Serial.println(productInput[0] -> getName().equals("Chocolatem"));
  for(int i = 0 ; i<lengthInput; i++){
    bool res = mac -> addProduct( productInput[i]);
    Serial.print(res);
  }
  
}

void loop() {

 // Serial.println(mac->getQtnProduct("Chocolate"));
  //Serial.println(mac->getQtnProduct("Coffee"));
  //Serial.println(mac->getQtnProduct("Tea"));
  delay(1000);
}