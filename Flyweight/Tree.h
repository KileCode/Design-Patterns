#ifndef TREE_H
#define TREE_H

#include "TreeType.h"

/**
 * Tree - Client/Context
 * Stores extrinsic state (position, scale) and references the shared flyweight
 */
class Tree {
private:
    int x;
    int y;
    int scale;
    TreeType* type;

public:
    Tree(int posX, int posY, int s, TreeType* t);
    virtual ~Tree();
    
    void render() const;
    int getX() const;
    int getY() const;
    int getScale() const;
    std::string getTypeName() const;
};

#endif