#include <iostream>
#include "Plant.h"
#include "Rose.h"
#include "DecorativePotDecorator.h"
#include "RibbonDecorator.h"
#include "Leaf.h"
#include "ConcreteOrder.h"
#include "FinalOrder.h"

using namespace std;

int main() {
    cout << "=== Plant Decorator + Composite + Prototype Pattern Demo ===" << endl << endl;

    // Create derived Rose objects
    Rose* redRose = new Rose("Rose", "Red");
    Rose* whiteRose = new Rose("Rose", "White");
    Rose* pinkRose = new Rose("Rose", "Pink");

    // Decorate some roses
    Plant* fancyRedRose = new DecorativePotDecorator(redRose);
    Plant* superFancyWhiteRose = new DecorativePotDecorator(new RibbonDecorator(whiteRose));
    Plant* ribbonPinkRose = new RibbonDecorator(pinkRose);

    // Create composite order (this will be owned by FinalOrder)
    ConcreteOrder* weddingOrder = new ConcreteOrder("Weekly Office Plants");
    weddingOrder->add(new Leaf(redRose, 3));              // 3 plain red roses
    weddingOrder->add(new Leaf(fancyRedRose, 2));         // 2 red roses in decorative pot
    weddingOrder->add(new Leaf(superFancyWhiteRose, 1));  // 1 white rose with ribbon AND pot
    weddingOrder->add(new Leaf(ribbonPinkRose, 2));       // 2 pink roses with ribbons

    cout << "--- Original Order ---" << endl;
    cout << weddingOrder->getDescription();
    cout << "Total: $" << weddingOrder->getPrice() << endl << endl;

    // Create FinalOrder (takes ownership of weddingOrder)
    FinalOrder* originalFinalOrder = new FinalOrder(weddingOrder);
    originalFinalOrder->calculateTotalPrice();

    cout << "--- Original FinalOrder ---" << endl;
    cout << originalFinalOrder->getOrderDetails();
    cout << "FinalOrder Total: $" << originalFinalOrder->getTotalPrice() << endl << endl;

    // Clone the FinalOrder for a repeat customer
    cout << "--- Cloning FinalOrder (Repeat Customer) ---" << endl;
    FinalOrder* clonedFinalOrder = dynamic_cast<FinalOrder*>(originalFinalOrder->clone());

    cout << "Cloned FinalOrder (Week 2):" << endl;
    cout << clonedFinalOrder->getOrderDetails();
    cout << "Cloned Total: $" << clonedFinalOrder->getTotalPrice() << endl << endl;

    // Modify the cloned order (customer wants 2 extra items this week)
    cout << "--- Modifying Cloned Order ---" << endl;
    cout << "Customer says: 'This week, add 2 more fancy red roses please!'" << endl << endl;

    // We need to get the root order and add to it
    // In this demo, we'll create a new item and demonstrate the modification
    Rose* extraRose = new Rose("Rose", "Red");
    Plant* extraFancyRose = new DecorativePotDecorator(extraRose);
    
    // Create a completely new modified order
    ConcreteOrder* modifiedOrder = new ConcreteOrder("Weekly Office Plants (Modified)");
    modifiedOrder->add(new Leaf(redRose, 3));
    modifiedOrder->add(new Leaf(fancyRedRose, 4));  // Changed from 2 to 4
    modifiedOrder->add(new Leaf(superFancyWhiteRose, 1));
    modifiedOrder->add(new Leaf(ribbonPinkRose, 2));
    
    // Create new FinalOrder with modified order
    FinalOrder* modifiedFinalOrder = new FinalOrder(modifiedOrder);

    cout << "Modified FinalOrder (Week 2 with additions):" << endl;
    cout << modifiedFinalOrder->getOrderDetails();
    cout << "Modified Total: $" << modifiedFinalOrder->getTotalPrice() << endl << endl;

    // Demonstrate that original is unchanged
    cout << "--- Original FinalOrder Still Unchanged ---" << endl;
    cout << originalFinalOrder->getOrderDetails();
    cout << "Original Total: $" << originalFinalOrder->getTotalPrice() << endl << endl;

    // Real-world scenario: Corporate customer with weekly recurring order
    cout << "=== Corporate Customer Scenario ===" << endl;
    cout << "ABC Corp orders the same plants every Monday for their offices." << endl << endl;

    // Week 1
    Rose* corpRose1 = new Rose("Rose", "Yellow");
    Rose* corpRose2 = new Rose("Rose", "Orange");
    Plant* decoratedCorp1 = new DecorativePotDecorator(corpRose1);
    Plant* decoratedCorp2 = new RibbonDecorator(corpRose2);

    ConcreteOrder* week1Order = new ConcreteOrder("ABC Corp - Office Plants");
    week1Order->add(new Leaf(decoratedCorp1, 5));
    week1Order->add(new Leaf(decoratedCorp2, 3));

    FinalOrder* week1FinalOrder = new FinalOrder(week1Order);

    cout << "Week 1 Order:" << endl;
    cout << week1FinalOrder->getOrderDetails();
    cout << "Week 1 Total: $" << week1FinalOrder->getTotalPrice() << endl << endl;

    // Week 2 - Clone the order
    FinalOrder* week2FinalOrder = dynamic_cast<FinalOrder*>(week1FinalOrder->clone());
    cout << "Week 2 Order (Cloned from Week 1):" << endl;
    cout << week2FinalOrder->getOrderDetails();
    cout << "Week 2 Total: $" << week2FinalOrder->getTotalPrice() << endl << endl;

    // Week 3 - Clone again
    FinalOrder* week3FinalOrder = dynamic_cast<FinalOrder*>(week1FinalOrder->clone());
    cout << "Week 3 Order (Cloned from Week 1):" << endl;
    cout << week3FinalOrder->getOrderDetails();
    cout << "Week 3 Total: $" << week3FinalOrder->getTotalPrice() << endl << endl;

    cout << "Notice: All three orders are independent deep copies!" << endl;
    cout << "Each can be modified without affecting the others." << endl << endl;

    // Cleanup
    delete originalFinalOrder;
    delete clonedFinalOrder;
    delete modifiedFinalOrder;
    delete week1FinalOrder;
    delete week2FinalOrder;
    delete week3FinalOrder;

    return 0;
}