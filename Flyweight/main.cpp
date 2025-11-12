#include <iostream>
#include "Forest.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "  Flyweight Pattern Demonstration\n";
    std::cout << "  Forest Renderer\n";
    std::cout << "========================================\n\n";
    
    Forest* forest = new Forest();
    
    std::cout << "=== Planting Trees ===\n" << std::endl;
    
    forest->plantTree(10, 20, 100, "Oak");
    forest->plantTree(50, 30, 90, "Pine");
    forest->plantTree(80, 40, 110, "Oak");
    forest->plantTree(120, 50, 95, "Birch");
    forest->plantTree(150, 60, 100, "Pine");
    forest->plantTree(200, 70, 105, "Oak");
    forest->plantTree(250, 80, 90, "Birch");
    forest->plantTree(300, 90, 100, "Pine");
    forest->plantTree(350, 100, 95, "Oak");
    forest->plantTree(400, 110, 100, "Birch");
    
    std::cout << "\n=== Forest Statistics ===" << std::endl;
    std::cout << "Total trees planted: " << forest->getTreeCount() << std::endl;
    std::cout << "Unique tree types (flyweights): " << forest->getTreeTypeCount() << std::endl;
    std::cout << "==========================\n" << std::endl;
    
    forest->render();
    
    forest->displayMemoryUsage();
    
    std::cout << "=== Demonstrating Flyweight Sharing ===\n" << std::endl;
    std::cout << "Notice how the factory returns existing flyweights:" << std::endl;
    std::cout << "- First Oak created a new flyweight" << std::endl;
    std::cout << "- Subsequent Oaks reused the same flyweight" << std::endl;
    std::cout << "- Same for Pine and Birch types\n" << std::endl;
    
    std::cout << "=== Key Concepts ===\n" << std::endl;
    std::cout << "INTRINSIC STATE (shared, stored in flyweight):" << std::endl;
    std::cout << "  - Tree type name (Oak, Pine, Birch)" << std::endl;
    std::cout << "  - Color" << std::endl;
    std::cout << "  - Texture file path" << std::endl;
    std::cout << "\nEXTRINSIC STATE (unique per tree, stored in context):" << std::endl;
    std::cout << "  - X position" << std::endl;
    std::cout << "  - Y position" << std::endl;
    std::cout << "  - Scale" << std::endl;
    std::cout << "\nThis allows us to render thousands of trees efficiently!" << std::endl;
    std::cout << "====================\n" << std::endl;
    
    std::cout << "\n=== Creating a Larger Forest ===\n" << std::endl;
    Forest* bigForest = new Forest();
    
    for (int i = 0; i < 1000; i++) {
        int x = (i * 37) % 1000;
        int y = (i * 53) % 800;
        int scale = 90 + (i % 20);
        
        std::string type;
        if (i % 3 == 0) type = "Oak";
        else if (i % 3 == 1) type = "Pine";
        else type = "Birch";
        
        bigForest->plantTree(x, y, scale, type);
    }
    
    std::cout << "\nLarge forest created with " << bigForest->getTreeCount() << " trees!" << std::endl;
    std::cout << "But only " << bigForest->getTreeTypeCount() << " tree type objects (flyweights) in memory." << std::endl;
    
    bigForest->displayMemoryUsage();
    
    delete forest;
    delete bigForest;
    
    return 0;
}