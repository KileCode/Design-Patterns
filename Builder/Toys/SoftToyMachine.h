#ifndef SOFTTOYMACHINE_H
#define SOFTTOYMACHINE_H

#include <string>

class SoftToyMachine {
public:
    virtual ~SoftToyMachine() {}
    
    // Pure virtual methods - must be implemented
    virtual void selectBody() = 0;
    virtual void stuff() = 0;
    
    // Virtual methods with default empty implementations
    virtual void insertHeart() {}
    virtual void addVoice() {}
    virtual void setName(std::string name) {}
};

#endif