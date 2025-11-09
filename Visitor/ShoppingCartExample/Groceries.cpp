#include "Groceries.h"
#include "PricingCalculator.h"

Groceries::Groceries(const std::string& n, double price, bool perishable, double wt)
    : name(n), basePrice(price), isPerishable(perishable), weight(wt) {}

void Groceries::accept(PricingCalculator& calculator) {
    calculator.visit(this);
}

std::string Groceries::getName() const {
    return name;
}

double Groceries::getBasePrice() const {
    return basePrice;
}

std::string Groceries::getCategory() const {
    return "Groceries";
}

bool Groceries::getIsPerishable() const {
    return isPerishable;
}

double Groceries::getWeight() const {
    return weight;
}