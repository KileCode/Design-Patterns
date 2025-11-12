#include "BirchTree.h"
#include <iostream>

BirchTree::BirchTree() : TreeType("Birch", "White", "birch_bark.png") {}

BirchTree::BirchTree(std::string c, std::string t) 
    : TreeType("Birch", c, t) {}

BirchTree::~BirchTree() {}

void BirchTree::render(int x, int y, int scale) const {
    std::cout << "Rendering Birch tree at (" << x << "," << y 
              << ") scale:" << scale << "% - Color:" << color 
              << " Texture:" << texture << std::endl;
}

std::string BirchTree::getType() const {
    return "Birch";
}