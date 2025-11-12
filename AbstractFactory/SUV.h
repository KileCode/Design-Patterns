// SUV.h - Abstract Product Interface for SUV family
#ifndef SUV_H
#define SUV_H

#include <string>

// Abstract Product - defines interface for SUV objects
class SUV {
public:
    virtual ~SUV() {}
    virtual std::string getDescription() const = 0;
    virtual void drive() const = 0;
};

#endif // SUV_H