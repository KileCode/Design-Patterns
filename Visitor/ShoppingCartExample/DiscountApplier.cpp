#include "DiscountApplier.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Groceries.h"
#include <iostream>
#include <iomanip>

DiscountApplier::DiscountApplier() : totalDiscount(0.0) {}

void DiscountApplier::visit(Electronics* product) {
    std::cout << "Applying discount to Electronics: " << product->getName() << std::endl;
    double discount = 0.0;
    if (product->getWarrantyYears() >= 2) {
        discount = product->getBasePrice() * 0.10; // 10% off if warranty >= 2 years
        std::cout << "  Extended warranty discount: 10%" << std::endl;
    } else {
        discount = product->getBasePrice() * 0.05; // 5% standard discount
        std::cout << "  Standard discount: 5%" << std::endl;
    }
    totalDiscount = discount;
    std::cout << "  Discount Amount: $" << std::fixed << std::setprecision(2) << discount << std::endl;
}

void DiscountApplier::visit(Clothing* product) {
    std::cout << "Applying discount to Clothing: " << product->getName() << std::endl;
    double discount = 0.0;
    if (product->getIsPremiumBrand()) {
        discount = product->getBasePrice() * 0.15; // 15% off premium brands
        std::cout << "  Premium brand discount: 15%" << std::endl;
    } else {
        discount = product->getBasePrice() * 0.20; // 20% off regular brands
        std::cout << "  Regular brand discount: 20%" << std::endl;
    }
    totalDiscount = discount;
    std::cout << "  Discount Amount: $" << std::fixed << std::setprecision(2) << discount << std::endl;
}

void DiscountApplier::visit(Groceries* product) {
    std::cout << "Applying discount to Groceries: " << product->getName() << std::endl;
    double discount = 0.0;
    if (product->getIsPerishable()) {
        discount = product->getBasePrice() * 0.25; // 25% off perishables (clearance)
        std::cout << "  Perishable clearance discount: 25%" << std::endl;
    } else {
        discount = product->getBasePrice() * 0.10; // 10% off non-perishables
        std::cout << "  Standard grocery discount: 10%" << std::endl;
    }
    totalDiscount = discount;
    std::cout << "  Discount Amount: $" << std::fixed << std::setprecision(2) << discount << std::endl;
}

double DiscountApplier::getTotalDiscount() const {
    return totalDiscount;
}