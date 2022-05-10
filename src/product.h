#ifndef __PRODUCT__
#define __PRODUCT__

#include <Arduino.h>
//#include <string>

//Identifica un prodotto memoriazzando nome e prezzo
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
