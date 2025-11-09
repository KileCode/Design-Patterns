#ifndef DISCOUNTAPPLIER_H
#define DISCOUNTAPPLIER_H

#include "PricingCalculator.h"

// ConcreteVisitor
class DiscountApplier : public PricingCalculator {
private:
    double totalDiscount;
public:
    DiscountApplier();
    void visit(Electronics* product) override;
    void visit(Clothing* product) override;
    void visit(Groceries* product) override;
    double getTotalDiscount() const;
};

#endif