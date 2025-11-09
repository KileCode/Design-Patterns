#include "ComputerFacade.h"
#include <iostream>

ComputerFacade::ComputerFacade() {
    // Initialize all subsystem components
    cpu = new CPU("Intel Core i7");
    memory = new Memory(16);  // 16GB RAM
    hardDrive = new HardDrive(1, "Linux Ubuntu");  // 1TB drive
    bios = new BIOS("AMI BIOS v2.4");
}

ComputerFacade::~ComputerFacade() {
    delete cpu;
    delete memory;
    delete hardDrive;
    delete bios;
}

void ComputerFacade::start() {
    std::cout << "\n=== STARTING COMPUTER ===" << std::endl;
    std::cout << "\nPress power button...\n" << std::endl;
    
    // Step 1: BIOS initialization (delegates to BIOS subsystem)
    bios->displaySplashScreen();
    bios->beep(1);  // Single beep indicates successful POST
    bios->powerOnSelfTest();
    
    // Step 2: Memory check (delegates to Memory subsystem)
    memory->performSelfTest();
    
    // Step 3: BIOS hardware initialization
    bios->initializeHardware();
    
    // Step 4: CPU initialization (delegates to CPU subsystem)
    cpu->freeze();
    
    // Step 5: Hard drive operations (delegates to HardDrive subsystem)
    hardDrive->spinUp();
    hardDrive->seek(BOOT_SECTOR);
    
    // Step 6: Load boot sector from hard drive to memory
    std::string bootData = hardDrive->read(BOOT_SECTOR, SECTOR_SIZE);
    memory->load(BOOT_ADDRESS, bootData);
    
    // Step 7: BIOS loads boot loader
    bios->loadBootLoader();
    
    // Step 8: CPU executes boot instructions
    cpu->jump(BOOT_ADDRESS);
    cpu->execute();
    
    std::cout << "\n[SYSTEM] " << hardDrive->getOSName() 
              << " is booting..." << std::endl;
    std::cout << "[SYSTEM] Boot sequence complete!" << std::endl;
    std::cout << "[SYSTEM] Computer is ready to use.\n" << std::endl;
}

void ComputerFacade::shutdown() {
    std::cout << "\n=== SHUTTING DOWN COMPUTER ===" << std::endl;
    std::cout << "\nInitiating shutdown sequence...\n" << std::endl;
    
    // Reverse order shutdown
    std::cout << "[SYSTEM] Closing " << hardDrive->getOSName() << "..." << std::endl;
    
    cpu->reset();
    memory->clear();
    hardDrive->spinDown();
    
    std::cout << "\n[SYSTEM] Shutdown complete. Safe to power off.\n" << std::endl;
}

// Optional accessor methods for direct subsystem access
CPU* ComputerFacade::getCPU() {
    return cpu;
}

Memory* ComputerFacade::getMemory() {
    return memory;
}

HardDrive* ComputerFacade::getHardDrive() {
    return hardDrive;
}

BIOS* ComputerFacade::getBIOS() {
    return bios;
}