#ifndef CUDDLYBEAR_H
#define CUDDLYBEAR_H

#include <string>
#include <map>

class CuddlyBear {
private:
    std::map<std::string, std::string> part;

public:
    CuddlyBear();
    void setPart(std::string partName, std::string partValue);
    void show();
};

#endif