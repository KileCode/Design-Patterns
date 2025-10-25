#ifndef WEAPONINVENTORY_H
#define WEAPONINVENTORY_H

#include "Node.h"
#include "WeaponIterator.h"

// Forward declaration
class WeaponIterator;

// ConcreteAggregate from pattern
class WeaponInventory {
    friend class WeaponIterator;
    
private:
    Node* head;
    
public:
    WeaponInventory();
    ~WeaponInventory();
    
    void addWeapon(Item weapon);
    WeaponIterator* createIterator();
};

#endif