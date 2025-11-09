#ifndef MEMORY_H
#define MEMORY_H

#include <string>

// Subsystem class: Handles RAM operations
class Memory {
private:
    int sizeGB;
    long bootAddress;
    std::string* data;
    
public:
    Memory(int size);
    ~Memory();
    void load(long position, std::string bootData);
    void clear();
    void performSelfTest();
    int getSize();
};

#endif