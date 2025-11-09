#include "PlainGiraffeMaker.h"

PlainGiraffeMaker::PlainGiraffeMaker() : giraffe(0) {}

PlainGiraffeMaker::~PlainGiraffeMaker() {
    if (giraffe != 0) {
        delete giraffe;
    }
}

void PlainGiraffeMaker::selectBody() {
    // Delete any previous instance to avoid memory leak
    if (giraffe != 0) {
        delete giraffe;
    }
    giraffe = new PlainGiraffe();
    giraffe->selectSkin("yellow with brown spots");
}

void PlainGiraffeMaker::stuff() {
    giraffe->setWeight(50.0);
    giraffe->setHeight(1.5);
}

void PlainGiraffeMaker::setName(std::string name) {
    giraffe->setName(name);
}

PlainGiraffe PlainGiraffeMaker::getGiraffe() {
    // Return a copy, not the original
    return *giraffe;
}