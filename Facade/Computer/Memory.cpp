#include "Memory.h"
#include <iostream>

Memory::Memory(int size) : sizeGB(size), bootAddress(0), data(nullptr) {
    data = new std::string("");
}

Memory::~Memory() {
    delete data;
}

void Memory::load(long position, std::string bootData) {
    bootAddress = position;
    *data = bootData;
    std::cout << "[Memory: " << sizeGB << "GB] Loading boot sector from address 0x" 
              << std::hex << position << std::dec << std::endl;
    std::cout << "[Memory: " << sizeGB << "GB] Boot data loaded into RAM" << std::endl;
}

void Memory::clear() {
    std::cout << "[Memory: " << sizeGB << "GB] Clearing memory..." << std::endl;
    *data = "";
    bootAddress = 0;
}

void Memory::performSelfTest() {
    std::cout << "[Memory: " << sizeGB << "GB] Running POST (Power-On Self-Test)..." << std::endl;
    std::cout << "[Memory: " << sizeGB << "GB] Memory test PASSED" << std::endl;
}

int Memory::getSize() {
    return sizeGB;
}