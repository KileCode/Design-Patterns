// BMWFactory.h - Concrete Factory for BMW products
#ifndef BMW_FACTORY_H
#define BMW_FACTORY_H

#include "VehicleFactory.h"

// Concrete Factory - creates BMW product family
class BMWFactory : public VehicleFactory {
public:
    Sedan* createSedan() override;
    SUV* createSUV() override;
    Truck* createTruck() override;
};

#endif // BMW_FACTORY_H