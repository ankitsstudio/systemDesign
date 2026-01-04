#include <iostream>

using namespace std;

// abstraction (Interface)
class Database {
public: 
    virtual void save(string data) = 0; //pure virtual function
};

// Low-Level Module for sql implementation
class MySQLDatabase: public Database {
    public: 
        void save(string data) override {
            cout<<"Saving user data "<<data<<" to the sql database"<<endl;
        }
};

// Low-Level Module for mongo implementation
class MongoDatabase : public Database {
    public: 
        void save(string data) override {
            cout<<"Saving user data "<<data<<" to the mongo database"<<endl;
        }
};

// High-Level Module (OPEN/CLOSED Principle Intact, no need to change this class if want to add new storage service)
class UserService {
    private:
        Database* db; // dependency Injection

    public:
        UserService(Database* db){
            this->db = db;
        }
        void storeUser(string user) {
            db->save(user);
        }
};

int main (){
    Database* sqldb = new MySQLDatabase();
    // Database* mongodb = new MongoDatabase();

    // UserService service(mongodb);
    UserService service(sqldb);
    service.storeUser("Mohit");
}