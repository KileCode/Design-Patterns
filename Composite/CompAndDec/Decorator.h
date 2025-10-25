#ifndef DECORATOR_H
#define DECORATOR_H

#include "Plant.h"

class Decorator : public Plant {
protected:
    Plant* wrappedPlant;

public:
    Decorator(Plant* plant);
    virtual ~Decorator();
    virtual double getPrice() = 0;
    virtual string getDescription() = 0;
};

#endif