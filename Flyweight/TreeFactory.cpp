#include "TreeFactory.h"
#include "OakTree.h"
#include "PineTree.h"
#include "BirchTree.h"
#include <iostream>

TreeFactory::TreeFactory() {}

TreeFactory::~TreeFactory() {
    for (std::map<std::string, TreeType*>::iterator it = treeTypes.begin();
         it != treeTypes.end(); ++it) {
        delete it->second;
    }
}

TreeType* TreeFactory::getTreeType(std::string type) {
    std::map<std::string, TreeType*>::iterator it = treeTypes.find(type);
    
    if (it != treeTypes.end()) {
        std::cout << "[Factory] Returning existing " << type << " flyweight" << std::endl;
        return it->second;
    } else {
        std::cout << "[Factory] Creating new " << type << " flyweight" << std::endl;
        TreeType* newTree = nullptr;
        
        if (type == "Oak") {
            newTree = new OakTree();
        } else if (type == "Pine") {
            newTree = new PineTree();
        } else if (type == "Birch") {
            newTree = new BirchTree();
        }
        
        if (newTree != nullptr) {
            treeTypes.insert(std::pair<std::string, TreeType*>(type, newTree));
        }
        
        return newTree;
    }
}

int TreeFactory::getTreeTypeCount() const {
    return treeTypes.size();
}