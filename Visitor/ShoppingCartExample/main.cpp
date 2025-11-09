#include "Product.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Groceries.h"
#include "TaxCalculator.h"
#include "DiscountApplier.h"
#include "ShippingCalculator.h"
#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "=== Shopping Cart System using Visitor Pattern ===" << std::endl;
    std::cout << std::endl;

    // Create various products (ConcreteElements)
    Electronics laptop("Gaming Laptop", 1299.99, 3);
    Electronics phone("Smartphone", 799.99, 1);
    Clothing jacket("Designer Jacket", 249.99, "L", true);
    Clothing tshirt("Cotton T-Shirt", 29.99, "M", false);
    Groceries milk("Organic Milk", 5.99, true, 1.0);
    Groceries rice("Basmati Rice", 12.99, false, 5.0);

    // Create ObjectStructure (ShoppingCart) and add products
    ShoppingCart cart;
    cart.addProduct(&laptop);
    cart.addProduct(&phone);
    cart.addProduct(&jacket);
    cart.addProduct(&tshirt);
    cart.addProduct(&milk);
    cart.addProduct(&rice);

    std::cout << "Shopping Cart Contents (" << cart.getItemCount() << " items):" << std::endl;
    std::cout << "------------------------" << std::endl;
    for (Product* product : cart.getProducts()) {
        std::cout << "- " << product->getName() 
                  << " (" << product->getCategory() << "): $" 
                  << std::fixed << std::setprecision(2) << product->getBasePrice() << std::endl;
    }
    std::cout << std::endl;

    // Calculate totals
    double subtotal = 0.0;
    for (Product* product : cart.getProducts()) {
        subtotal += product->getBasePrice();
    }

    std::cout << "=== Running TaxCalculator Visitor ===" << std::endl;
    TaxCalculator taxCalc;
    double totalTax = 0.0;
    for (Product* product : cart.getProducts()) {
        product->accept(taxCalc);
        totalTax += taxCalc.getTotalTax();
        std::cout << std::endl;
    }

    std::cout << "=== Running DiscountApplier Visitor ===" << std::endl;
    DiscountApplier discountCalc;
    double totalDiscount = 0.0;
    for (Product* product : cart.getProducts()) {
        product->accept(discountCalc);
        totalDiscount += discountCalc.getTotalDiscount();
        std::cout << std::endl;
    }

    std::cout << "=== Running ShippingCalculator Visitor ===" << std::endl;
    ShippingCalculator shippingCalc;
    double totalShipping = 0.0;
    for (Product* product : cart.getProducts()) {
        product->accept(shippingCalc);
        totalShipping += shippingCalc.getShippingCost();
        std::cout << std::endl;
    }

    std::cout << "=== Demonstrating ObjectStructure (ShoppingCart) ===" << std::endl;
    std::cout << "The ShoppingCart can also use acceptCalculator() to traverse all items:" << std::endl;
    TaxCalculator taxCalc2;
    cart.acceptCalculator(taxCalc2); // ObjectStructure handles iteration
    std::cout << std::endl;

    std::cout << "=== Order Summary ===" << std::endl;
    std::cout << "Subtotal:        $" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    std::cout << "Discounts:      -$" << totalDiscount << std::endl;
    std::cout << "Tax:            +$" << totalTax << std::endl;
    std::cout << "Shipping:       +$" << totalShipping << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Total:           $" << (subtotal - totalDiscount + totalTax + totalShipping) << std::endl;
    std::cout << std::endl;

    std::cout << "=== Pattern Structure Demonstrated ===" << std::endl;
    std::cout << "ObjectStructure: ShoppingCart (stores and manages products)" << std::endl;
    std::cout << "Elements: Electronics, Clothing, Groceries" << std::endl;
    std::cout << "Visitors: TaxCalculator, DiscountApplier, ShippingCalculator" << std::endl;
    std::cout << "Client: main() (coordinates visitors and object structure)" << std::endl;

    return 0;
}