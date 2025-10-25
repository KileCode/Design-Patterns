#include "WeaponInventory.h"

WeaponInventory::WeaponInventory() : head(0) {}

WeaponInventory::~WeaponInventory() {
    Node* current = head;
    while (current != 0) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void WeaponInventory::addWeapon(Item weapon) {
    Node* newNode = new Node(weapon);
    
    if (head == 0) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != 0) {
            current = current->next;
        }
        current->next = newNode;
    }
}

WeaponIterator* WeaponInventory::createIterator() {
    return new WeaponIterator(this);
}