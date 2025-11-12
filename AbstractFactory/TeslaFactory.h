// TeslaFactory.h - Concrete Factory for Tesla products
#ifndef TESLA_FACTORY_H
#define TESLA_FACTORY_H

#include "VehicleFactory.h"

// Concrete Factory - creates Tesla product family
class TeslaFactory : public VehicleFactory {
public:
    Sedan* createSedan() override;
    SUV* createSUV() override;
    Truck* createTruck() override;
};

#endif // TESLA_FACTORY_H