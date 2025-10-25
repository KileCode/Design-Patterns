#ifndef RIBBONDECORATOR_H
#define RIBBONDECORATOR_H

#include "Decorator.h"

class RibbonDecorator : public Decorator {
private:
    static const int RIBBON_COST = 3;

public:
    RibbonDecorator(Plant* plant);
    double getPrice() override;
    string getDescription() override;
};

#endif