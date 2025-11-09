#include "Mother.h"

Mother::Mother() : machine(0) {}

void Mother::setMachine(SoftToyMachine* m) {
    machine = m;
}

void Mother::construct() {
    // Mother's construction process - omits some methods and uses defaults
    machine->selectBody();
    machine->stuff();
    machine->setName("Homemade toy");
    // Note: Mother omits insertHeart() and addVoice()
}