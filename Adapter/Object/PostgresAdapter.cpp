#include "PostgresAdapter.h"

PostgresAdapter::PostgresAdapter(std::string dbName) {
    adaptee = new PostgresConnection(dbName);
}

PostgresAdapter::~PostgresAdapter() {
    delete adaptee;
}

void PostgresAdapter::connect() {
    adaptee->establishLink();
}

void PostgresAdapter::executeQuery(std::string query) {
    adaptee->performSQL(query);
}

void PostgresAdapter::disconnect() {
    adaptee->terminateLink();
}