#include "FinalOrder.h"
#include "Leaf.h"
#include "ConcreteOrder.h"
#include <iostream>

FinalOrder::FinalOrder() : order(nullptr), totalPrice(0.0) {}

FinalOrder::FinalOrder(Order* ord) : order(ord), totalPrice(0.0) {
    calculateTotalPrice();
}

FinalOrder::~FinalOrder() {
    if (order != nullptr) {
        delete order;
    }
}

Order* FinalOrder::deepCopyOrder(Order* original) {
    if (original == nullptr) {
        return nullptr;
    }
    
    // Try to cast to ConcreteOrder (composite)
    ConcreteOrder* composite = dynamic_cast<ConcreteOrder*>(original);
    if (composite != nullptr) {
        // It's a composite - create new composite and recursively copy children
        ConcreteOrder* newComposite = new ConcreteOrder(composite->getName());
        
        for (int i = 0; i < composite->getChildCount(); i++) {
            Order* child = composite->getChild(i);
            Order* clonedChild = deepCopyOrder(child);
            newComposite->add(clonedChild);
        }
        
        return newComposite;
    }
    
    // Try to cast to Leaf
    Leaf* leaf = dynamic_cast<Leaf*>(original);
    if (leaf != nullptr) {
        // It's a leaf - create new leaf with same plant and quantity
        // Note: In this simplified version, we're sharing plant references
        // In a full implementation, you might want to clone plants too
        return new Leaf(leaf->getPlant(), leaf->getQuantity());
    }
    
    return nullptr;
}

AbstractFinalOrder* FinalOrder::clone() {
    FinalOrder* cloned = new FinalOrder();
    
    if (order != nullptr) {
        cloned->order = deepCopyOrder(order);
        cloned->calculateTotalPrice();
    }
    
    return cloned;
}

void FinalOrder::calculateTotalPrice() {
    if (order != nullptr) {
        totalPrice = order->getPrice();
    } else {
        totalPrice = 0.0;
    }
}

double FinalOrder::getTotalPrice() {
    return totalPrice;
}

std::string FinalOrder::getOrderDetails() {
    if (order != nullptr) {
        return order->getDescription();
    }
    return "Empty order";
}

void FinalOrder::setOrder(Order* ord) {
    if (order != nullptr) {
        delete order;
    }
    order = ord;
    calculateTotalPrice();
}