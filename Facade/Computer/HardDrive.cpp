#include "HardDrive.h"
#include <iostream>

HardDrive::HardDrive(int capacity, std::string operatingSystem) 
    : capacityTB(capacity), osName(operatingSystem) {}

std::string HardDrive::read(long lba, int size) {
    std::cout << "[HardDrive: " << capacityTB << "TB] Reading " << size 
              << " bytes from LBA: " << lba << std::endl;
    return "BOOT_SECTOR_DATA";
}

void HardDrive::spinUp() {
    std::cout << "[HardDrive: " << capacityTB << "TB] Spinning up disk platters..." << std::endl;
}

void HardDrive::spinDown() {
    std::cout << "[HardDrive: " << capacityTB << "TB] Spinning down..." << std::endl;
}

void HardDrive::seek(long sector) {
    std::cout << "[HardDrive: " << capacityTB << "TB] Seeking to boot sector " 
              << sector << std::endl;
}

std::string HardDrive::getOSName() {
    return osName;
}