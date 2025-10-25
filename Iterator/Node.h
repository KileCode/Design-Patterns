#ifndef NODE_H
#define NODE_H

#include "Item.h"

// Node for linked list storage
class Node {
public:
    Item item;
    Node* next;
    
    Node() : next(0) {}
    Node(Item i) : item(i), next(0) {}
};

#endif