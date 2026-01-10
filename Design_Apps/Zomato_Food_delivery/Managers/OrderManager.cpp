#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include<iostream>
#include<vector>
#include<algorithm>

#include "../Models/Order.cpp"

using namespace std;

class OrderManager {
private:
    static OrderManager* instance;
    vector<Order*> orders;

    OrderManager(){} // private constructor

public:
    static OrderManager* getInstance() {
        if(!instance){
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order* o){
        orders.push_back(o);
    }

    void listOrders(){
        cout << "\n--- All Orders ---" << endl;
        for (auto order : orders) {
            cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->getTotal()
                    << " | At: " << order->getScheduled() << endl;
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif
