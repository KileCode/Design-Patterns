// Sedan.h - Abstract Product Interface for Sedan family
#ifndef SEDAN_H
#define SEDAN_H

#include <string>

// Abstract Product - defines interface for Sedan objects
class Sedan {
public:
    virtual ~Sedan() {}
    virtual std::string getDescription() const = 0;
    virtual void drive() const = 0;
};

#endif // SEDAN_H