#include <iostream>
#include "WeaponInventory.h"
#include "WeaponIterator.h"

using namespace std;

int main() {
    // Create the aggregate (WeaponInventory)
    WeaponInventory* weapons = new WeaponInventory();
    
    // Add some weapons
    weapons->addWeapon(Item("Sword", 50));
    weapons->addWeapon(Item("Axe", 75));
    weapons->addWeapon(Item("Bow", 40));
    weapons->addWeapon(Item("Dagger", 30));
    
    cout << "=== Weapon Inventory ===" << endl;
    
    // Create iterator (Factory Method pattern)
    WeaponIterator* it = weapons->createIterator();
    
    // Traverse using iterator
    for (it->first(); !it->isDone(); it->next()) {
        Item weapon = it->currentItem();
        cout << "Weapon: " << weapon.name 
             << ", Damage: " << weapon.damage << endl;
    }
    
    cout << "\n=== Using iterator again ===" << endl;
    
    // Can iterate multiple times
    for (it->first(); !it->isDone(); it->next()) {
        Item weapon = it->currentItem();
        if (weapon.damage > 40) {
            cout << weapon.name << " is a powerful weapon!" << endl;
        }
    }
    
    // Cleanup
    delete it;
    delete weapons;
    
    return 0;
}