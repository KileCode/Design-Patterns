#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <string>

class DatabaseConnection {
public:
    virtual ~DatabaseConnection() {}
    virtual void connect() = 0;
    virtual void executeQuery(std::string query) = 0;
    virtual void disconnect() = 0;
};

#endif