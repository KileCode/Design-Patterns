#ifndef TAXCALCULATOR_H
#define TAXCALCULATOR_H

#include "PricingCalculator.h"

// ConcreteVisitor
class TaxCalculator : public PricingCalculator {
private:
    double totalTax;
public:
    TaxCalculator();
    void visit(Electronics* product) override;
    void visit(Clothing* product) override;
    void visit(Groceries* product) override;
    double getTotalTax() const;
};

#endif