#include "RibbonDecorator.h"

RibbonDecorator::RibbonDecorator(Plant* plant) : Decorator(plant) {}

double RibbonDecorator::getPrice() {
    return wrappedPlant->getPrice() + RIBBON_COST;
}

string RibbonDecorator::getDescription() {
    return wrappedPlant->getDescription() + " with ribbon";
}