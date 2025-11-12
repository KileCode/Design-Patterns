
#ifndef POSTGRESADAPTER_H
#define POSTGRESADAPTER_H

#include "DatabaseConnection.h"
#include "PostgresConnection.h"
#include <string>

class PostgresAdapter : public DatabaseConnection {
public:
    PostgresAdapter(std::string dbName);
    ~PostgresAdapter();
    virtual void connect();
    virtual void executeQuery(std::string query);
    virtual void disconnect();
private:
    PostgresConnection* adaptee;
};

#endif