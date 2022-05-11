#include <Arduino.h>
#include "Product.h"
#include "ProductListed.h"
ProductListed::ProductListed(){
    this->quantity = 0;
    this->product = new Product();
}
ProductListed::ProductListed(Product* product){
    this->quantity = 0;
    this->product = product;
}
ProductListed::ProductListed(Product* product, int quantity){
    this->quantity = quantity;    
    this->product = product;
}
String ProductListed::getName(){
    return this->product->getName();
}
void ProductListed::setName(String name){
    this->product ->setName(name);
}
int ProductListed::getQuantity(){
    return this->quantity;
}
void ProductListed::setQuantity(int quantity){
    this->quantity = quantity;
}
Product* ProductListed::getProduct(){ 
     return this->product;
 }
void ProductListed::setProduct(Product* product){  
    this->product = product;
}

