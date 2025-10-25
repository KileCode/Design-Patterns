#include "Decorator.h"

Decorator::Decorator(Plant* plant) : Plant("", 0), wrappedPlant(plant) {}

Decorator::~Decorator() {
    // Note: In a real system, you'd need to manage memory carefully
    // For this proof of concept, we'll keep it simple
}