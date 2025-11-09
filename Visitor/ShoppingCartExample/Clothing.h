#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"
#include <string>

// ConcreteElement
class Clothing : public Product {
private:
    std::string name;
    double basePrice;
    std::string size;
    bool isPremiumBrand;
public:
    Clothing(const std::string& n, double price, const std::string& sz, bool premium);
    void accept(PricingCalculator& calculator) override;
    std::string getName() const override;
    double getBasePrice() const override;
    std::string getCategory() const override;
    std::string getSize() const;
    bool getIsPremiumBrand() const;
};

#endif