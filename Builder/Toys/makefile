# Makefile for Builder Pattern Example

CXX = g++
CXXFLAGS = -Wall -g
TARGET = builder_example

# Object files
OBJS = main.o PlainGiraffe.o CuddlyBear.o PlainGiraffeMaker.o \
       CuddlyBearMaker.o Mother.o Shop.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
main.o: main.cpp Mother.h Shop.h PlainGiraffeMaker.h CuddlyBearMaker.h \
        PlainGiraffe.h CuddlyBear.h
	$(CXX) $(CXXFLAGS) -c main.cpp

PlainGiraffe.o: PlainGiraffe.cpp PlainGiraffe.h
	$(CXX) $(CXXFLAGS) -c PlainGiraffe.cpp

CuddlyBear.o: CuddlyBear.cpp CuddlyBear.h
	$(CXX) $(CXXFLAGS) -c CuddlyBear.cpp

PlainGiraffeMaker.o: PlainGiraffeMaker.cpp PlainGiraffeMaker.h \
                     SoftToyMachine.h PlainGiraffe.h
	$(CXX) $(CXXFLAGS) -c PlainGiraffeMaker.cpp

CuddlyBearMaker.o: CuddlyBearMaker.cpp CuddlyBearMaker.h \
                   SoftToyMachine.h CuddlyBear.h
	$(CXX) $(CXXFLAGS) -c CuddlyBearMaker.cpp

Mother.o: Mother.cpp Mother.h SoftToyMachine.h
	$(CXX) $(CXXFLAGS) -c Mother.cpp

Shop.o: Shop.cpp Shop.h SoftToyMachine.h
	$(CXX) $(CXXFLAGS) -c Shop.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run