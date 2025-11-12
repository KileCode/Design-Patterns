// ToyotaFactory.h - Concrete Factory for Toyota products
#ifndef TOYOTA_FACTORY_H
#define TOYOTA_FACTORY_H

#include "VehicleFactory.h"

// Concrete Factory - creates Toyota product family
class ToyotaFactory : public VehicleFactory {
public:
    Sedan* createSedan() override;
    SUV* createSUV() override;
    Truck* createTruck() override;
};

#endif // TOYOTA_FACTORY_H