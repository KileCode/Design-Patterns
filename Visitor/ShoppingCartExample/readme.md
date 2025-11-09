# Visitor Design Pattern - Shopping Cart System

## Pattern Overview
The Visitor pattern separates pricing/calculation operations from product objects, making it easy to add new pricing rules without modifying the product classes.

## Participants

### Visitor (PricingCalculator.h)
- **Role**: Abstract interface defining calculation operations
- **Responsibility**: Declares a `visit()` method for each ConcreteElement type (Electronics, Clothing, Groceries)
- **Key Feature**: Uses method overloading to handle different product types

### ConcreteVisitor (TaxCalculator, DiscountApplier, ShippingCalculator)
- **Role**: Implements specific pricing calculations
- **Responsibility**: Provides concrete implementation of each `visit()` method with product-specific logic
- **Examples**:
  - `TaxCalculator`: Applies different tax rates (15% electronics, 8% clothing, 0-5% groceries)
  - `DiscountApplier`: Applies category-specific discounts (premium brands, clearance items)
  - `ShippingCalculator`: Calculates shipping costs (fragile handling, refrigerated transport)
- **Key Feature**: Can maintain state (totalTax, totalDiscount, shippingCost)

### Element (Product.h)
- **Role**: Abstract interface for products
- **Responsibility**: Declares `accept()` method that takes a PricingCalculator
- **Key Feature**: Provides common interface for all product types

### ConcreteElement (Electronics, Clothing, Groceries)
- **Role**: Specific product types with unique attributes
- **Unique Attributes**:
  - `Electronics`: warrantyYears
  - `Clothing`: size, isPremiumBrand
  - `Groceries`: isPerishable, weight
- **Responsibility**: Implements `accept()` method by calling `calculator.visit(this)`
- **Key Feature**: Each class's `accept()` enables correct method dispatch via double dispatch

### ObjectStructure (ShoppingCart)
- **Role**: Container that manages the collection of products
- **Responsibility**: Stores products and provides high-level interface for visitor traversal
- **Key Methods**:
  - `addProduct()` / `removeProduct()` - Manage cart
  - `acceptCalculator()` - Apply visitor to all products
- **Key Feature**: Encapsulates iteration logic, allowing calculators to process entire cart

### Client (main.cpp) `Electronics`: warrantyYears
  - `Clothing`: size, isPremiumBrand
  - `Groceries`: isPerishable, weight
- **Responsibility**: Implements `accept()` method by calling `calculator.visit(this)`
- **Key Feature**: Each class's `accept()` enables correct method dispatch via double dispatch

### Client (main.cpp)
- **Role**: Shopping cart coordinator
- **Responsibility**: Creates products, applies visitors, calculates totals

## Double Dispatch Mechanism

1. Client calls `product.accept(calculator)`
2. Product's `accept()` calls `calculator.visit(this)` 
3. Correct `visit()` overload executes based on product's runtime type
4. Calculator accesses product-specific methods (e.g., `getWarrantyYears()`, `getIsPerishable()`)

**Result**: Calculation logic depends on BOTH the calculator type and product type.

## Real-World Benefits
✓ Add new pricing rules (e.g., LoyaltyPointsCalculator) without touching product classes  
✓ Different rules for different categories handled elegantly  
✓ Pricing logic grouped by operation type (high cohesion)  
✓ Products remain simple, focused on data storage

## Tradeoffs
✗ Adding new product types (e.g., Furniture) requires updating all calculators  
✗ Calculators need access to product internals (reduced encapsulation)

## Build & Run
```bash
make          # Compile
./shopping_cart   # Run
make clean    # Clean build files
```

## Sample Output
The system demonstrates:
- Different tax rates per product category
- Category-specific discount rules
- Weight-based and handling-based shipping costs
- Complete order summary with all calculations