#ifndef CONCRETEORDER_H
#define CONCRETEORDER_H

#include "Order.h"
#include <vector>
#include <string>

class ConcreteOrder : public Order {
private:
    vector<Order*> children;
    string orderName;

public:
    ConcreteOrder(string name);
    ~ConcreteOrder();
    double getPrice() override;
    string getDescription() override;
    void add(Order* order) override;
    void remove(Order* order) override;
    
    // Getters for cloning
    string getName() const;
    int getChildCount() const;
    Order* getChild(int index) const;
};

#endif