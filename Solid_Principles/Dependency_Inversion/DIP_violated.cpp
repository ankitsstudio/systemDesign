#include <iostream>

using namespace std;

class MySQLDatabase {
    public: 
        void saveToSQL(string data) {
            cout<<"Saving user data"<<data<<" to the sql database"<<endl;
        }
};

class MongoDatabase {
    public: 
        void saveToMongo(string data) {
            cout<<"Saving user data"<<data<<" to the mongo database"<<endl;
        }
};

// High-Level Module (Tightly coupled)
class UserService {
    private:
        MySQLDatabase* sqlDB; // Direct dependency on SQL database
        MongoDatabase* mongoDB; // Direct dependency on Mongo database

        // If a new storage requires then will need to change this high-level module.

    public:
        void storeUserToSQL(string user) {
            sqlDB->saveToSQL(user);
        }

        void storeUserToMongo(string user) {
            mongoDB->saveToMongo(user);
        }
};

int main (){
    UserService service;
    service.storeUserToSQL("Aditya");
    service.storeUserToMongo("Mohit");
}