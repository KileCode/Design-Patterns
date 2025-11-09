# Facade Design Pattern - Computer Startup Example

## Overview

This project demonstrates the **Facade Design Pattern** using a computer startup system as an example. The pattern provides a simplified interface to a complex subsystem, making it easier for clients to interact with the system.

## What is the Facade Pattern?

The Facade pattern:
- Provides a unified, simplified interface to a set of interfaces in a subsystem
- Makes the subsystem easier to use by hiding its complexity
- Doesn't prevent direct access to subsystem classes when needed
- Reduces coupling between clients and subsystems

## Project Structure

```
.
├── README.md
├── Makefile
├── main.cpp                  # Client code demonstrating the pattern
├── ComputerFacade.h          # Facade class header
├── ComputerFacade.cpp        # Facade class implementation
├── CPU.h                     # CPU subsystem header
├── CPU.cpp                   # CPU subsystem implementation
├── Memory.h                  # Memory subsystem header
├── Memory.cpp                # Memory subsystem implementation
├── HardDrive.h               # HardDrive subsystem header
├── HardDrive.cpp             # HardDrive subsystem implementation
├── BIOS.h                    # BIOS subsystem header
└── BIOS.cpp                  # BIOS subsystem implementation
```

## How It Works

### Without Facade (Complex)
Without the facade, a client would need to:
1. Create CPU, Memory, HardDrive, and BIOS objects
2. Call BIOS POST and hardware initialization
3. Perform memory self-tests
4. Initialize and freeze the CPU
5. Spin up hard drive and seek boot sector
6. Read boot sector data
7. Load boot data into memory at specific address
8. Jump CPU to boot address
9. Execute boot instructions

### With Facade (Simple)
With the facade, the client simply calls:
```cpp
ComputerFacade computer;
computer.start();    // All complexity hidden!
computer.shutdown(); // Easy shutdown too!
```

## Building the Project

### Compile
```bash
make
```

### Run
```bash
./computer_startup
```

### Clean
```bash
make clean
```

### Rebuild
```bash
make rebuild
```

## Key Components

### Facade Class: `ComputerFacade`
- **Purpose**: Simplifies the computer startup process
- **Methods**:
  - `start()` - Orchestrates the entire boot sequence
  - `shutdown()` - Handles shutdown process
  - `getCPU()`, `getMemory()`, etc. - Optional direct subsystem access

### Subsystem Classes

#### `CPU`
- Handles processor operations
- Methods: `freeze()`, `jump()`, `execute()`, `reset()`, `getStatus()`

#### `Memory`
- Handles RAM operations
- Methods: `load()`, `clear()`, `performSelfTest()`, `getSize()`

#### `HardDrive`
- Handles storage operations
- Methods: `read()`, `spinUp()`, `spinDown()`, `seek()`, `getOSName()`

#### `BIOS`
- Handles firmware operations
- Methods: `powerOnSelfTest()`, `initializeHardware()`, `loadBootLoader()`, `displaySplashScreen()`, `beep()`, `getVersion()`

## Design Principles Demonstrated

1. **Simplified Interface**: Complex multi-step process reduced to single method call
2. **Subsystem Independence**: All subsystems work independently without knowledge of the facade
3. **Delegation**: Facade delegates work to appropriate subsystems
4. **Optional Direct Access**: Clients can still access subsystems directly if needed
5. **Reduced Coupling**: Clients depend on facade, not multiple subsystems

## Example Output

```
=== STARTING COMPUTER ===

Press power button...

========================================
      COMPUTER BOOT SEQUENCE
      BIOS Version: AMI BIOS v2.4
========================================

[BIOS: AMI BIOS v2.4] *BEEP*
[BIOS: AMI BIOS v2.4] Starting Power-On Self-Test (POST)...
[Memory: 16GB] Running POST (Power-On Self-Test)...
[Memory: 16GB] Memory test PASSED
...
[SYSTEM] Linux Ubuntu is booting...
[SYSTEM] Boot sequence complete!
[SYSTEM] Computer is ready to use.
```

## Learning Points

- The facade pattern is ideal when you have a complex subsystem with many interdependent classes
- It provides a high-level interface that makes the subsystem easier to use
- It doesn't restrict access to low-level subsystem functionality when needed
- It promotes loose coupling between clients and subsystems
- It's commonly used in libraries, frameworks, and API design

## Requirements

- C++ compiler with C++11 support (g++, clang++)
- Make utility

## Author

Based on the Facade Design Pattern as described in "Design Patterns: Elements of Reusable Object-Oriented Software" by Gamma, Helm, Johnson, and Vlissides.