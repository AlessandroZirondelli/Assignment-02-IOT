#ifndef __PRODUCT__
#define __PRODUCT__

#include <Arduino.h>
//#include <string>

class Product {

public:
    Product();
    Product(String name, int quantity);
    String getName(); 
    void setName();
    int getQuantity();
    void setQuantity(int quantity);

  


private:
    int quatity;
    String name;

};

#endif