#include "PlainGiraffe.h"
#include <iostream>
using namespace std;

PlainGiraffe::PlainGiraffe() : name(""), colour(""), weight(0.0), height(0.0) {}

void PlainGiraffe::setName(string n) {
    name = n;
}

void PlainGiraffe::selectSkin(string c) {
    colour = c;
}

void PlainGiraffe::setWeight(double w) {
    weight = w;
}

void PlainGiraffe::setHeight(double h) {
    height = h;
}

void PlainGiraffe::describe() {
    cout << "Plain Giraffe:" << endl;
    cout << "  Name: " << name << endl;
    cout << "  Colour: " << colour << endl;
    cout << "  Weight: " << weight << " kg" << endl;
    cout << "  Height: " << height << " m" << endl;
}