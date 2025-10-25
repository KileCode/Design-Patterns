#ifndef FINALORDER_H
#define FINALORDER_H

#include "AbstractFinalOrder.h"
#include "Order.h"
#include <string>

class FinalOrder : public AbstractFinalOrder {
private:
    Order* order;
    double totalPrice;
    
    Order* deepCopyOrder(Order* original);

public:
    FinalOrder();
    FinalOrder(Order* ord);
    ~FinalOrder();
    
    AbstractFinalOrder* clone() override;
    void calculateTotalPrice() override;
    double getTotalPrice() override;
    std::string getOrderDetails();
    void setOrder(Order* ord);
};

#endif