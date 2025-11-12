#ifndef POSTGRESCONNECTION_H
#define POSTGRESCONNECTION_H

#include <iostream>
#include <string>

class PostgresConnection {
public:
    PostgresConnection(std::string dbName);
    void establishLink();
    void performSQL(std::string sql);
    void terminateLink();
private:
    std::string database;
    bool active;
};

#endif