#ifndef PLAINGIRAFFE_H
#define PLAINGIRAFFE_H

#include <string>

class PlainGiraffe {
private:
    std::string name;
    std::string colour;
    double weight;
    double height;

public:
    PlainGiraffe();
    void setName(std::string n);
    void selectSkin(std::string c);
    void setWeight(double w);
    void setHeight(double h);
    void describe();
};

#endif