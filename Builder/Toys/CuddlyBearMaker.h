#ifndef CUDDLYBEARMAKER_H
#define CUDDLYBEARMAKER_H

#include "SoftToyMachine.h"
#include "CuddlyBear.h"

class CuddlyBearMaker : public SoftToyMachine {
private:
    CuddlyBear* bear;

public:
    CuddlyBearMaker();
    ~CuddlyBearMaker();
    
    void selectBody();
    void stuff();
    void insertHeart();
    void addVoice();
    void setName(std::string name);
    
    CuddlyBear* getBear();
};

#endif