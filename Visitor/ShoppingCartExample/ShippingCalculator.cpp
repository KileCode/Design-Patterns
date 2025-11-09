#include "ShippingCalculator.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Groceries.h"
#include <iostream>
#include <iomanip>

ShippingCalculator::ShippingCalculator() : shippingCost(0.0) {}

void ShippingCalculator::visit(Electronics* product) {
    std::cout << "Calculating shipping for Electronics: " << product->getName() << std::endl;
    shippingCost = 15.00; // Flat rate for electronics (fragile handling)
    std::cout << "  Shipping method: Fragile handling required" << std::endl;
    std::cout << "  Shipping Cost: $" << std::fixed << std::setprecision(2) << shippingCost << std::endl;
}

void ShippingCalculator::visit(Clothing* product) {
    std::cout << "Calculating shipping for Clothing: " << product->getName() << std::endl;
    shippingCost = 5.00; // Standard flat rate for clothing
    std::cout << "  Shipping method: Standard packaging" << std::endl;
    std::cout << "  Shipping Cost: $" << std::fixed << std::setprecision(2) << shippingCost << std::endl;
}

void ShippingCalculator::visit(Groceries* product) {
    std::cout << "Calculating shipping for Groceries: " << product->getName() << std::endl;
    if (product->getIsPerishable()) {
        shippingCost = 12.00 + (product->getWeight() * 2.0); // Refrigerated shipping
        std::cout << "  Shipping method: Refrigerated transport" << std::endl;
    } else {
        shippingCost = 3.00 + (product->getWeight() * 0.5); // Weight-based
        std::cout << "  Shipping method: Standard transport" << std::endl;
    }
    std::cout << "  Weight: " << product->getWeight() << " kg" << std::endl;
    std::cout << "  Shipping Cost: $" << std::fixed << std::setprecision(2) << shippingCost << std::endl;
}

double ShippingCalculator::getShippingCost() const {
    return shippingCost;
}