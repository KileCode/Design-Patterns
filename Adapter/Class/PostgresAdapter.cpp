// PostgresAdapter.cpp
#include "PostgresAdapter.h"

PostgresAdapter::PostgresAdapter(std::string dbName) : PostgresConnection(dbName) {}

void PostgresAdapter::connect() {
    establishLink();
}

void PostgresAdapter::executeQuery(std::string query) {
    performSQL(query);
}

void PostgresAdapter::disconnect() {
    terminateLink();
}