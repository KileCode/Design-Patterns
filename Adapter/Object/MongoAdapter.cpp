#include "MongoAdapter.h"

MongoAdapter::MongoAdapter(std::string host) {
    adaptee = new MongoDBConnection(host);
}

MongoAdapter::~MongoAdapter() {
    delete adaptee;
}

void MongoAdapter::connect() {
    adaptee->openConnection();
}

void MongoAdapter::executeQuery(std::string query) {
    adaptee->runQuery(query);
}

void MongoAdapter::disconnect() {
    adaptee->closeConnection();
}