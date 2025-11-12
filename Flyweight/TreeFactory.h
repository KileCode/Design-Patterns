#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "TreeType.h"
#include <map>
#include <string>

/**
 * TreeFactory - FlyweightFactory
 * Creates an instance of a flyweight if it does not exist or supplies an existing one
 */
class TreeFactory {
private:
    std::map<std::string, TreeType*> treeTypes;

public:
    TreeFactory();
    virtual ~TreeFactory();
    
    TreeType* getTreeType(std::string type);
    int getTreeTypeCount() const;
};

#endif