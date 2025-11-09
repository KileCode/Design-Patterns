#include <iostream>
#include "Mother.h"
#include "Shop.h"
#include "PlainGiraffeMaker.h"
#include "CuddlyBearMaker.h"
#include "PlainGiraffe.h"
#include "CuddlyBear.h"

int main() {
    std::cout << "=== Builder Pattern Example ===" << std::endl << std::endl;
    
    // Create concrete builders
    PlainGiraffeMaker giraffeMaker;
    CuddlyBearMaker bearMaker1;
    CuddlyBearMaker bearMaker2;
    
    // Example 1: Mother creates a giraffe
    std::cout << "Example 1: Mother creates a giraffe" << std::endl;
    Mother mother;
    mother.setMachine(&giraffeMaker);
    mother.construct();
    PlainGiraffe giraffe1 = giraffeMaker.getGiraffe();
    giraffe1.describe();
    std::cout << std::endl;
    
    // Example 2: Shop creates a bear
    std::cout << "Example 2: Shop creates a bear" << std::endl;
    Shop shop1(&bearMaker1, "Teddy");
    shop1.construct();
    CuddlyBear* bear1 = bearMaker1.getBear();
    bear1->show();
    std::cout << std::endl;
    
    // Example 3: Mother creates a bear (reusing giraffeMaker for another giraffe first)
    std::cout << "Example 3: Mother creates another giraffe" << std::endl;
    mother.setMachine(&giraffeMaker);
    mother.construct();
    PlainGiraffe giraffe2 = giraffeMaker.getGiraffe();
    giraffe2.describe();
    std::cout << std::endl;
    
    // Example 4: Shop creates another bear with different name
    std::cout << "Example 4: Shop creates another bear" << std::endl;
    Shop shop2(&bearMaker2, "Cuddles");
    shop2.construct();
    CuddlyBear* bear2 = bearMaker2.getBear();
    bear2->show();
    std::cout << std::endl;
    
    // Example 5: Mother creates a bear (demonstrating different construction)
    std::cout << "Example 5: Mother creates a bear (simpler construction)" << std::endl;
    CuddlyBearMaker bearMaker3;
    mother.setMachine(&bearMaker3);
    mother.construct();
    CuddlyBear* bear3 = bearMaker3.getBear();
    bear3->show();
    std::cout << std::endl;
    
    std::cout << "Notice how the same builders create different products" << std::endl;
    std::cout << "when used by different directors!" << std::endl;
    
    return 0;
}