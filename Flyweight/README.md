# Flyweight Design Pattern - Forest Renderer

## Overview

This project demonstrates the **Flyweight Design Pattern** using a Forest/Tree Renderer as a practical example. The implementation follows the structure from the COS214 course slides.

## What is the Flyweight Pattern?

**Intent**: "Use sharing to support large numbers of fine-grained objects efficiently." - GoF(195)

**Classification**: Object Structural Pattern

### Why Use Flyweight for a Forest?

Rendering thousands of trees is memory-intensive. Without optimization:
- Each tree would store its own texture, color, and type data
- 10,000 trees = 10,000 copies of the same texture data

With Flyweight:
- Tree types (Oak, Pine, Birch) are shared flyweights
- Only 3 flyweight objects store texture/color data
- 10,000 trees share these 3 flyweights
- Massive memory savings!

## Project Structure

```
.
├── TreeType.h/cpp          # Flyweight interface
├── OakTree.h/cpp           # ConcreteFlyweight
├── PineTree.h/cpp          # ConcreteFlyweight
├── BirchTree.h/cpp         # ConcreteFlyweight
├── TreeFactory.h/cpp       # FlyweightFactory
├── Tree.h/cpp              # Client/Context
├── Forest.h/cpp            # Forest manager
├── main.cpp                # Demonstration
├── Makefile                # Build automation
└── README.md               # This file
```

## Pattern Participants

### Flyweight (TreeType)
Defines the interface through which flyweights are instantiated

### ConcreteFlyweight (OakTree, PineTree, BirchTree)
Implements the interface and stores **intrinsic state** (shareable)

### FlyweightFactory (TreeFactory)
Creates an instance of a flyweight if it does not exist or supplies an existing one

### Client (Tree)
Stores **extrinsic state** and references the shared flyweight

## Intrinsic vs Extrinsic State

### Intrinsic State (Shared)
Stored in the flyweight, independent of context:
- Tree type name (Oak, Pine, Birch)
- Color
- Texture file path

### Extrinsic State (Unique)
Stored in the client, depends on context:
- X position
- Y position  
- Scale

## How It Works

1. **Client requests a tree**: Forest wants to plant an Oak at (10, 20)
2. **Factory checks cache**: Has Oak flyweight been created?
   - If yes: Return existing Oak flyweight
   - If no: Create new Oak flyweight, cache it, return it
3. **Client stores extrinsic state**: Tree object stores position (10, 20) and scale
4. **Rendering**: Tree passes extrinsic state to flyweight's render() method

## Building and Running

```bash
make          # Compile
make run      # Build and run
make clean    # Clean build files
make rebuild  # Clean and rebuild
make help     # Show commands
```

## Memory Efficiency

### Without Flyweight
10,000 trees × ~100 bytes per tree type = ~1,000,000 bytes

### With Flyweight
3 tree types × ~100 bytes = ~300 bytes (intrinsic)
10,000 trees × ~20 bytes = ~200,000 bytes (extrinsic)
Total = ~200,300 bytes

**Memory saved: ~80%!**

## Related Patterns

From the slides:
- **Composite**: In combination with flyweights, can model directed-acyclic graphs
- **State**: States can be implemented as flyweights
- **Strategy**: Strategies can be implemented as flyweights

## Key Takeaways

1. **Flyweight shares data** between many objects to save memory
2. **Intrinsic state** is shared (stored in flyweight)
3. **Extrinsic state** is unique (passed to flyweight methods)
4. **FlyweightFactory** manages the pool of shared flyweights
5. **Use when** you have many similar objects that share common data

## References

- Gang of Four (GoF), *Design Patterns: Elements of Reusable Object-Oriented Software*
- COS214 Course Slides - University of Pretoria