
#include "Arduino.h"
#include "catalog.h"
#include "ProductListed.h"

Catalog::Catalog(){
    this->numProd = 0;
}
int Catalog::getQtnProduct(String name){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){  // Ricerco il prodotto per nome 
                return productList[i] -> getQuantity(); // Ritorno la qtn se il prodotto è presente
            }
        }
        return 0; // Se il prodotto non è presente ritorno 0
}

void Catalog::setQtnProduct(String name, int quantity){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){ // Ricerco il prodotto per nome 
                productList[i] -> setQuantity(quantity); // Setto la qtn del prodotto 
            }
        }   
}
bool Catalog::addProduct(ProductListed* product){ // 
    if (numProd < MAX_PRODUCT){ // Controllo se c'è posto nell'array dei prodotti
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
        tot = tot + productList[i] -> getQuantity();   // Sommo tutte le quantità dei singoli prodotti
    }
    return tot;
}
