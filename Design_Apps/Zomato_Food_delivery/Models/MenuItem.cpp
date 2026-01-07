#include<iostream>

using namespace std;

class MenuItem {
private: 
    string code;
    string name;
    double price;

public: 
    MenuItem(string& code, string& name, double price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    // getters and setters
    void setItemCode(string& c) {
        code = c;
    }

    string getItemCode() const {
        return code;
    }

    void setItemName(string& n) {
        name = n;
    }

    string getItemName() const {
        return name;
    }

    void setPrice(double p){
        price = p;
    }

    double getPrice() const {
        return price;
    }
};