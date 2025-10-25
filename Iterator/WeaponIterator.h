#ifndef WEAPONITERATOR_H
#define WEAPONITERATOR_H

#include "Iterator.h"
#include "WeaponInventory.h"

// Forward declaration
class WeaponInventory;

// ConcreteIterator from pattern
class WeaponIterator : public Iterator {
private:
    WeaponInventory* inventory;
    Node* current;
    
public:
    WeaponIterator(WeaponInventory* inv);
    
    void first();
    void next();
    bool isDone();
    Item currentItem();
};

#endif