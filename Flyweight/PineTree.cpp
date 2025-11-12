#include "PineTree.h"
#include <iostream>

PineTree::PineTree() : TreeType("Pine", "Light Green", "pine_bark.png") {}

PineTree::PineTree(std::string c, std::string t) 
    : TreeType("Pine", c, t) {}

PineTree::~PineTree() {}

void PineTree::render(int x, int y, int scale) const {
    std::cout << "Rendering Pine tree at (" << x << "," << y 
              << ") scale:" << scale << "% - Color:" << color 
              << " Texture:" << texture << std::endl;
}

std::string PineTree::getType() const {
    return "Pine";
}