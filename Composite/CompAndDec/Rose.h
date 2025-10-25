#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"

class Rose : public Plant {
private:
    string color;

public:
    Rose(string n, string c);
    ~Rose();
    string getDescription() override;
};

#endif