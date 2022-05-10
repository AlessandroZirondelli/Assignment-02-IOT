#ifndef __CATALOGUE__
#define __CATALOGUE__

#include <Arduino.h>
#include "config.h"
#include "ProductListed.h"
//#include <string>

class Catalog {

private:
    ProductListed* productList[MAX_PRODUCT]; // Array che memorizzano i prodotti presenti nella macchina
    int numProd; // Numero di prodotti memorizzati nel catalogo
public:
    Catalog();
    int getQtnProduct(String name);  // Ritorna la quanittà di un prodotto
    void setQtnProduct(String name, int qtn); // Setto la quantità di un prodotto
    bool addProduct(ProductListed* product); // Aggiungo un prodotto al catalogo
    int getTotalDisponibility(); // Ritorna la quantità totale tra tutti i prodotto, fa la somma di tutte le quantità dei singoli prodotti


};

#endif
