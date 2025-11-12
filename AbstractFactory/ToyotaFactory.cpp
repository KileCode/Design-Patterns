// ToyotaFactory.cpp - Implementation of Toyota factory
#include "ToyotaFactory.h"
#include "ToyotaProducts.h"

Sedan* ToyotaFactory::createSedan() {
    return new ToyotaSedan();
}

SUV* ToyotaFactory::createSUV() {
    return new ToyotaSUV();
}

Truck* ToyotaFactory::createTruck() {
    return new ToyotaTruck();
}