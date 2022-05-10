
#include "Arduino.h"
#include "catalog.h"
#include "ProductListed.h"

Catalog::Catalog(){
    this->numProd = 0;
}
int Catalog::getQtnProduct(String name){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){  // I search product by name
                return productList[i] -> getQuantity(); // Get back the quantity if the product is present
            }
        }
        return 0; // If the product isnt't present return 0
}

void Catalog::setQtnProduct(String name, int quantity){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){ // Search prodcut by name 
                productList[i] -> setQuantity(quantity); //Set quantity of the product
            }
        }   
}
bool Catalog::addProduct(ProductListed* product){ // 
    if (numProd < MAX_PRODUCT){ //Check if the max is reached 
        productList[numProd] = product;
        numProd++;
        return true;
    } else {
        return false; 
    }
}
int Catalog::getTotalDisponibility(){
    int tot = 0;
    for(int i = 0; i<numProd;i++){
        tot = tot + productList[i] -> getQuantity();   //Do the sum beetwen all product's quantity
    }
    return tot;
}
ProductListed ** Catalog::getProducts(){
    return productList;
}
int Catalog::getNumProducts(){
    return this->numProd;
}