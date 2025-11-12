#ifndef OAKTREE_H
#define OAKTREE_H

#include "TreeType.h"

/**
 * OakTree - ConcreteFlyweight
 * Implements the interface and stores intrinsic (shareable) state
 */
class OakTree : public TreeType {
public:
    OakTree();
    OakTree(std::string c, std::string t);
    virtual ~OakTree();
    
    virtual void render(int x, int y, int scale) const;
    virtual std::string getType() const;
};

#endif