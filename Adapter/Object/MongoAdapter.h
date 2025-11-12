#ifndef MONGOADAPTER_H
#define MONGOADAPTER_H

#include "DatabaseConnection.h"
#include "MongoDBConnection.h"
#include <string>

class MongoAdapter : public DatabaseConnection {
public:
    MongoAdapter(std::string host);
    ~MongoAdapter();
    virtual void connect();
    virtual void executeQuery(std::string query);
    virtual void disconnect();
private:
    MongoDBConnection* adaptee;
};

#endif