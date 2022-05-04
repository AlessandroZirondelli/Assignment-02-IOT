#include <Arduino.h>
//#include <string>
#include "product.h"
Product::Product(){
    this->quantity = 0;
    this->name = "";
}
Product::Product(String name, int quantity){
    this->quantity = quantity;    
    this->name = name;
}
String Product::getName(){
    return this->name;
}
void Product::setName(String name){
    this->name = name;
}
int Product::getQuantity(){
    return this->quantity;
}
void Product::setQuantity(int quantity){
    this->quantity = quantity;
}



