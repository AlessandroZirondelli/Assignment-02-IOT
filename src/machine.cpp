#include "machine.h"
#include <Arduino.h>

Machine::Machine(){
    state = START;
    numProd = 0; 
}
void Machine::init(){
    /*metterer nel main
    numProd = 3;
    productList[0] = new Product("Chocolate",40);
    productList[1] = new Product("Coffee",50);
    productList[2] = new Product("Tea",60);
*/
}

    int Machine::getQtnProduct(String name){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){  
                return productList[i] -> getQuantity();
            }
        }
        return 0;
    }
    void Machine::setQtnProduct(String name, int quantity){
        for(int i = 0; i<numProd;i++){
            if(productList[i] -> getName().equals(name)){
                productList[i] -> setQuantity(quantity);
            }
        }   
    }
    bool Machine::addProduct(Product* product){

        if (numProd < MAX_PRODUCT){
            productList[numProd] = product;
            numProd++;
            return true;
        } else {
            return false; 
        }
    }
    
    bool Machine::isStart(){
        return state == START;
    }
    bool Machine::isSelect(){
        return state == SELECT;
    }
    bool Machine::isMaking(){
        return state == MAKING;
    }
    bool Machine::isWait(){
        return state == WAIT;
    }
    bool Machine::isSelfTest(){
        return state == SELFTEST;
    }
    bool Machine::isAssistance(){
        return state == ASSISTANCE;
    }

    void Machine::setStart(){
        state = START;
    }
    void Machine::setSelect(){
        state = SELECT;
    }
    void Machine::setMaking(){
        state = MAKING;
    }
    void Machine::setWait(){
        state = WAIT;
    }
    void Machine::setSelfTest(){
        state = SELFTEST;
    }
    void Machine::setAssistance(){
        state = ASSISTANCE;
    }


