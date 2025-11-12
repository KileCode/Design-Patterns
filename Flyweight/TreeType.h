#ifndef TREETYPE_H
#define TREETYPE_H

#include <string>

/**
 * TreeType - Flyweight
 * Defines the interface through which flyweights are instantiated
 */
class TreeType {
protected:
    std::string name;
    std::string color;
    std::string texture;

public:
    TreeType();
    TreeType(std::string n, std::string c, std::string t);
    virtual ~TreeType();
    
    virtual void render(int x, int y, int scale) const = 0;
    virtual std::string getType() const = 0;
    
    std::string getName() const;
    std::string getColor() const;
    std::string getTexture() const;
};

#endif