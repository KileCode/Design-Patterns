#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H

#include "Decorator.h"

class DecorativePotDecorator : public Decorator {
private:
    static const int DECORATIVE_POT_COST = 10;

public:
    DecorativePotDecorator(Plant* plant);
    double getPrice() override;
    string getDescription() override;
};

#endif