// Truck.h - Abstract Product Interface for Truck family
#ifndef TRUCK_H
#define TRUCK_H

#include <string>

// Abstract Product - defines interface for Truck objects
class Truck {
public:
    virtual ~Truck() {}
    virtual std::string getDescription() const = 0;
    virtual void drive() const = 0;
};

#endif // TRUCK_H