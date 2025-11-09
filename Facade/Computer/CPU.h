#ifndef CPU_H
#define CPU_H

#include <string>

// Subsystem class: Handles CPU operations
class CPU {
private:
    std::string model;
    bool running;
    
public:
    CPU(std::string cpuModel);
    void freeze();
    void jump(long position);
    void execute();
    void reset();
    std::string getStatus();
};

#endif