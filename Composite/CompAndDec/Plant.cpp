#include "Plant.h"

Plant::Plant(string n, double price) : name(n), basePrice(price) {}

Plant::~Plant() {}

double Plant::getPrice() {
    return basePrice;
}

string Plant::getDescription() {
    return name;
}

string Plant::getName() {
    return name;
}