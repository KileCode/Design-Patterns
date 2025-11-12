#include "GameSettingsMeyers.h"
#include <iostream>

// Initialize static member
int GameSettingsMeyers::instanceCallCount = 0;

/**
 * Private Constructor
 */
GameSettingsMeyers::GameSettingsMeyers() 
    : volumeLevel(50), 
      difficultyLevel(2), 
      fullscreenMode(false),
      playerName("Player1") {
    std::cout << "[GameSettingsMeyers] Constructor called - Instance created\n";
}

/**
 * Private Copy Constructor
 */
GameSettingsMeyers::GameSettingsMeyers(const GameSettingsMeyers& other) {
    std::cout << "[GameSettingsMeyers] ERROR: Copy constructor should never be called!\n";
}

/**
 * Private Assignment Operator
 */
GameSettingsMeyers& GameSettingsMeyers::operator=(const GameSettingsMeyers& other) {
    std::cout << "[GameSettingsMeyers] ERROR: Assignment operator should never be called!\n";
    return *this;
}

/**
 * Private Destructor
 */
GameSettingsMeyers::~GameSettingsMeyers() {
    std::cout << "[GameSettingsMeyers] Destructor called - Instance destroyed\n";
}

/**
 * instance() - Meyers Singleton
 * 
 * From slides: "the Singleton object is created when the instance method
 * is called for the first time"
 * 
 * Magic of static local variables:
 * 1. 'theInstance' is created ONCE on first call
 * 2. Subsequent calls return reference to SAME object
 * 3. Destroyed automatically when program terminates (NO MEMORY LEAK!)
 * 4. Thread-safe initialization guaranteed by C++11 standard
 * 
 * This solves the memory leak problem from the Standard implementation!
 */
GameSettingsMeyers& GameSettingsMeyers::instance() {
    instanceCallCount++;
    
    if (instanceCallCount == 1) {
        std::cout << "[GameSettingsMeyers::instance()] First call - Creating singleton instance\n";
    } else {
        std::cout << "[GameSettingsMeyers::instance()] Returning existing instance\n";
    }
    
    // Static local variable - created on STACK, not HEAP
    // Lives for the entire program duration
    // Automatically destroyed when program ends
    static GameSettingsMeyers theInstance;
    
    return theInstance;
}

/**
 * Get the number of times instance() has been called
 */
int GameSettingsMeyers::getInstanceCallCount() {
    return instanceCallCount;
}

// Getters and Setters implementation
void GameSettingsMeyers::setVolume(int volume) {
    if (volume >= 0 && volume <= 100) {
        volumeLevel = volume;
    }
}

int GameSettingsMeyers::getVolume() const {
    return volumeLevel;
}

void GameSettingsMeyers::setDifficulty(int difficulty) {
    if (difficulty >= 1 && difficulty <= 3) {
        difficultyLevel = difficulty;
    }
}

int GameSettingsMeyers::getDifficulty() const {
    return difficultyLevel;
}

std::string GameSettingsMeyers::getDifficultyString() const {
    switch(difficultyLevel) {
        case 1: return "Easy";
        case 2: return "Medium";
        case 3: return "Hard";
        default: return "Unknown";
    }
}

void GameSettingsMeyers::setFullscreen(bool fullscreen) {
    fullscreenMode = fullscreen;
}

bool GameSettingsMeyers::isFullscreen() const {
    return fullscreenMode;
}

void GameSettingsMeyers::setPlayerName(const std::string& name) {
    playerName = name;
}

std::string GameSettingsMeyers::getPlayerName() const {
    return playerName;
}

void GameSettingsMeyers::displaySettings() const {
    std::cout << "\n=== Game Settings (Meyers) ===" << std::endl;
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Volume: " << volumeLevel << "%" << std::endl;
    std::cout << "Difficulty: " << getDifficultyString() << std::endl;
    std::cout << "Fullscreen: " << (fullscreenMode ? "ON" : "OFF") << std::endl;
    std::cout << "================================\n" << std::endl;
}