#ifndef __MACHINE__
#define __MACHINE__
#include "Product.h"
#include "ProductListed.h"
#include "catalog.h"


class Machine {
    
public:
    Machine();
    void init();
    bool addCatalog(Catalog* catalog);
    Catalog* getCatalog();
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
    Catalog* catalog;


};

#endif
