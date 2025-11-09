# Makefile for Facade Design Pattern - Computer Startup Example

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = main

# Object files
OBJECTS = main.o CPU.o Memory.o HardDrive.o BIOS.o ComputerFacade.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "\n=== Build Complete ==="
	@echo "Run with: ./$(TARGET)\n"

# Compile main.cpp
main.o: main.cpp ComputerFacade.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile CPU.cpp
CPU.o: CPU.cpp CPU.h
	$(CXX) $(CXXFLAGS) -c CPU.cpp

# Compile Memory.cpp
Memory.o: Memory.cpp Memory.h
	$(CXX) $(CXXFLAGS) -c Memory.cpp

# Compile HardDrive.cpp
HardDrive.o: HardDrive.cpp HardDrive.h
	$(CXX) $(CXXFLAGS) -c HardDrive.cpp

# Compile BIOS.cpp
BIOS.o: BIOS.cpp BIOS.h
	$(CXX) $(CXXFLAGS) -c BIOS.cpp

# Compile ComputerFacade.cpp
ComputerFacade.o: ComputerFacade.cpp ComputerFacade.h CPU.h Memory.h HardDrive.h BIOS.h
	$(CXX) $(CXXFLAGS) -c ComputerFacade.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete"

# Rebuild everything from scratch
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run