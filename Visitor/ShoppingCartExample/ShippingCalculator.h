#ifndef SHIPPINGCALCULATOR_H
#define SHIPPINGCALCULATOR_H

#include "PricingCalculator.h"

// ConcreteVisitor
class ShippingCalculator : public PricingCalculator {
private:
    double shippingCost;
public:
    ShippingCalculator();
    void visit(Electronics* product) override;
    void visit(Clothing* product) override;
    void visit(Groceries* product) override;
    double getShippingCost() const;
};

#endif