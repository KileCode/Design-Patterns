#include "Shop.h"

Shop::Shop(SoftToyMachine* m, std::string name) : machine(m), bearName(name) {}

void Shop::construct() {
    // Shop's construction process - calls all methods with parameters
    machine->selectBody();
    machine->stuff();
    machine->insertHeart();
    machine->addVoice();
    machine->setName(bearName);
}