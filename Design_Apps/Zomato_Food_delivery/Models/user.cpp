#ifndef USER_H
#define USER_H

#include<iostream>
#include "Cart.cpp"

using namespace std;

class User {
private: 
    string name;
    int userId;
    string address;
    Cart* cart;

public:
    // user constructer
    User(int userId, const string& name, const string& address) {
        this->name = name;
        this->userId = userId;
        this->address = address;
        this->cart = new Cart();
    }

    // user destructor
    ~User(){
        delete cart;
    }

    // getter and setter methods
    string getName() const {
        return name;
    }
    void setName(const string& n){
        name = n;
    }

    string getAddress() const{
        return address;
    }
    
    void setAddress(const string& a){
        address = a;
    }

    Cart* getCart() const{
        return cart;
    }
};

#endif