# Singleton Design Pattern - Game Settings Manager

## Overview

This project demonstrates the **Singleton Design Pattern** using a Game Settings Manager as a practical example. The implementation follows the structure outlined in the COS214 course slides and includes both the **Standard (Muldner) Implementation** and the **Meyers Implementation**.

## What is the Singleton Pattern?

**Intent**: "Ensure a class only has one instance, and provide a global point of access to it." - GoF(127)

**Classification**: Object Creational Pattern

### Why Use Singleton for Game Settings?

In a game application, you want:
- **ONE** centralized place to store all settings (volume, difficulty, player name, etc.)
- **Consistent** settings across all parts of the game (main menu, gameplay, options screen)
- **No conflicts** from multiple settings objects with different values
- **Global access** so any part of the game can read/modify settings

Without Singleton, different parts of your game might create separate settings objects, leading to inconsistencies!

## Project Structure

```
.
├── GameSettings.h              # Standard implementation header
├── GameSettings.cpp            # Standard implementation source
├── GameSettingsMeyers.h        # Meyers implementation header
├── GameSettingsMeyers.cpp      # Meyers implementation source
├── main.cpp                    # Demonstration program
├── Makefile                    # Build automation
└── README.md                   # This file
```

## Pattern Participants

According to the slides, the Singleton pattern has one main participant:

### Singleton
- Defines an **instance operation** that ensures the object is only constructible via this operation
- The instance operation is a **static method** that returns the single instance
- **Constructor, Copy Constructor, Assignment Operator, and Destructor** are private/protected to prevent external instantiation

## Two Implementation Approaches

### 1. Standard (Muldner) Implementation

**Files**: `GameSettings.h`, `GameSettings.cpp`

**Key Characteristics**:
```cpp
class GameSettings {
private:
    static GameSettings* onlyInstance;  // Static pointer
    GameSettings();                      // Private constructor
    
public:
    static GameSettings* instance() {
        if (onlyInstance == nullptr) {
            onlyInstance = new GameSettings();  // Created on HEAP
        }
        return onlyInstance;
    }
};
```

**How it works**:
- Returns a **pointer** to the singleton
- Creates instance on the **heap** using `new`
- Lazy initialization (created on first call)
- Access: `settings->method()`

**Issues**:
- ⚠️ **Memory leak**: Instance is never deleted
- Not automatically destroyed when program ends

### 2. Meyers Implementation

**Files**: `GameSettingsMeyers.h`, `GameSettingsMeyers.cpp`

**Key Characteristics**:
```cpp
class GameSettingsMeyers {
private:
    GameSettingsMeyers();  // Private constructor
    
public:
    static GameSettingsMeyers& instance() {
        static GameSettingsMeyers theInstance;  // Static local variable
        return theInstance;
    }
};
```

**How it works**:
- Returns a **reference** to the singleton
- Creates instance on the **stack** as a static local variable
- Lazy initialization (created on first call)
- Access: `settings.method()`

**Advantages**:
- ✅ **No memory leak**: Automatically destroyed when program ends
- ✅ **Thread-safe** in C++11 and later
- ✅ **Cleaner**: No manual memory management needed

**From the slides**: "The Meyers solution solves the memory leak problem!"

## Answering the Slide Questions

### Q1: Where is the instance variable `onlyInstance` initialized?

**Answer**: In the `.cpp` file, outside any function:
```cpp
GameSettings* GameSettings::onlyInstance = nullptr;
```

### Q2: What about the memory leak?

**Answer**: In the Standard implementation, we allocate memory with `new` but never `delete` it. The memory is only freed when the program terminates. The **Meyers implementation solves this** by using a static local variable that's automatically destroyed.

### Q3: Would a virtual destructor solve the memory leak problem?

**Answer**: No. A virtual destructor is needed for proper polymorphic destruction in inheritance hierarchies, but it doesn't solve the leak itself—we still never call `delete` on `onlyInstance`.

### Q4: Why must the Constructor, Copy Constructor, Assignment operator and Destructor be protected or private?

**Answer**:
- **Constructor**: Prevents direct instantiation (`GameSettings gs;` won't compile)
- **Copy Constructor**: Prevents copying (`GameSettings copy = *instance();` won't compile)
- **Assignment Operator**: Prevents assignment (`*settings1 = *settings2;` won't compile)
- **Destructor**: Controls how the object is destroyed

This ensures only ONE instance can exist!

### Q5: What are the implications of private vs protected?

**Answer**:
- **Private**: No inheritance possible; singleton cannot be a base class
- **Protected**: Allows inheritance, but derived classes could break the singleton guarantee—use with caution!

### Q6: Do I know how many calls to Singleton instance have been made?

**Answer**: Yes! Both implementations include an `instanceCallCount` static variable that tracks this:
```cpp
static int getInstanceCallCount();
```

## Building and Running

### Compile the project:
```bash
make
```

### Run the program:
```bash
make run
```

### Clean build files:
```bash
make clean
```

### Rebuild everything:
```bash
make rebuild
```

### See all commands:
```bash
make help
```

## Expected Output

When you run the program, you'll see:

1. **Standard Implementation Demo**:
   - Multiple parts of the game accessing settings
   - Settings changes persist across all access points
   - All pointers have the same memory address
   - Instance call count tracking
   - NO destructor called (memory leak!)

2. **Meyers Implementation Demo**:
   - Same behavior as Standard
   - All references have the same memory address
   - Destructor IS called when program ends (proper cleanup!)

3. **Key Differences Summary**:
   - Side-by-side comparison of both approaches

## Key Takeaways

1. **Singleton ensures only ONE instance** exists throughout the program
2. **Global access point** via the `instance()` static method
3. **Private constructors** prevent external instantiation
4. **Standard implementation** has a memory leak (never deleted)
5. **Meyers implementation** is preferred (no leak, thread-safe)
6. **Use Singleton when** you need exactly one instance with global access

## Related Patterns (from slides)

Many design patterns can make use of a Singleton:
- **Abstract Factory**: Factory itself can be a singleton
- **Builder**: Builder director can be a singleton
- **Prototype**: Prototype registry can be a singleton
- **Facade**: Facade object often is a singleton

## References

- T. Muldner, *C++ Programming with Design Patterns Revealed*, Addison-Wesley, 2002
- Gang of Four (GoF), *Design Patterns: Elements of Reusable Object-Oriented Software*
- COS214 Course Slides - University of Pretoria

## Author

Created as a practical example for learning the Singleton design pattern in COS214.

---

**Happy Learning! 🎮**