#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// Forward declaration
class PricingCalculator;

// Element
class Product {
public:
    virtual ~Product() {}
    virtual void accept(PricingCalculator& calculator) = 0;
    virtual std::string getName() const = 0;
    virtual double getBasePrice() const = 0;
    virtual std::string getCategory() const = 0;
};

#endif