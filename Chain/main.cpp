#include <iostream>
#include "Granny.h"
#include "Dad.h"
#include "Mom.h"

int main() {
    // Assemble the chain
    Granny granny;
    Dad dad;
    Mom mom;

    granny.setNext(&dad);
    dad.setNext(&mom);

    std::string need;
    std::cout << "Enter baby's need (love/feed/change): ";
    std::cin >> need;

    granny.handleRequest(need);

    return 0;
}
