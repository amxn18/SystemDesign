#include<bits/stdc++.h>
using namespace std;
// High-level module depends on low-level module
// This is a violation of the Dependency Inversion Principle (DIP)
// High-level modules should not depend on low-level modules. Both should depend on abstractions
class MySQLDatabase { // Low-level module 
    public:
    void saveToSQL(string data) {
        cout << "Saving to MySQL: " << data << endl;
    }
};

class MongoDBDatabase {  // Low-level module
    public:
    void saveToMongo(string data) {
        cout << "Saving to MongoDB: " << data << endl;
    }
};

class UserServer{ // High-level module
    private:
    MySQLDatabase* mysqlDB;
    MongoDBDatabase* mongoDB;
    public:
    UserServer(MySQLDatabase* mysql, MongoDBDatabase* mongo) : mysqlDB(mysql), mongoDB(mongo) {}
    void saveUserData(string data) {
        if (mysqlDB) {
            mysqlDB->saveToSQL(data);
        }
        if (mongoDB) {
            mongoDB->saveToMongo(data);
        }
    }
};

int main(){
    MySQLDatabase mysqlDB;
    MongoDBDatabase mongoDB;
    UserServer userServer(&mysqlDB, &mongoDB);
    
    userServer.saveUserData("User data example");
    
    return 0;
}


// DIP is violated here because the high-level module `UserServer` directly depends on low-level modules `MySQLDatabase` and `MongoDBDatabase`. This creates a tight coupling between the high-level and low-level modules, making it difficult to change or extend the system without modifying the high-level module.
// To follow the Dependency Inversion Principle, we should introduce an abstraction (interface) that both high-level and low-level modules can depend on. This way, the high-level module will not depend directly on the low-level modules, but rather on the abstraction.
// This can be achieved by creating an interface for the database operations and having both `MySQ  LDatabase` and `MongoDBDatabase` implement this interface. The `UserServer` will then depend on this interface instead of the concrete database implementations. This will allow for greater flexibility and easier maintenance in the codebase.
// The code above is a simple example of how the Dependency Inversion Principle can be violated in C++. It demonstrates how high-level modules can become tightly coupled with low-level modules, making the code less flexible and harder to maintain. By following the Dependency Inversion Principle, we can create a more modular and maintainable codebase that is easier to extend and modify in the future.          
// In a real-world scenario, you would typically use interfaces or abstract classes to define the contract for the database operations, and then implement those interfaces in the concrete database classes. This would allow you to easily switch out the database implementations without affecting the high-level module, adhering to the Dependency Inversion Principle.
// This code is a simple demonstration of the Dependency Inversion Principle violation in C++. It shows