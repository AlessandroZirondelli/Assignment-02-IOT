#ifndef __CATALOGUE__
#define __CATALOGUE__

#include <Arduino.h>
#include "config.h"
#include "ProductListed.h"
//#include <string>

class Catalog {

private:
    ProductListed* productList[MAX_PRODUCT];
    int numProd;
public:
    Catalog();
    int getQtnProduct(String name); 
    void setQtnProduct(String name, int qtn);
    bool addProduct(ProductListed* product);
    int getTotalDisponibility();

};

#endif
