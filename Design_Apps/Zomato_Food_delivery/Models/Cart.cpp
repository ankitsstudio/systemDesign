#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "MenuItem.cpp"
#include "Restaurent.cpp"


using namespace std;

class Cart {
private: 
    Restaurent* restaurent;
    vector<MenuItem> items;

public:
    Cart(){
        restaurent = nullptr;
    }

    void addItem(const MenuItem &item){
        if(!restaurent){
            cout<<"No Restaurent is associated with the item.."<<endl;
        }
        else items.push_back(item);
    }

    double getTotalCost() const {
        double sum = 0;
        for(const auto& item: items){
            sum += item.getPrice();
        }
        return sum;
    }

    void clear(){
        items.clear();
        restaurent = nullptr;
    }

    bool isEmpty(){
        return (!restaurent || items.empty());
    }

    // getters and setters
    void setRestaurent(Restaurent* r){
        restaurent = r;
    }

    Restaurent* getRestaurent() const {
        return restaurent;
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

};

#endif