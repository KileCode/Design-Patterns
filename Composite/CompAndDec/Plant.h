#ifndef PLANT_H
#define PLANT_H

#include <string>
using namespace std;

class Plant {
protected:
    string name;
    double basePrice;

public:
    Plant(string n, double price);
    virtual ~Plant();
    virtual double getPrice();
    virtual string getDescription();
    string getName();
};

#endif