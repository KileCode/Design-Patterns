// ToyotaProducts.h - Concrete Products for Toyota family
#ifndef TOYOTA_PRODUCTS_H
#define TOYOTA_PRODUCTS_H

#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"

// Concrete Product - Toyota Sedan
class ToyotaSedan : public Sedan {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - Toyota SUV
class ToyotaSUV : public SUV {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - Toyota Truck
class ToyotaTruck : public Truck {
public:
    std::string getDescription() const override;
    void drive() const override;
};

#endif // TOYOTA_PRODUCTS_H