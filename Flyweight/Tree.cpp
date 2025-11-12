#include "Tree.h"

Tree::Tree(int posX, int posY, int s, TreeType* t) 
    : x(posX), y(posY), scale(s), type(t) {}

Tree::~Tree() {}

void Tree::render() const {
    type->render(x, y, scale);
}

int Tree::getX() const {
    return x;
}

int Tree::getY() const {
    return y;
}

int Tree::getScale() const {
    return scale;
}

std::string Tree::getTypeName() const {
    return type->getType();
}