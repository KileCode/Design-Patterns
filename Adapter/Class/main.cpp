#include <iostream>
#include "DatabaseConnection.h"
#include "MongoAdapter.h"
#include "PostgresAdapter.h"

using namespace std;

int main() {
    cout << "=== Testing MongoDB Adapter ===" << endl;
    DatabaseConnection* mongoDb = new MongoAdapter("localhost:27017");
    mongoDb->connect();
    mongoDb->executeQuery("db.users.find()");
    mongoDb->executeQuery("db.users.insertOne({name: 'John'})");
    mongoDb->disconnect();
    delete mongoDb;

    cout << "\n=== Testing PostgreSQL Adapter ===" << endl;
    DatabaseConnection* postgresDb = new PostgresAdapter("myapp_db");
    postgresDb->connect();
    postgresDb->executeQuery("SELECT * FROM users");
    postgresDb->executeQuery("INSERT INTO users VALUES ('Jane')");
    postgresDb->disconnect();
    delete postgresDb;

    return 0;
}