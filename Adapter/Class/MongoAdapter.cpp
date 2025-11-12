
// MongoAdapter.cpp
#include "MongoAdapter.h"

MongoAdapter::MongoAdapter(std::string host) : MongoDBConnection(host) {}

void MongoAdapter::connect() {
    openConnection();
}

void MongoAdapter::executeQuery(std::string query) {
    runQuery(query);
}

void MongoAdapter::disconnect() {
    closeConnection();
}