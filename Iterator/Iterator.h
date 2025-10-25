#ifndef ITERATOR_H
#define ITERATOR_H

#include "Item.h"

// Iterator interface (Abstract Iterator from pattern)
class Iterator {
public:
    virtual ~Iterator() {}
    
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Item currentItem() = 0;
};

#endif