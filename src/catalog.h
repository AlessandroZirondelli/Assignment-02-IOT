#ifndef __CATALOGUE__
#define __CATALOGUE__

#include <Arduino.h>
#include "config.h"
#include "ProductListed.h"
//#include <string>

class Catalog {

private:
    ProductListed* productList[MAX_PRODUCT]; // Array mantains all products 
    int numProd; // Number of products in the machine
public:
    Catalog();
    int getQtnProduct(String name);  // Return the quantity of product
    void setQtnProduct(String name, int qtn); // Set quantity of product
    bool addProduct(ProductListed* product); //add product to catalog
    int getTotalDisponibility(); // Return the total quantity of product, do the sum of all product's quantity
    ProductListed ** getProducts();
    int getNumProducts();
};

#endif
