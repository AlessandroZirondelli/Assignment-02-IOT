#ifndef __MACHINE__
#define __MACHINE__
#include "Product.h"
#include "ProductListed.h"
#define MAX_PRODUCT 40


class Machine {
    
public:
    Machine();
    void init();
    int getQtnProduct(String name);
    void setQtnProduct(String name,int quantity);
    bool addProduct(ProductListed* product);
    bool isStart();
    bool isSelect();
    bool isMaking();
    bool isWait();
    bool isSelfTest();
    bool isAssistance();
    void setStart();
    void setSelect();
    void setMaking();
    void setWait();
    void setSelfTest();
    void setAssistance();

private:
    enum { START, SELECT, MAKING, WAIT,SELFTEST, ASSISTANCE } state;
    ProductListed* productList[MAX_PRODUCT]; 
    int numProd; 

};

#endif
