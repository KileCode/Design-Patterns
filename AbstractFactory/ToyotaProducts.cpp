// ToyotaProducts.cpp - Implementations for Toyota products
#include "ToyotaProducts.h"
#include <iostream>

// ToyotaSedan implementations
std::string ToyotaSedan::getDescription() const {
    return "Toyota Camry - Reliable and fuel-efficient sedan";
}

void ToyotaSedan::drive() const {
    std::cout << "Driving Toyota Sedan with smooth hybrid engine" << std::endl;
}

// ToyotaSUV implementations
std::string ToyotaSUV::getDescription() const {
    return "Toyota RAV4 - Versatile family SUV";
}

void ToyotaSUV::drive() const {
    std::cout << "Driving Toyota SUV with all-wheel drive" << std::endl;
}

// ToyotaTruck implementations
std::string ToyotaTruck::getDescription() const {
    return "Toyota Tacoma - Rugged mid-size truck";
}

void ToyotaTruck::drive() const {
    std::cout << "Driving Toyota Truck with off-road capability" << std::endl;
}