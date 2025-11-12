// BMWProducts.h - Concrete Products for BMW family
#ifndef BMW_PRODUCTS_H
#define BMW_PRODUCTS_H

#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"

// Concrete Product - BMW Sedan
class BMWSedan : public Sedan {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - BMW SUV
class BMWSUV : public SUV {
public:
    std::string getDescription() const override;
    void drive() const override;
};

// Concrete Product - BMW Truck
class BMWTruck : public Truck {
public:
    std::string getDescription() const override;
    void drive() const override;
};

#endif // BMW_PRODUCTS_H