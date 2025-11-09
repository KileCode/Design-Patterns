#include "CPU.h"
#include <iostream>

CPU::CPU(std::string cpuModel) : model(cpuModel), running(false) {}

void CPU::freeze() {
    std::cout << "[CPU: " << model << "] Freezing processor..." << std::endl;
    running = false;
}

void CPU::jump(long position) {
    std::cout << "[CPU: " << model << "] Jumping to boot address: 0x" 
              << std::hex << position << std::dec << std::endl;
}

void CPU::execute() {
    std::cout << "[CPU: " << model << "] Executing boot instructions..." << std::endl;
    running = true;
}

void CPU::reset() {
    std::cout << "[CPU: " << model << "] Resetting processor state..." << std::endl;
    running = false;
}

std::string CPU::getStatus() {
    return running ? "RUNNING" : "IDLE";
}