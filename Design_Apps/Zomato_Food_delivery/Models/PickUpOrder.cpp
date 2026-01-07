#include <iostream>
#include "Order.cpp"

using namespace std;

class PickUpOrder : public Order {
private: 
    string restauretAddress;

public:
    PickUpOrder(string& da){
        restauretAddress = "";
    }

    string getType() const override {
        return "Delivery";
    }

    // getters and setters

    void setDeliveryAddress(string& ra) {
        restauretAddress = ra;
    }

    string getDeliveryAddress() const {
        return restauretAddress;
    }
};