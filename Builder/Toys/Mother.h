#ifndef MOTHER_H
#define MOTHER_H

#include "SoftToyMachine.h"

class Mother {
private:
    SoftToyMachine* machine;

public:
    Mother();
    void setMachine(SoftToyMachine* m);
    void construct();
};

#endif