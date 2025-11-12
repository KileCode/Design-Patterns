#include "Forest.h"
#include <iostream>

Forest::Forest() {
    factory = new TreeFactory();
}

Forest::~Forest() {
    for (std::vector<Tree*>::iterator it = trees.begin(); 
         it != trees.end(); ++it) {
        delete *it;
    }
    delete factory;
}

void Forest::plantTree(int x, int y, int scale, std::string type) {
    TreeType* treeType = factory->getTreeType(type);
    if (treeType != nullptr) {
        Tree* tree = new Tree(x, y, scale, treeType);
        trees.push_back(tree);
    }
}

void Forest::render() const {
    std::cout << "\n=== Rendering Forest ===" << std::endl;
    for (std::vector<Tree*>::const_iterator it = trees.begin(); 
         it != trees.end(); ++it) {
        (*it)->render();
    }
    std::cout << "========================\n" << std::endl;
}

int Forest::getTreeCount() const {
    return trees.size();
}

int Forest::getTreeTypeCount() const {
    return factory->getTreeTypeCount();
}

void Forest::displayMemoryUsage() const {
    size_t intrinsicSize = factory->getTreeTypeCount() * sizeof(TreeType);
    size_t extrinsicSize = trees.size() * sizeof(Tree);
    size_t totalSize = intrinsicSize + extrinsicSize;
    
    std::cout << "\n=== Memory Usage Analysis ===" << std::endl;
    std::cout << "Total trees: " << trees.size() << std::endl;
    std::cout << "Unique tree types (flyweights): " << factory->getTreeTypeCount() << std::endl;
    std::cout << "Intrinsic state memory (shared): ~" << intrinsicSize << " bytes" << std::endl;
    std::cout << "Extrinsic state memory (per tree): ~" << extrinsicSize << " bytes" << std::endl;
    std::cout << "Total memory: ~" << totalSize << " bytes" << std::endl;
    std::cout << "\nWithout Flyweight pattern:" << std::endl;
    std::cout << "Would need: ~" << (trees.size() * sizeof(TreeType)) << " bytes just for tree type data" << std::endl;
    std::cout << "Memory saved: ~" << ((trees.size() * sizeof(TreeType)) - intrinsicSize) << " bytes" << std::endl;
    std::cout << "==============================\n" << std::endl;
}