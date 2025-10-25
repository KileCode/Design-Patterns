#include "Order.h"
#include <iostream>

Order::~Order() {}

void Order::add(Order* order) {
    cout << "Cannot add to a leaf" << endl;
}

void Order::remove(Order* order) {
    cout << "Cannot remove from a leaf" << endl;
}