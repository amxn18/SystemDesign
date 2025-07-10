#include<bits/stdc++.h>
using namespace std;

// Abstraction(Interface)
class Database {
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// MySql Implementation(low-level module)
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Saving to MySQL: " << data << endl;
    }
};      
// MongoDB Implementation(low-level module) 
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Saving to MongoDB: " << data << endl;
    }
};      

// High-level module
class UserServer {
private:
    Database* db; // Depend on abstraction instead of concrete implementation                       
public:
    UserServer(Database* database) : db(database) {} // Constructor injection           
    void saveUserData(string data) {
        db->save(data); // Use the abstraction to save data
    }  
};

int main() {
    MySQLDatabase mysqlDB; // Create MySQL database instance
    MongoDBDatabase mongoDB; // Create MongoDB database instance

    UserServer userServer(&mysqlDB); // Use MySQL database
    userServer.saveUserData("User data for MySQL");

    UserServer userServerMongo(&mongoDB); // Use MongoDB database
    userServerMongo.saveUserData("User data for MongoDB");

    return 0;
}   


// This code follows the Dependency Inversion Principle (DIP) by introducing an abstraction (the `Database` interface) that both high-level and low-level modules depend on. The `UserServer` class now depends
// on the `Database` interface instead of directly on the concrete implementations (`MySQLDatabase` and `MongoDBDatabase`). This allows for greater flexibility and easier maintenance, as you can easily switch out the database implementations without affecting the high-level module.
// The code demonstrates how to implement the Dependency Inversion Principle in C++ by using interfaces and dependency injection. It shows how to create a high-level module that depends on an abstraction instead of concrete implementations, allowing for greater flexibility and easier maintenance in the codebase.
// This code is a simple demonstration of the Dependency Inversion Principle in C++. It shows how to create a high-level module that depends on an abstraction instead of concrete implementations, allowing for greater flexibility and easier maintenance in the codebase.
// By following the Dependency Inversion Principle, we can create a more modular and maintainable codebase that is easier to extend and modify in the future. This code can be used as a starting point for implementing the Dependency Inversion Principle in C++ projects.
// It demonstrates how to create a high-level module that depends on an abstraction instead of concrete implementations, allowing for greater flexibility and easier maintenance in the codebase.
// The code can be extended further by adding more database implementations or other high-level modules that depend