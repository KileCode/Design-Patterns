#include "Mom.h"

void Mom::handleRequest(const std::string& need) {
    if (need == "change") {
        std::cout << "Mom changes the baby's diaper." << std::endl;
    } else {
        std::cout << "Mom can't help with \"" << need 
                  << "\". The baby keeps crying..." << std::endl;
        Caregiver::handleRequest(need);
    }
}
