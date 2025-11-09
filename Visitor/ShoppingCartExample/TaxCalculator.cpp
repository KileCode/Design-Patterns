#include "TaxCalculator.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Groceries.h"
#include <iostream>
#include <iomanip>

TaxCalculator::TaxCalculator() : totalTax(0.0) {}

void TaxCalculator::visit(Electronics* product) {
    std::cout << "Calculating tax for Electronics: " << product->getName() << std::endl;
    double tax = product->getBasePrice() * 0.15; // 15% tax on electronics
    totalTax = tax;
    std::cout << "  Base Price: $" << std::fixed << std::setprecision(2) << product->getBasePrice() << std::endl;
    std::cout << "  Tax Rate: 15%" << std::endl;
    std::cout << "  Tax Amount: $" << tax << std::endl;
}

void TaxCalculator::visit(Clothing* product) {
    std::cout << "Calculating tax for Clothing: " << product->getName() << std::endl;
    double tax = product->getBasePrice() * 0.08; // 8% tax on clothing
    totalTax = tax;
    std::cout << "  Base Price: $" << std::fixed << std::setprecision(2) << product->getBasePrice() << std::endl;
    std::cout << "  Tax Rate: 8%" << std::endl;
    std::cout << "  Tax Amount: $" << tax << std::endl;
}

void TaxCalculator::visit(Groceries* product) {
    std::cout << "Calculating tax for Groceries: " << product->getName() << std::endl;
    double taxRate = product->getIsPerishable() ? 0.0 : 0.05; // No tax on perishables, 5% on non-perishables
    double tax = product->getBasePrice() * taxRate;
    totalTax = tax;
    std::cout << "  Base Price: $" << std::fixed << std::setprecision(2) << product->getBasePrice() << std::endl;
    std::cout << "  Perishable: " << (product->getIsPerishable() ? "Yes" : "No") << std::endl;
    std::cout << "  Tax Rate: " << (taxRate * 100) << "%" << std::endl;
    std::cout << "  Tax Amount: $" << tax << std::endl;
}

double TaxCalculator::getTotalTax() const {
    return totalTax;
}