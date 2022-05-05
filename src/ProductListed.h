#ifndef __CATALOGUEPROD__
#define __CATALOGUEPROD__

#include <Arduino.h>
#include "Product.h"

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
    int getQuantity();
    void setQuantity(int quantity);

};

#endif
