# Abstract Factory Design Pattern

## Overview
The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

## Intent
- Create families of related objects without specifying concrete classes
- Ensure product family consistency
- Support multiple product families through different factories

---

## Pattern Structure

### Participants

#### 1. **AbstractFactory** (VehicleFactory)
- Declares interface for creating abstract products
- Contains factory methods for each product type

#### 2. **ConcreteFactory** (ToyotaFactory, BMWFactory, TeslaFactory)
- Implements the abstract factory interface
- Creates concrete products belonging to one family
- Each factory creates a complete product family

#### 3. **AbstractProduct** (Sedan, SUV, Truck)
- Declares interface for a type of product
- Defines common operations all products must support

#### 4. **ConcreteProduct** (ToyotaSedan, BMWSedan, TeslaSedan, etc.)
- Implements the abstract product interface
- Created by corresponding concrete factory
- 9 total: 3 manufacturers × 3 vehicle types

#### 5. **Client** (main.cpp)
- Uses only abstract interfaces (AbstractFactory and AbstractProduct)
- Never instantiates concrete products directly
- Receives a concrete factory and works through abstract interface

---

## How This Example Relates to the Pattern

### Pattern Mapping

| Pattern Role | Our Implementation |
|--------------|-------------------|
| AbstractFactory | `VehicleFactory` |
| ConcreteFactory₁ | `ToyotaFactory` |
| ConcreteFactory₂ | `BMWFactory` |
| ConcreteFactory₃ | `TeslaFactory` |
| AbstractProductA | `Sedan` |
| AbstractProductB | `SUV` |
| AbstractProductC | `Truck` |
| ConcreteProductA₁ | `ToyotaSedan` |
| ConcreteProductA₂ | `BMWSedan` |
| ConcreteProductA₃ | `TeslaSedan` |
| (+ 6 more products) | (BMW/Tesla SUV/Truck) |
| Client | `main()` function |

### Product Families

Each factory creates a complete family:

```
Toyota Family: ToyotaSedan, ToyotaSUV, ToyotaTruck
BMW Family:    BMWSedan,    BMWSUV,    BMWTruck
Tesla Family:  TeslaSedan,  TeslaSUV,  TeslaTruck
```

---

## Key Concepts

### 1. **Family Consistency**
When you choose a factory, all products come from the same family:
```cpp
VehicleFactory* factory = new ToyotaFactory();
Sedan* sedan = factory->createSedan();   // Gets ToyotaSedan
SUV* suv = factory->createSUV();         // Gets ToyotaSUV
Truck* truck = factory->createTruck();   // Gets ToyotaTruck
// All three are Toyota products - guaranteed!
```

### 2. **Client Independence**
The client never knows about concrete classes:
```cpp
// Client code works with abstract types only
VehicleFactory* factory = /* some factory */;
Sedan* sedan = factory->createSedan();  // Don't know which sedan
sedan->drive();                         // Don't care which sedan
```

### 3. **Factory Interchangeability**
Switch factories without changing client code:
```cpp
// Same client code, different factory
VehicleFactory* factory1 = new ToyotaFactory();
showInventory(factory1);  // Shows Toyota vehicles

VehicleFactory* factory2 = new BMWFactory();
showInventory(factory2);  // Shows BMW vehicles
// Same function, different results!
```

---

## Important Design Decisions

### Where the Client Decides:

1. **Which factory to instantiate**
   - `VehicleFactory* factory = new ToyotaFactory();`
   - This is the ONLY place concrete classes appear in client code

2. **When to switch factories**
   - Can create different factories at runtime
   - Based on user input, configuration, or business logic

3. **Which products to create**
   - `factory->createSedan()` vs `factory->createSUV()`
   - But NOT which concrete type (Toyota vs BMW)

### What the Pattern Guarantees:

1. **Type Safety**: All products implement correct interfaces
2. **Family Consistency**: All products from one factory belong to same family
3. **Easy Extension**: Add new families by creating new factories
4. **Decoupling**: Client doesn't depend on concrete classes

---

## Benefits

✅ **Isolates concrete classes** - Client uses only abstract interfaces  
✅ **Easy to exchange product families** - Just swap the factory  
✅ **Promotes consistency** - Products from one family work together  
✅ **Supports new families** - Add new factory without changing client  

---

## When to Use

Use Abstract Factory when:
- System needs to be independent of how products are created
- System should work with multiple families of related products
- Family of related products must be used together
- You want to provide a library of products without exposing implementations

---

## File Organization in Our Example

```
Abstract Products (Interfaces):
├── Sedan.h
├── SUV.h
└── Truck.h

Concrete Products (Grouped by Family):
├── ToyotaProducts.h/.cpp  (ToyotaSedan, ToyotaSUV, ToyotaTruck)
├── BMWProducts.h/.cpp     (BMWSedan, BMWSUV, BMWTruck)
└── TeslaProducts.h/.cpp   (TeslaSedan, TeslaSUV, TeslaTruck)

Abstract Factory:
└── VehicleFactory.h

Concrete Factories:
├── ToyotaFactory.h/.cpp
├── BMWFactory.h/.cpp
└── TeslaFactory.h/.cpp

Client:
└── main.cpp
```

---

## Class Relationships

```
Client (main)
    ↓ uses
VehicleFactory (abstract)
    ↑ implements
    ├── ToyotaFactory
    ├── BMWFactory
    └── TeslaFactory
    
VehicleFactory creates →
    ├── Sedan (abstract) → ToyotaSedan, BMWSedan, TeslaSedan
    ├── SUV (abstract)   → ToyotaSUV, BMWSUV, TeslaSUV
    └── Truck (abstract) → ToyotaTruck, BMWTruck, TeslaTruck
```

---

## Example Usage Flow

1. **Client decides** which factory: `new ToyotaFactory()`
2. **Factory creates** products: `factory->createSedan()`
3. **Returns abstract type**: `Sedan*` (not `ToyotaSedan*`)
4. **Client uses** through interface: `sedan->drive()`
5. **No knowledge** of concrete class in client code

---

## Summary

The Abstract Factory pattern is all about **families of related objects**. The client chooses which family (factory) to use, and the pattern guarantees all products come from that family. The client never needs to know the concrete classes—it works entirely through abstract interfaces.

**Core Principle**: *"Depend on abstractions, not concretions"*