#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h"
#include "PricingCalculator.h"
#include <vector>

// ObjectStructure
class ShoppingCart {
private:
    std::vector<Product*> products;
public:
    void addProduct(Product* product);
    void removeProduct(Product* product);
    void acceptCalculator(PricingCalculator& calculator);
    const std::vector<Product*>& getProducts() const;
    int getItemCount() const;
};

#endif