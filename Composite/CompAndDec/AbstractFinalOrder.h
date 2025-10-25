#ifndef ABSTRACTFINALORDER_H
#define ABSTRACTFINALORDER_H

class AbstractFinalOrder {
public:
    virtual ~AbstractFinalOrder();
    virtual AbstractFinalOrder* clone() = 0;
    virtual void calculateTotalPrice() = 0;
    virtual double getTotalPrice() = 0;
};

#endif