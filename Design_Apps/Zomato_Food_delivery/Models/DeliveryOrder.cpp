#include <iostream>
#include "Order.cpp"

using namespace std;

class DeliveryOrder : public Order {
private: 
    string deliverAddress;

public:
    DeliveryOrder(string& da){
        deliverAddress = "";
    }

    string getType() const override {
        return "Delivery";
    }

    // getters and setters

    void setDeliveryAddress(string& da) {
        deliverAddress = da;
    }

    string getDeliveryAddress() const {
        return deliverAddress;
    }
};