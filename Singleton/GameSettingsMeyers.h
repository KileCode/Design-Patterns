#ifndef GAMESETTINGSMEYERS_H
#define GAMESETTINGSMEYERS_H

#include <string>

/**
 * GameSettingsMeyers - Singleton Pattern (Meyers Implementation)
 * 
 * This implementation addresses the memory leak in the Standard implementation!
 * 
 * Structure matches the slides exactly:
 * - Constructor, Copy Constructor, Assignment Operator are protected
 * - Destructor is protected (to allow potential inheritance)
 * - Member variables are protected
 * - Public interface provides the instance() method and operations
 * 
 * Key Differences from Standard Implementation:
 * - Returns a REFERENCE instead of a pointer
 * - Creates instance on the STACK (not heap) inside instance() method
 * - Instance is automatically destroyed when program ends (no memory leak!)
 * - Uses static local variable instead of static member variable
 * 
 * From slides: "The Meyers solution solves the memory leak problem!"
 */
class GameSettingsMeyers {
private:
    // Counter to track how many times instance() has been called
    static int instanceCallCount;

protected:
    /**
     * PROTECTED Constructor
     * Question from slides: "Why must Constructor be protected or private?"
     * Answer: To prevent external code from creating additional instances,
     * ensuring only ONE instance exists through the instance() method.
     * 
     * Protected vs Private:
     * - PROTECTED: Allows inheritance (use with caution!)
     * - PRIVATE: No inheritance possible
     */
    GameSettingsMeyers();
    
    /**
     * PROTECTED Copy Constructor
     * Prevents copying: GameSettingsMeyers copy = *instance();
     */
    GameSettingsMeyers(const GameSettingsMeyers& other);
    
    /**
     * PROTECTED Assignment Operator
     * Prevents assignment: *instance1 = *instance2;
     */
    GameSettingsMeyers& operator=(const GameSettingsMeyers& other);
    
    /**
     * PROTECTED Destructor
     * Question from slides: "What are the implications of private vs protected?"
     * Answer: 
     * - PRIVATE: No inheritance possible, singleton cannot be base class
     * - PROTECTED: Allows inheritance, but be careful - derived classes
     *   could break the singleton guarantee!
     */
    ~GameSettingsMeyers();
    
    // Protected member variables (game settings data)
    int volumeLevel;
    int difficultyLevel;  // 1=Easy, 2=Medium, 3=Hard
    bool fullscreenMode;
    std::string playerName;

public:
    /**
     * instance() - Meyers Singleton implementation
     * 
     * From slides: "creates a static Singleton object on the stack and
     * returns a reference to the object"
     * 
     * Key points:
     * 1. Static local variable is created on FIRST CALL
     * 2. Same instance returned on ALL subsequent calls
     * 3. Automatically destroyed when program ends (no memory leak!)
     * 4. Thread-safe in C++11 and later
     * 
     * This is called "Meyers Singleton" after Scott Meyers
     */
    static GameSettingsMeyers& instance();
    
    /**
     * Get the number of times instance() has been called
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

#endif // GAMESETTINGSMEYERS_H