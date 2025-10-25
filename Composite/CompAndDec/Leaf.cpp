#include "Leaf.h"
#include <sstream>

Leaf::Leaf(Plant* p, int qty) : plant(p), quantity(qty) {}

Leaf::~Leaf() {
    // Plant will be deleted elsewhere or managed separately
}

double Leaf::getPrice() {
    return plant->getPrice() * quantity;
}

string Leaf::getDescription() {
    stringstream ss;
    ss << quantity << "x " << plant->getDescription();
    return ss.str();
}

Plant* Leaf::getPlant() const {
    return plant;
}

int Leaf::getQuantity() const {
    return quantity;
}