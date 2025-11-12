#ifndef PINETREE_H
#define PINETREE_H

#include "TreeType.h"

/**
 * PineTree - ConcreteFlyweight
 * Implements the interface and stores intrinsic (shareable) state
 */
class PineTree : public TreeType {
public:
    PineTree();
    PineTree(std::string c, std::string t);
    virtual ~PineTree();
    
    virtual void render(int x, int y, int scale) const;
    virtual std::string getType() const;
};

#endif