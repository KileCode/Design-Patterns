#include "CuddlyBear.h"
#include <iostream>

CuddlyBear::CuddlyBear() {}

void CuddlyBear::setPart(std::string partName, std::string partValue) {
    part[partName] = partValue;
}

void CuddlyBear::show() {
    std::cout << "Cuddly Bear:" << std::endl;
    for (std::map<std::string, std::string>::iterator it = part.begin(); 
         it != part.end(); ++it) {
        std::cout << "  " << it->first << ": " << it->second << std::endl;
    }
}