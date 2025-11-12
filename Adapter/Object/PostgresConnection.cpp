// PostgresConnection.cpp
#include "PostgresConnection.h"

PostgresConnection::PostgresConnection(std::string dbName) 
    : database(dbName), active(false) {}

void PostgresConnection::establishLink() {
    std::cout << "PostgreSQL: Establishing link to database " << database << std::endl;
    active = true;
}

void PostgresConnection::performSQL(std::string sql) {
    if (active) {
        std::cout << "PostgreSQL: Performing SQL -> " << sql << std::endl;
    } else {
        std::cout << "PostgreSQL: Link not active!" << std::endl;
    }
}

void PostgresConnection::terminateLink() {
    std::cout << "PostgreSQL: Terminating link" << std::endl;
    active = false;
}