#ifndef FOREST_H
#define FOREST_H

#include "Tree.h"
#include "TreeFactory.h"
#include <vector>

/**
 * Forest - Manages collection of trees
 */
class Forest {
private:
    std::vector<Tree*> trees;
    TreeFactory* factory;

public:
    Forest();
    virtual ~Forest();
    
    void plantTree(int x, int y, int scale, std::string type);
    void render() const;
    int getTreeCount() const;
    int getTreeTypeCount() const;
    void displayMemoryUsage() const;
};

#endif