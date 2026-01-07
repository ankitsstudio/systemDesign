#include <iostream>
#include <vector>

#include "MenuItem.cpp"

using namespace std;

class Restaurent {
private: 
    static int nextRestoId;
    int restoId;
    string name;
    string location;
    vector<MenuItem> items;

public: 
    Restaurent(const string& name, const string& location){
        this->name = name;
        this->location = location;
        this->restoId = ++nextRestoId;
    }

    ~Restaurent(){
        cout<< "Destroying Restauren: "<<name<< " Clearing its menu.."<<endl;
        items.clear();
    }

    //getters and setters
    void setName(string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setLocation(string& l) {
        location = l;
    }

    string getLocation() const {
        return location;
    }

    void addMenuItem(const MenuItem& item){
        items.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return items;
    }
};

int Restaurent::nextRestoId = 0;