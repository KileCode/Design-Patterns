#include "DecorativePotDecorator.h"

DecorativePotDecorator::DecorativePotDecorator(Plant* plant) : Decorator(plant) {}

double DecorativePotDecorator::getPrice() {
    return wrappedPlant->getPrice() + DECORATIVE_POT_COST;
}

string DecorativePotDecorator::getDescription() {
    return wrappedPlant->getDescription() + " in decorative pot";
}