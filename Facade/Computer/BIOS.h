#ifndef BIOS_H
#define BIOS_H

#include <string>

// Subsystem class: Handles BIOS operations
class BIOS {
private:
    std::string version;
    bool initialized;
    
public:
    BIOS(std::string biosVersion);
    void powerOnSelfTest();
    void initializeHardware();
    void loadBootLoader();
    void displaySplashScreen();
    void beep(int count);
    std::string getVersion();
};

#endif