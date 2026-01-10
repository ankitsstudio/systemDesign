#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>

using namespace std;

class MenuItem {
private: 
    string code;
    string name;
    double price;

public: 
    MenuItem(const string& code, const string& name, double price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    // getters and setters
    void setItemCode(const string& c) {
        code = c;
    }

    string getItemCode() const {
        return code;
    }

    void setItemName(const string& n) {
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

#endif