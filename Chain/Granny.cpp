#include "Granny.h"

void Granny::handleRequest(const std::string& need) {
    if (need == "love") {
        std::cout << "Granny cuddles and loves the baby." << std::endl;
    } else {
        std::cout << "Granny can't help with \"" << need 
                  << "\", passing it on..." << std::endl;
        Caregiver::handleRequest(need);
    }
}
