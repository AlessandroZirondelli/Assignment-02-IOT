
#include "Arduino.h"
#include "catalog.h"
#include "ProductListed.h"

Catalog::Catalog(){
    this->numProd = 0;
}
int Catalog::getQtnProduct(String name){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){  
                return productList[i] -> getQuantity();
            }
        }
        return 0;
}
ProductListed* Catalog::getProduct(){
    return *productList;
}
void Catalog::setQtnProduct(String name, int quantity){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){
                productList[i] -> setQuantity(quantity);
            }
        }   
}
bool Catalog::addProduct(ProductListed* product){
    if (numProd < MAX_PRODUCT){
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
        tot = tot + productList[i] -> getQuantity();   
    }
    return tot;
}
