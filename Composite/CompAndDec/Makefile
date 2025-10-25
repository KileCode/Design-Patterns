CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = plant_demo

SOURCES = Plant.cpp Rose.cpp Decorator.cpp DecorativePotDecorator.cpp RibbonDecorator.cpp \
          Order.cpp Leaf.cpp ConcreteOrder.cpp AbstractFinalOrder.cpp FinalOrder.cpp main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run