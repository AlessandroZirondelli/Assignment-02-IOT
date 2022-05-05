#include <Arduino.h>
//#include <string>
#include "Product.h"

Product::Product(){
    this->price = 0;
    this->name = "";
}
Product::Product(String name){
    this->price = 0;    
    this->name = name;
}
Product::Product(String name, int price){
    this->price = price;    
    this->name = name;
}
String Product::getName(){
    return this->name;
}
void Product::setName(String name){
    this->name = name;
}
int Product::getPrice(){
    return this->price;
}
void Product::setPrice(int price){
    this->price = price;
}



