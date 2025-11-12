#ifndef GRANNY_H
#define GRANNY_H

#include "Caregiver.h"

class Granny : public Caregiver {
public:
    void handleRequest(const std::string& need);
};

#endif
