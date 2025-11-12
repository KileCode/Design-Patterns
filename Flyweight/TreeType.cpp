#include "TreeType.h"

TreeType::TreeType() : name(""), color(""), texture("") {}

TreeType::TreeType(std::string n, std::string c, std::string t) 
    : name(n), color(c), texture(t) {}

TreeType::~TreeType() {}

std::string TreeType::getName() const {
    return name;
}

std::string TreeType::getColor() const {
    return color;
}

std::string TreeType::getTexture() const {
    return texture;
}