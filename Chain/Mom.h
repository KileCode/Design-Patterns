#ifndef MOM_H
#define MOM_H

#include "Caregiver.h"

class Mom : public Caregiver {
public:
    void handleRequest(const std::string& need);
};

#endif
