#include "OakTree.h"
#include <iostream>

OakTree::OakTree() : TreeType("Oak", "Dark Green", "oak_bark.png") {}

OakTree::OakTree(std::string c, std::string t) 
    : TreeType("Oak", c, t) {}

OakTree::~OakTree() {}

void OakTree::render(int x, int y, int scale) const {
    std::cout << "Rendering Oak tree at (" << x << "," << y 
              << ") scale:" << scale << "% - Color:" << color 
              << " Texture:" << texture << std::endl;
}

std::string OakTree::getType() const {
    return "Oak";
}