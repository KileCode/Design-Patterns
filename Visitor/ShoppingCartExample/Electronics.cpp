#include "Electronics.h"
#include "PricingCalculator.h"

Electronics::Electronics(const std::string& n, double price, int warranty)
    : name(n), basePrice(price), warrantyYears(warranty) {}

void Electronics::accept(PricingCalculator& calculator) {
    calculator.visit(this);
}

std::string Electronics::getName() const {
    return name;
}

double Electronics::getBasePrice() const {
    return basePrice;
}

std::string Electronics::getCategory() const {
    return "Electronics";
}

int Electronics::getWarrantyYears() const {
    return warrantyYears;
}