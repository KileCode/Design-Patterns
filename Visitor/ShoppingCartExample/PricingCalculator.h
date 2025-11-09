#ifndef PRICINGCALCULATOR_H
#define PRICINGCALCULATOR_H

// Forward declarations
class Electronics;
class Clothing;
class Groceries;

// Visitor
class PricingCalculator {
public:
    virtual ~PricingCalculator() {}
    virtual void visit(Electronics* product) = 0;
    virtual void visit(Clothing* product) = 0;
    virtual void visit(Groceries* product) = 0;
};

#endif