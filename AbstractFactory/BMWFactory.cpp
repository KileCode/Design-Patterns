// BMWFactory.cpp - Implementation of BMW factory
#include "BMWFactory.h"
#include "BMWProducts.h"

Sedan* BMWFactory::createSedan() {
    return new BMWSedan();
}

SUV* BMWFactory::createSUV() {
    return new BMWSUV();
}

Truck* BMWFactory::createTruck() {
    return new BMWTruck();
}