// TeslaProducts.h - Concrete Products for Tesla family
#ifndef TESLA_PRODUCTS_H
#define TESLA_PRODUCTS_H

#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"

// Concrete Product - Tesla Sedan
class TeslaSedan : public Sedan {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - Tesla SUV
class TeslaSUV : public SUV {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - Tesla Truck
class TeslaTruck : public Truck {
public:
    std::string getDescription() const override;
    void drive() const override;
};

#endif // TESLA_PRODUCTS_H