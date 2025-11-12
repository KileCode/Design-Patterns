CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Caregiver.o Granny.o Dad.o Mom.o
TARGET = main

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Granny.h Dad.h Mom.h
Caregiver.o: Caregiver.cpp Caregiver.h
Granny.o: Granny.cpp Granny.h Caregiver.h
Dad.o: Dad.cpp Dad.h Caregiver.h
Mom.o: Mom.cpp Mom.h Caregiver.h

clean:
	rm -f *.o $(TARGET)

run:
	./$(TARGET)