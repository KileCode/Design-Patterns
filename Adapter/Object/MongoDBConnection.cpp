// MongoDBConnection.cpp
#include "MongoDBConnection.h"

MongoDBConnection::MongoDBConnection(std::string host) 
    : hostname(host), connected(false) {}

void MongoDBConnection::openConnection() {
    std::cout << "MongoDB: Opening connection to " << hostname << std::endl;
    connected = true;
}

void MongoDBConnection::runQuery(std::string query) {
    if (connected) {
        std::cout << "MongoDB: Executing query -> " << query << std::endl;
    } else {
        std::cout << "MongoDB: Not connected!" << std::endl;
    }
}

void MongoDBConnection::closeConnection() {
    std::cout << "MongoDB: Closing connection" << std::endl;
    connected = false;
}