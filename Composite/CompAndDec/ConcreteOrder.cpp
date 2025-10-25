#include "ConcreteOrder.h"
#include <sstream>

ConcreteOrder::ConcreteOrder(string name) : orderName(name) {}

ConcreteOrder::~ConcreteOrder() {
    for (Order* child : children) {
        delete child;
    }
}

double ConcreteOrder::getPrice() {
    double total = 0;
    for (Order* child : children) {
        total += child->getPrice();
    }
    return total;
}

string ConcreteOrder::getDescription() {
    stringstream ss;
    ss << orderName << ":\n";
    for (Order* child : children) {
        ss << "  - " << child->getDescription() << " ($" << child->getPrice() << ")\n";
    }
    return ss.str();
}

void ConcreteOrder::add(Order* order) {
    children.push_back(order);
}

void ConcreteOrder::remove(Order* order) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == order) {
            children.erase(it);
            break;
        }
    }
}

string ConcreteOrder::getName() const {
    return orderName;
}

int ConcreteOrder::getChildCount() const {
    return children.size();
}

Order* ConcreteOrder::getChild(int index) const {
    if (index >= 0 && index < children.size()) {
        return children[index];
    }
    return nullptr;
}