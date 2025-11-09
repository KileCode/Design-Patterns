#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Product.h"
#include <string>

// ConcreteElement
class Electronics : public Product {
private:
    std::string name;
    double basePrice;
    int warrantyYears;
public:
    Electronics(const std::string& n, double price, int warranty);
    void accept(PricingCalculator& calculator) override;
    std::string getName() const override;
    double getBasePrice() const override;
    std::string getCategory() const override;
    int getWarrantyYears() const;
};

#endif