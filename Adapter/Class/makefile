CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main
OBJS = main.o MongoAdapter.o PostgresAdapter.o MongoDBConnection.o PostgresConnection.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp DatabaseConnection.h MongoAdapter.h PostgresAdapter.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MongoAdapter.o: MongoAdapter.h MongoAdapter.cpp MongoDBConnection.h DatabaseConnection.h
	$(CXX) $(CXXFLAGS) -c MongoAdapter.cpp

PostgresAdapter.o: PostgresAdapter.h PostgresAdapter.cpp PostgresConnection.h DatabaseConnection.h
	$(CXX) $(CXXFLAGS) -c PostgresAdapter.cpp

MongoDBConnection.o: MongoDBConnection.h MongoDBConnection.cpp
	$(CXX) $(CXXFLAGS) -c MongoDBConnection.cpp

PostgresConnection.o: PostgresConnection.h PostgresConnection.cpp
	$(CXX) $(CXXFLAGS) -c PostgresConnection.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)