#ifndef __CATALOGUEPROD__
#define __CATALOGUEPROD__

#include <Arduino.h>
#include "Product.h"

//Identifica un prodotto che può essere aggiunto al catalogo, viene memorizzato un oggetto di tipo "Prodotto" e la sua quantità
class ProductListed {

private:
    int quantity;
    String name;
    Product* product;
public:
    ProductListed();
    ProductListed(Product* product);
    ProductListed(Product* product, int quantity);
    Product* getProduct();
    void setProduct(Product* product);
    String getName(); 
    void setName(String name);
    int getQuantity(); //Ritorno la quantità del prodotto listato
    void setQuantity(int quantity); // Setto la quantità del prodotto listato 

};

#endif
