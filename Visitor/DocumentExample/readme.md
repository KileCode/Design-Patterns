# Visitor Design Pattern - Document Processing System

## Pattern Overview
The Visitor pattern separates operations from the objects on which they operate, making it easy to add new operations without modifying the object structure.

## Participants

### Visitor (DocumentProcessor.h)
- **Role**: Abstract interface defining visit operations
- **Responsibility**: Declares a `visit()` method for each ConcreteElement type
- **Key Feature**: Uses method overloading for different element types

### ConcreteVisitor (SpellChecker, WordCounter, Exporter)
- **Role**: Implements specific operations on elements
- **Responsibility**: Provides concrete implementation of each `visit()` method
- **Key Feature**: Can maintain state across visits (e.g., totalWords, errorCount)

### Element (Document.h)
- **Role**: Abstract interface for visitable objects
- **Responsibility**: Declares `accept()` method that takes a Visitor
- **Key Feature**: Allows visitors to access elements through a common interface

### ConcreteElement (PDFDocument, WordDocument, TextDocument)
- **Role**: Specific element types in the object structure
- **Responsibility**: Implements `accept()` method by calling `visitor.visit(this)`
- **Key Feature**: Each class's `accept()` must be implemented separately despite identical code (enables correct static typing for double dispatch)

### Client (main.cpp)
- **Role**: Creates and coordinates visitors and elements
- **Responsibility**: Calls `accept()` on elements, passing desired visitor

## Double Dispatch Mechanism

1. Client calls `element.accept(visitor)`
2. Element's `accept()` calls `visitor.visit(this)` 
3. Correct `visit()` overload executes based on element's runtime type
4. Visitor can call back to element's methods

**Result**: Method execution depends on runtime types of BOTH the visitor and element.

## Benefits
✓ Easy to add new operations (new Visitors) without changing Elements  
✓ Related operations grouped together (high cohesion)  
✓ Operations can maintain state across multiple elements

## Tradeoffs
✗ Hard to add new ConcreteElement types (all Visitors must be updated)  
✗ May break encapsulation (visitors need access to element internals)

## Build & Run
```bash
make          # Compile
./document_processor  # Run
make clean    # Clean build files
```