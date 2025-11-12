// TeslaFactory.cpp - Implementation of Tesla factory
#include "TeslaFactory.h"
#include "TeslaProducts.h"

Sedan* TeslaFactory::createSedan() {
    return new TeslaSedan();
}

SUV* TeslaFactory::createSUV() {
    return new TeslaSUV();
}

Truck* TeslaFactory::createTruck() {
    return new TeslaTruck();
}