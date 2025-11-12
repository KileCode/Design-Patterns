# Makefile for Singleton Pattern Game Settings Example

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Target executable
TARGET = game_settings

# Source files
SOURCES = main.cpp GameSettings.cpp GameSettingsMeyers.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependencies)
HEADERS = GameSettings.h GameSettingsMeyers.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@echo ""
	./$(TARGET)

# Rebuild (clean + build)
rebuild: clean all

# Help target
help:
	@echo "Singleton Pattern Game Settings - Makefile Commands"
	@echo ""
	@echo "Usage:"
	@echo "  make          - Build the project"
	@echo "  make run      - Build and run the program"
	@echo "  make clean    - Remove build files"
	@echo "  make rebuild  - Clean and rebuild"
	@echo "  make help     - Show this help message"
	@echo ""

# Phony targets (not actual files)
.PHONY: all clean run rebuild help