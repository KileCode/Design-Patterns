#include "ShoppingCart.h"
#include <algorithm>

void ShoppingCart::addProduct(Product* product) {
    products.push_back(product);
}

void ShoppingCart::removeProduct(Product* product) {
    products.erase(std::remove(products.begin(), products.end(), product), products.end());
}

void ShoppingCart::acceptCalculator(PricingCalculator& calculator) {
    for (Product* product : products) {
        product->accept(calculator);
    }
}

const std::vector<Product*>& ShoppingCart::getProducts() const {
    return products;
}

int ShoppingCart::getItemCount() const {
    return products.size();
}