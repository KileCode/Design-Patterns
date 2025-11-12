// TeslaProducts.cpp - Implementations for Tesla products
#include "TeslaProducts.h"
#include <iostream>

// TeslaSedan implementations
std::string TeslaSedan::getDescription() const {
    return "Tesla Model S - Electric luxury sedan";
}

void TeslaSedan::drive() const {
    std::cout << "Driving Tesla Sedan with instant acceleration and autopilot" << std::endl;
}

// TeslaSUV implementations
std::string TeslaSUV::getDescription() const {
    return "Tesla Model X - Electric SUV with falcon-wing doors";
}

void TeslaSUV::drive() const {
    std::cout << "Driving Tesla SUV with zero emissions" << std::endl;
}

// TeslaTruck implementations
std::string TeslaTruck::getDescription() const {
    return "Tesla Cybertruck - Futuristic electric truck";
}

void TeslaTruck::drive() const {
    std::cout << "Driving Tesla Truck with exoskeleton design" << std::endl;
}