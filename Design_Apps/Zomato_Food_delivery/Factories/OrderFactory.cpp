#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include<iostream>
#include "../Models/Order.cpp"
#include "../Models/Cart.cpp"
#include "../Models/Restaurent.cpp"
#include "../Models/User.cpp"
#include "../Strategies/PaymentStrategy.cpp"
#include <vector>
#include <string>
using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurent* restaurant, const vector<MenuItem>& menuItems, PaymentStrategy* paymentStrategy,
                                 double totalCost, const string& orderType) = 0;
    virtual ~OrderFactory() {}
};

#endif