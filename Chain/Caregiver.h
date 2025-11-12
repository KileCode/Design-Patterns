#ifndef CAREGIVER_H
#define CAREGIVER_H

#include <string>
#include <iostream>

class Caregiver {
protected:
    Caregiver* next;
public:
    Caregiver() : next(nullptr) {}
    virtual ~Caregiver() {}

    void setNext(Caregiver* n) {
        next = n;
    }

    virtual void handleRequest(const std::string& need) {
        if (next)
            next->handleRequest(need);
        else
            std::cout << "No one can handle the baby's need for \"" 
                      << need << "\"." << std::endl;
    }
};

#endif
