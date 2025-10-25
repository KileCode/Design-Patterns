#ifndef ITEM_H
#define ITEM_H

// Simple item structure
class Item {
public:
    char name[50];
    int damage;
    
    Item() : damage(0) {
        name[0] = '\0';
    }
    
    Item(const char* n, int d) : damage(d) {
        int i = 0;
        while (n[i] != '\0' && i < 49) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }
};

#endif