#ifndef COMPUTERFACADE_H
#define COMPUTERFACADE_H

#include "CPU.h"
#include "Memory.h"
#include "HardDrive.h"
#include "BIOS.h"

// Facade class: Provides simplified interface to complex computer startup
// This follows the Facade Design Pattern structure from the document
class ComputerFacade {
private:
    // The facade knows which subsystem classes are responsible for a request
    CPU* cpu;
    Memory* memory;
    HardDrive* hardDrive;
    BIOS* bios;
    
    // Boot address constant
    static const long BOOT_ADDRESS = 0x7C00;
    static const int BOOT_SECTOR = 0;
    static const int SECTOR_SIZE = 512;
    
public:
    ComputerFacade();
    ~ComputerFacade();
    
    // Simplified interface methods
    // The facade delegates client requests to appropriate subsystem objects
    void start();
    void shutdown();
    
    // Optional: Allow direct access to subsystems if needed
    // (Following the pattern's principle of not preventing subsystem access)
    CPU* getCPU();
    Memory* getMemory();
    HardDrive* getHardDrive();
    BIOS* getBIOS();
};

#endif