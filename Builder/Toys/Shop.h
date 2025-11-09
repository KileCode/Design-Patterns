#ifndef SHOP_H
#define SHOP_H

#include "SoftToyMachine.h"
#include <string>

class Shop {
private:
    SoftToyMachine* machine;
    std::string bearName;

public:
    Shop(SoftToyMachine* m, std::string name);
    void construct();
};

#endif