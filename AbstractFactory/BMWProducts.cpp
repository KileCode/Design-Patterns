// BMWProducts.cpp - Implementations for BMW products
#include "BMWProducts.h"
#include <iostream>

// BMWSedan implementations
std::string BMWSedan::getDescription() const {
    return "BMW 3 Series - Ultimate driving machine";
}

void BMWSedan::drive() const {
    std::cout << "Driving BMW Sedan with precision handling" << std::endl;
}

// BMWSUV implementations
std::string BMWSUV::getDescription() const {
    return "BMW X5 - Luxury performance SUV";
}

void BMWSUV::drive() const {
    std::cout << "Driving BMW SUV with dynamic performance" << std::endl;
}

// BMWTruck implementations
std::string BMWTruck::getDescription() const {
    return "BMW Pickup Concept - Innovative truck design";
}

void BMWTruck::drive() const {
    std::cout << "Driving BMW Truck with German engineering" << std::endl;
}