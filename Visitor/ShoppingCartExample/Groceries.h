#ifndef GROCERIES_H
#define GROCERIES_H

#include "Product.h"
#include <string>

// ConcreteElement
class Groceries : public Product {
private:
    std::string name;
    double basePrice;
    bool isPerishable;
    double weight;
public:
    Groceries(const std::string& n, double price, bool perishable, double wt);
    void accept(PricingCalculator& calculator) override;
    std::string getName() const override;
    double getBasePrice() const override;
    std::string getCategory() const override;
    bool getIsPerishable() const;
    double getWeight() const;
};

#endif