#ifndef HARDDRIVE_H
#define HARDDRIVE_H

#include <string>

// Subsystem class: Handles hard drive operations
class HardDrive {
private:
    int capacityTB;
    std::string osName;
    
public:
    HardDrive(int capacity, std::string operatingSystem);
    std::string read(long lba, int size);
    void spinUp();
    void spinDown();
    void seek(long sector);
    std::string getOSName();
};

#endif