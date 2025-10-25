#include "WeaponIterator.h"

WeaponIterator::WeaponIterator(WeaponInventory* inv) 
    : inventory(inv), current(0) {
    first();
}

void WeaponIterator::first() {
    current = inventory->head;
}

void WeaponIterator::next() {
    if (current != 0) {
        current = current->next;
    }
}

bool WeaponIterator::isDone() {
    return current == 0;
}

Item WeaponIterator::currentItem() {
    if (current != 0) {
        return current->item;
    }
    return Item();
}