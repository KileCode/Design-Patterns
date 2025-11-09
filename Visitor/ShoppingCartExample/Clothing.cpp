#include "Clothing.h"
#include "PricingCalculator.h"

Clothing::Clothing(const std::string& n, double price, const std::string& sz, bool premium)
    : name(n), basePrice(price), size(sz), isPremiumBrand(premium) {}

void Clothing::accept(PricingCalculator& calculator) {
    calculator.visit(this);
}

std::string Clothing::getName() const {
    return name;
}

double Clothing::getBasePrice() const {
    return basePrice;
}

std::string Clothing::getCategory() const {
    return "Clothing";
}

std::string Clothing::getSize() const {
    return size;
}

bool Clothing::getIsPremiumBrand() const {
    return isPremiumBrand;
}