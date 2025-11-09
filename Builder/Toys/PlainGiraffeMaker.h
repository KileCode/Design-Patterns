#ifndef PLAINGIRAFFE_MAKER_H
#define PLAINGIRAFFE_MAKER_H

#include "SoftToyMachine.h"
#include "PlainGiraffe.h"

class PlainGiraffeMaker : public SoftToyMachine {
private:
    PlainGiraffe* giraffe;

public:
    PlainGiraffeMaker();
    ~PlainGiraffeMaker();
    
    void selectBody();
    void stuff();
    void setName(std::string name);
    
    PlainGiraffe getGiraffe();
};

#endif