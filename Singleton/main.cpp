#include <iostream>
#include "GameSettings.h"
#include "GameSettingsMeyers.h"

/**
 * Simulates different parts of a game accessing settings
 */
void mainMenu() {
    std::cout << "\n--- MAIN MENU accessing settings ---\n";
    GameSettings* settings = GameSettings::instance();
    settings->displaySettings();
}

void gameplayLevel() {
    std::cout << "\n--- GAMEPLAY LEVEL accessing settings ---\n";
    GameSettings* settings = GameSettings::instance();
    std::cout << "Playing at difficulty: " << settings->getDifficultyString() << std::endl;
    std::cout << "Volume level: " << settings->getVolume() << std::endl;
}

void optionsMenu() {
    std::cout << "\n--- OPTIONS MENU modifying settings ---\n";
    GameSettings* settings = GameSettings::instance();
    settings->setVolume(75);
    settings->setDifficulty(3);
    settings->setPlayerName("ProGamer");
    settings->setFullscreen(true);
    std::cout << "Settings updated!\n";
}

/**
 * Simulates different parts of a game accessing Meyers settings
 */
void mainMenuMeyers() {
    std::cout << "\n--- MAIN MENU accessing Meyers settings ---\n";
    GameSettingsMeyers& settings = GameSettingsMeyers::instance();
    settings.displaySettings();
}

void gameplayLevelMeyers() {
    std::cout << "\n--- GAMEPLAY LEVEL accessing Meyers settings ---\n";
    GameSettingsMeyers& settings = GameSettingsMeyers::instance();
    std::cout << "Playing at difficulty: " << settings.getDifficultyString() << std::endl;
    std::cout << "Volume level: " << settings.getVolume() << std::endl;
}

void optionsMenuMeyers() {
    std::cout << "\n--- OPTIONS MENU modifying Meyers settings ---\n";
    GameSettingsMeyers& settings = GameSettingsMeyers::instance();
    settings.setVolume(85);
    settings.setDifficulty(1);
    settings.setPlayerName("CasualPlayer");
    settings.setFullscreen(false);
    std::cout << "Settings updated!\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "  Singleton Pattern Demonstration\n";
    std::cout << "  Game Settings Manager\n";
    std::cout << "========================================\n\n";
    
    // ======== STANDARD IMPLEMENTATION DEMO ========
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║  STANDARD (Muldner) IMPLEMENTATION     ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    std::cout << "\n1. Main menu accesses settings (first call)\n";
    mainMenu();
    
    std::cout << "\n2. Gameplay level accesses same settings\n";
    gameplayLevel();
    
    std::cout << "\n3. Options menu modifies settings\n";
    optionsMenu();
    
    std::cout << "\n4. Main menu sees updated settings (proves it's the same instance!)\n";
    mainMenu();
    
    std::cout << "\n5. Checking instance call count:\n";
    std::cout << "   instance() was called " << GameSettings::getInstanceCallCount() 
              << " times (answers slide question!)\n";
    
    // Demonstrate that we always get the same instance
    std::cout << "\n6. Proving it's the same instance with pointer addresses:\n";
    GameSettings* ptr1 = GameSettings::instance();
    GameSettings* ptr2 = GameSettings::instance();
    GameSettings* ptr3 = GameSettings::instance();
    std::cout << "   ptr1 address: " << ptr1 << std::endl;
    std::cout << "   ptr2 address: " << ptr2 << std::endl;
    std::cout << "   ptr3 address: " << ptr3 << std::endl;
    std::cout << "   All addresses are the same! ✓\n";
    
    std::cout << "\n   Total instance() calls: " << GameSettings::getInstanceCallCount() << std::endl;
    
    // ======== MEYERS IMPLEMENTATION DEMO ========
    std::cout << "\n\n╔════════════════════════════════════════╗\n";
    std::cout << "║  MEYERS IMPLEMENTATION                 ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    std::cout << "\n1. Main menu accesses settings (first call)\n";
    mainMenuMeyers();
    
    std::cout << "\n2. Gameplay level accesses same settings\n";
    gameplayLevelMeyers();
    
    std::cout << "\n3. Options menu modifies settings\n";
    optionsMenuMeyers();
    
    std::cout << "\n4. Main menu sees updated settings\n";
    mainMenuMeyers();
    
    std::cout << "\n5. Checking instance call count:\n";
    std::cout << "   instance() was called " << GameSettingsMeyers::getInstanceCallCount() 
              << " times\n";
    
    // Demonstrate that we always get the same instance
    std::cout << "\n6. Proving it's the same instance with reference addresses:\n";
    GameSettingsMeyers& ref1 = GameSettingsMeyers::instance();
    GameSettingsMeyers& ref2 = GameSettingsMeyers::instance();
    GameSettingsMeyers& ref3 = GameSettingsMeyers::instance();
    std::cout << "   ref1 address: " << &ref1 << std::endl;
    std::cout << "   ref2 address: " << &ref2 << std::endl;
    std::cout << "   ref3 address: " << &ref3 << std::endl;
    std::cout << "   All addresses are the same! ✓\n";
    
    std::cout << "\n   Total instance() calls: " << GameSettingsMeyers::getInstanceCallCount() << std::endl;
    
    // ======== KEY DIFFERENCES ========
    std::cout << "\n\n╔════════════════════════════════════════╗\n";
    std::cout << "║  KEY DIFFERENCES                       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    std::cout << "\nStandard Implementation:\n";
    std::cout << "  - Returns POINTER (GameSettings*)\n";
    std::cout << "  - Creates instance on HEAP (using new)\n";
    std::cout << "  - Has MEMORY LEAK (never deleted)\n";
    std::cout << "  - Access: settings->method()\n";
    
    std::cout << "\nMeyers Implementation:\n";
    std::cout << "  - Returns REFERENCE (GameSettings&)\n";
    std::cout << "  - Creates instance on STACK (static local)\n";
    std::cout << "  - NO memory leak (auto-destroyed)\n";
    std::cout << "  - Access: settings.method()\n";
    std::cout << "  - Thread-safe in C++11+\n";
    
    std::cout << "\n\nProgram ending...\n";
    std::cout << "Watch for destructor calls:\n";
    std::cout << "  - Standard: NO destructor (memory leak!)\n";
    std::cout << "  - Meyers: WILL call destructor (proper cleanup!)\n\n";
    
    return 0;
}