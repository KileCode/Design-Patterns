#include "GameSettings.h"
#include <iostream>

// Initialize static members
// Question from slides: "Where is the instance variable onlyInstance initialized?"
// Answer: RIGHT HERE - in the .cpp file, outside any function
GameSettings* GameSettings::onlyInstance = nullptr;
int GameSettings::instanceCallCount = 0;

/**
 * Private Constructor - sets default game settings
 */
GameSettings::GameSettings() 
    : volumeLevel(50), 
      difficultyLevel(2), 
      fullscreenMode(false),
      playerName("Player1") {
    std::cout << "[GameSettings] Constructor called - Instance created\n";
}

/**
 * Private Copy Constructor - should never be called
 */
GameSettings::GameSettings(const GameSettings& other) {
    std::cout << "[GameSettings] ERROR: Copy constructor should never be called!\n";
}

/**
 * Private Assignment Operator - should never be called
 */
GameSettings& GameSettings::operator=(const GameSettings& other) {
    std::cout << "[GameSettings] ERROR: Assignment operator should never be called!\n";
    return *this;
}

/**
 * Private Destructor
 */
GameSettings::~GameSettings() {
    std::cout << "[GameSettings] Destructor called - Instance destroyed\n";
}

/**
 * instance() - The Singleton access point
 * 
 * Standard/Muldner Implementation:
 * - Creates instance on HEAP using new
 * - Lazy initialization (created on first call)
 * - WARNING: Memory leak! onlyInstance is never deleted
 * 
 * Question from slides: "What about the memory leak?"
 * Answer: In this implementation, we allocate memory with 'new' but never 'delete' it.
 * The memory is only freed when the program terminates.
 * The Meyers implementation solves this!
 */
GameSettings* GameSettings::instance() {
    instanceCallCount++;
    
    if (onlyInstance == nullptr) {
        std::cout << "[GameSettings::instance()] First call - Creating singleton instance\n";
        onlyInstance = new GameSettings();  // Allocated on HEAP
    } else {
        std::cout << "[GameSettings::instance()] Returning existing instance\n";
    }
    
    return onlyInstance;
}

/**
 * Get the number of times instance() has been called
 */
int GameSettings::getInstanceCallCount() {
    return instanceCallCount;
}

// Getters and Setters implementation
void GameSettings::setVolume(int volume) {
    if (volume >= 0 && volume <= 100) {
        volumeLevel = volume;
    }
}

int GameSettings::getVolume() const {
    return volumeLevel;
}

void GameSettings::setDifficulty(int difficulty) {
    if (difficulty >= 1 && difficulty <= 3) {
        difficultyLevel = difficulty;
    }
}

int GameSettings::getDifficulty() const {
    return difficultyLevel;
}

std::string GameSettings::getDifficultyString() const {
    switch(difficultyLevel) {
        case 1: return "Easy";
        case 2: return "Medium";
        case 3: return "Hard";
        default: return "Unknown";
    }
}

void GameSettings::setFullscreen(bool fullscreen) {
    fullscreenMode = fullscreen;
}

bool GameSettings::isFullscreen() const {
    return fullscreenMode;
}

void GameSettings::setPlayerName(const std::string& name) {
    playerName = name;
}

std::string GameSettings::getPlayerName() const {
    return playerName;
}

void GameSettings::displaySettings() const {
    std::cout << "\n=== Game Settings ===" << std::endl;
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Volume: " << volumeLevel << "%" << std::endl;
    std::cout << "Difficulty: " << getDifficultyString() << std::endl;
    std::cout << "Fullscreen: " << (fullscreenMode ? "ON" : "OFF") << std::endl;
    std::cout << "=====================\n" << std::endl;
}