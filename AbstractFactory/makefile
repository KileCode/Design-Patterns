# Makefile for Abstract Factory Pattern - Vehicle Manufacturing

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = main

# Object files
OBJS = main.o \
       ToyotaFactory.o \
       BMWFactory.o \
       TeslaFactory.o \
       ToyotaProducts.o \
       BMWProducts.o \
       TeslaProducts.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp (Client)
main.o: main.cpp VehicleFactory.h ToyotaFactory.h BMWFactory.h TeslaFactory.h Sedan.h SUV.h Truck.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile Concrete Factories
ToyotaFactory.o: ToyotaFactory.cpp ToyotaFactory.h VehicleFactory.h ToyotaProducts.h
	$(CXX) $(CXXFLAGS) -c ToyotaFactory.cpp

BMWFactory.o: BMWFactory.cpp BMWFactory.h VehicleFactory.h BMWProducts.h
	$(CXX) $(CXXFLAGS) -c BMWFactory.cpp

TeslaFactory.o: TeslaFactory.cpp TeslaFactory.h VehicleFactory.h TeslaProducts.h
	$(CXX) $(CXXFLAGS) -c TeslaFactory.cpp

# Compile Concrete Products
ToyotaProducts.o: ToyotaProducts.cpp ToyotaProducts.h Sedan.h SUV.h Truck.h
	$(CXX) $(CXXFLAGS) -c ToyotaProducts.cpp

BMWProducts.o: BMWProducts.cpp BMWProducts.h Sedan.h SUV.h Truck.h
	$(CXX) $(CXXFLAGS) -c BMWProducts.cpp

TeslaProducts.o: TeslaProducts.cpp TeslaProducts.h Sedan.h SUV.h Truck.h
	$(CXX) $(CXXFLAGS) -c TeslaProducts.cpp

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run