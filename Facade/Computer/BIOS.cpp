#include "BIOS.h"
#include <iostream>

BIOS::BIOS(std::string biosVersion) : version(biosVersion), initialized(false) {}

void BIOS::powerOnSelfTest() {
    std::cout << "[BIOS: " << version << "] Starting Power-On Self-Test (POST)..." << std::endl;
    std::cout << "[BIOS: " << version << "] Testing system components..." << std::endl;
}

void BIOS::initializeHardware() {
    std::cout << "[BIOS: " << version << "] Initializing hardware components..." << std::endl;
    std::cout << "[BIOS: " << version << "] Detecting storage devices..." << std::endl;
    initialized = true;
}

void BIOS::loadBootLoader() {
    std::cout << "[BIOS: " << version << "] Searching for boot device..." << std::endl;
    std::cout << "[BIOS: " << version << "] Loading boot loader..." << std::endl;
}

void BIOS::displaySplashScreen() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "      COMPUTER BOOT SEQUENCE\n";
    std::cout << "      BIOS Version: " << version << "\n";
    std::cout << "========================================\n";
    std::cout << std::endl;
}

void BIOS::beep(int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "[BIOS: " << version << "] *BEEP*" << std::endl;
    }
}

std::string BIOS::getVersion() {
    return version;
}