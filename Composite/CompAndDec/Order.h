#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

class Order {
public:
    virtual ~Order();
    virtual double getPrice() = 0;
    virtual string getDescription() = 0;
    virtual void add(Order* order);
    virtual void remove(Order* order);
};

#endif