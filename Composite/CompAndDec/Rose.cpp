#include "Rose.h"

Rose::Rose(string n, string c) : Plant(n, 5.0), color(c) {}

Rose::~Rose() {}

string Rose::getDescription() {
    return color + " " + name;
}