#ifndef DAD_H
#define DAD_H

#include "Caregiver.h"

class Dad : public Caregiver {
public:
    void handleRequest(const std::string& need);
};

#endif
