# Object Adapter Pattern - Database Connection Example

## Overview
This example demonstrates the **Object Adapter Pattern** using database connections. The application expects a standard `DatabaseConnection` interface, but needs to work with legacy database systems (MongoDB and PostgreSQL) that have incompatible interfaces.

## Pattern Participants

### Target: `DatabaseConnection`
- The interface expected by the client application
- Defines standard methods: `connect()`, `executeQuery()`, `disconnect()`

### Adaptee: `MongoDBConnection` and `PostgresConnection`
- Legacy database connection classes with incompatible interfaces
- **MongoDB** uses: `openConnection()`, `runQuery()`, `closeConnection()`
- **PostgreSQL** uses: `establishLink()`, `performSQL()`, `terminateLink()`

### Adapter: `MongoAdapter` and `PostgresAdapter`
- Implements the `DatabaseConnection` (Target) interface
- Uses **object composition** by holding a pointer to the Adaptee
- Delegates calls to the appropriate Adaptee methods

### Client: `main()`
- Works only with `DatabaseConnection*` pointers
- Can use any database system without knowing implementation details

## Key Adapter Pattern Features

1. **Object Composition**: Each adapter contains a pointer to its adaptee (`MongoDBConnection*` or `PostgresConnection*`)
2. **Public Inheritance**: Adapters inherit from `DatabaseConnection` (Target)
3. **Delegation**: Adapter methods delegate to adaptee methods
4. **Interface Translation**: Converts `connect()` → `openConnection()` / `establishLink()`, etc.

## Compilation & Running

```bash
make
make run
```

Or manually:
```bash
g++ -std=c++11 -o adapter_demo main.cpp MongoAdapter.cpp PostgresAdapter.cpp
./adapter_demo
```

## Expected Output
```
=== Testing MongoDB Adapter ===
MongoDB: Opening connection to localhost:27017
MongoDB: Executing query -> db.users.find()
MongoDB: Executing query -> db.users.insertOne({name: 'John'})
MongoDB: Closing connection

=== Testing PostgreSQL Adapter ===
PostgreSQL: Establishing link to database myapp_db
PostgreSQL: Performing SQL -> SELECT * FROM users
PostgreSQL: Performing SQL -> INSERT INTO users VALUES ('Jane')
PostgreSQL: Terminating link
```

## Why Use This Pattern?
- Work with legacy code without modifying it
- Maintain a consistent interface for client code
- Easy to add new database systems (just create new adapters)
- Follows Open/Closed Principle