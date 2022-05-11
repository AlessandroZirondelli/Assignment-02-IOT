#ifndef __PRODUCT__
#define __PRODUCT__

#include <Arduino.h>

//Identify a product with name and price
class Product {

private:
    int price;
    String name;
    
public:
    Product();
    Product(String name);
    Product(String name, int price);
    String getName(); 
    void setName(String name);
    int getPrice();
    void setPrice(int price);

};

#endif
