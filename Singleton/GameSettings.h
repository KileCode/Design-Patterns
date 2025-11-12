#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <string>

/**
 * GameSettings - Singleton Pattern (Standard/Muldner Implementation)
 * 
 * This class ensures only ONE instance of game settings exists throughout
 * the application, providing a global point of access to configuration.
 * 
 * Structure matches the slides exactly:
 * - Static instance pointer and operations are private
 * - Constructor, Copy Constructor, Assignment Operator are protected
 * - Destructor is protected (to allow potential inheritance)
 * - Public interface provides the instance() method and operations
 */
class GameSettings {
private:
    // The single instance (initialized in .cpp file)
    static GameSettings* onlyInstance;
    
    // Counter to track how many times instance() has been called
    static int instanceCallCount;

protected:
    /**
     * PROTECTED Constructor - prevents direct instantiation
     * Can only be called from within the class (by instance() method)
     * 
     * Question from slides: "What are the implications of private vs protected?"
     * Answer: PROTECTED allows inheritance - derived classes can be created,
     * but this requires careful design to maintain singleton guarantee!
     */
    GameSettings();
    
    /**
     * PROTECTED Copy Constructor - prevents copying
     */
    GameSettings(const GameSettings& other);
    
    /**
     * PROTECTED Assignment Operator - prevents assignment
     */
    GameSettings& operator=(const GameSettings& other);
    
    /**
     * PROTECTED Destructor
     * Protected allows inheritance, but be careful - derived classes
     * could potentially break the singleton guarantee
     */
    ~GameSettings();
    
    // Protected member variables (game settings data)
    int volumeLevel;
    int difficultyLevel;  // 1=Easy, 2=Medium, 3=Hard
    bool fullscreenMode;
    std::string playerName;

public:
    /**
     * instance() - The ONLY way to get access to the GameSettings object
     * 
     * This method:
     * 1. Creates the instance on first call (lazy initialization)
     * 2. Returns the same instance on subsequent calls
     * 3. Tracks how many times it's been called
     * 
     * Note: This creates the object on the HEAP (using new)
     * Memory Leak Warning: onlyInstance is never deleted!
     */
    static GameSettings* instance();
    
    /**
     * Get the number of times instance() has been called
     * Addresses slide question: "Do I know how many calls to Singleton instance have been made?"
     */
    static int getInstanceCallCount();
    
    // Public interface for game settings operations
    void setVolume(int volume);
    int getVolume() const;
    
    void setDifficulty(int difficulty);
    int getDifficulty() const;
    std::string getDifficultyString() const;
    
    void setFullscreen(bool fullscreen);
    bool isFullscreen() const;
    
    void setPlayerName(const std::string& name);
    std::string getPlayerName() const;
    
    // Display current settings
    void displaySettings() const;
};

#endif // GAMESETTINGS_H