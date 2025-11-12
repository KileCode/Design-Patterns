# Makefile for Flyweight Pattern Forest Renderer

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g
TARGET = forest_renderer

SOURCES = main.cpp TreeType.cpp OakTree.cpp PineTree.cpp BirchTree.cpp \
          TreeFactory.cpp Tree.cpp Forest.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = TreeType.h OakTree.h PineTree.h BirchTree.h TreeFactory.h Tree.h Forest.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with: ./$(TARGET)"

%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning build files..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

run: $(TARGET)
	@echo "Running $(TARGET)..."
	@echo ""
	./$(TARGET)

rebuild: clean all

help:
	@echo "Flyweight Pattern Forest Renderer - Makefile Commands"
	@echo ""
	@echo "Usage:"
	@echo "  make          - Build the project"
	@echo "  make run      - Build and run the program"
	@echo "  make clean    - Remove build files"
	@echo "  make rebuild  - Clean and rebuild"
	@echo "  make help     - Show this help message"
	@echo ""

.PHONY: all clean run rebuild help