# Class Adapter Pattern - Database Connection Example

## Overview
This example demonstrates the **Class Adapter Pattern** using database connections. Unlike the Object Adapter that uses composition, the Class Adapter uses **multiple inheritance** to adapt incompatible interfaces.

## Pattern Participants

### Target: `DatabaseConnection`
- The interface expected by the client application
- Defines standard methods: `connect()`, `executeQuery()`, `disconnect()`

### Adaptee: `MongoDBConnection` and `PostgresConnection`
- Legacy database connection classes with incompatible interfaces
- **MongoDB** uses: `openConnection()`, `runQuery()`, `closeConnection()`
- **PostgreSQL** uses: `establishLink()`, `performSQL()`, `terminateLink()`

### Adapter: `MongoAdapter` and `PostgresAdapter`
- **Public inheritance** from `DatabaseConnection` (Target) - inherits interface
- **Private inheritance** from Adaptee - inherits implementation only
- Directly calls inherited Adaptee methods (no delegation needed)

### Client: `main()`
- Works only with `DatabaseConnection*` pointers
- Can use any database system without knowing implementation details

## Key Class Adapter Features

1. **Multiple Inheritance**: `class MongoAdapter : public DatabaseConnection, private MongoDBConnection`
2. **No Object Composition**: No adaptee pointer needed
3. **Private Inheritance**: Inherits implementation from Adaptee, but not its interface
4. **Direct Method Calls**: `openConnection()` called directly (not through a pointer)
5. **Simpler Implementation**: No dynamic memory management for adaptee

## Class Adapter vs Object Adapter

| Aspect | Class Adapter | Object Adapter |
|--------|---------------|----------------|
| Mechanism | Private inheritance | Object composition |
| Adaptee pointer | No | Yes (needs new/delete) |
| Method calls | Direct (inherited) | Delegation (pointer->) |
| Runtime flexibility | Less (fixed at compile time) | More (can swap adaptees) |
| Memory | Simpler | More complex |

## Compilation & Running

```bash
make
make run
```

Or manually:
```bash
g++ -std=c++11 -o adapter_demo main.cpp MongoAdapter.cpp PostgresAdapter.cpp MongoDBConnection.cpp PostgresConnection.cpp
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

## Why Use Class Adapter?
- Simpler implementation (no pointers to manage)
- More efficient (no indirection through pointers)
- Good when you don't need runtime flexibility
- Follows the "mixin" pattern from your lecture slides