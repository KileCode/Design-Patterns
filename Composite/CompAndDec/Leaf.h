#ifndef LEAF_H
#define LEAF_H

#include "Order.h"
#include "Plant.h"

class Leaf : public Order {
private:
    Plant* plant;
    int quantity;

public:
    Leaf(Plant* p, int qty);
    ~Leaf();
    double getPrice() override;
    string getDescription() override;
    
    // Getters for cloning
    Plant* getPlant() const;
    int getQuantity() const;
};

#endif