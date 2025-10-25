CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = game

SRCS = main.cpp WeaponInventory.cpp WeaponIterator.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp WeaponInventory.h WeaponIterator.h Iterator.h Item.h Node.h
	$(CXX) $(CXXFLAGS) -c main.cpp

WeaponInventory.o: WeaponInventory.cpp WeaponInventory.h WeaponIterator.h Node.h Item.h
	$(CXX) $(CXXFLAGS) -c WeaponInventory.cpp

WeaponIterator.o: WeaponIterator.cpp WeaponIterator.h Iterator.h WeaponInventory.h Item.h Node.h
	$(CXX) $(CXXFLAGS) -c WeaponIterator.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run