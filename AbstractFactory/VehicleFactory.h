// VehicleFactory.h - Abstract Factory Interface
#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"

// Abstract Factory - declares factory methods for creating product families
class VehicleFactory {
public:
    virtual ~VehicleFactory() {}
    
    // Factory methods - each returns an abstract product type
    virtual Sedan* createSedan() = 0;
    virtual SUV* createSUV() = 0;
    virtual Truck* createTruck() = 0;
};

#endif // VEHICLE_FACTORY_H