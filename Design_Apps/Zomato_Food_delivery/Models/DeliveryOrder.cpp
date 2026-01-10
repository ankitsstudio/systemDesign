#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <iostream>
#include "Order.cpp"

using namespace std;

class DeliveryOrder : public Order {
private: 
    string deliverAddress;

public:
    DeliveryOrder() {};
    DeliveryOrder(const string& da){
        deliverAddress = "";
    }

    string getType() const override {
        return "Delivery";
    }

    // getters and setters

    void setDeliveryAddress(const string& da) {
        deliverAddress = da;
    }

    string getDeliveryAddress() const {
        return deliverAddress;
    }
};

#endif