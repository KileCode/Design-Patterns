#ifndef BIRCHTREE_H
#define BIRCHTREE_H

#include "TreeType.h"

/**
 * BirchTree - ConcreteFlyweight
 * Implements the interface and stores intrinsic (shareable) state
 */
class BirchTree : public TreeType {
public:
    BirchTree();
    BirchTree(std::string c, std::string t);
    virtual ~BirchTree();
    
    virtual void render(int x, int y, int scale) const;
    virtual std::string getType() const;
};

#endif