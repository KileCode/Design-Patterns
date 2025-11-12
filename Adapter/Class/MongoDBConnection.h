#ifndef MONGODBCONNECTION_H
#define MONGODBCONNECTION_H

#include <iostream>
#include <string>

class MongoDBConnection {
public:
    MongoDBConnection(std::string host);
    void openConnection();
    void runQuery(std::string query);
    void closeConnection();
protected:
    std::string hostname;
    bool connected;
};

#endif