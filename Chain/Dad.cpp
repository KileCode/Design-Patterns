#include "Dad.h"

void Dad::handleRequest(const std::string& need) {
    if (need == "feed") {
        std::cout << "Dad feeds the baby with a bottle." << std::endl;
    } else {
        std::cout << "Dad can't help with \"" << need 
                  << "\", passing it on..." << std::endl;
        Caregiver::handleRequest(need);
    }
}
