#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include <iostream>
#include "Order.cpp"

using namespace std;

class PickUpOrder : public Order {
private: 
    string restauretAddress;

public:
    PickUpOrder() {}
    PickUpOrder(const string& da){
        restauretAddress = "";
    }

    string getType() const override {
        return "Pickup";
    }

    // getters and setters

    void setPickupAddress(const string& ra) {
        restauretAddress = ra;
    }

    string getPickupAddress() const {
        return restauretAddress;
    }
};

#endif