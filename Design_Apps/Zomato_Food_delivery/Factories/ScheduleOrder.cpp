#ifndef SCHEDULEORDER_H
#define SCHEDULEORDER_H

#include<iostream>
#include "OrderFactory.cpp"
#include "../Models/DeliveryOrder.cpp"
#include "../Models/PickUpOrder.cpp"
#include "../utils/TimeUtils.cpp"
using namespace std;

class ScheduleOrder : public OrderFactory {
private:
    string scheduleTime;
public:
     ScheduleOrder(string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Cart* cart, Restaurent* restaurent, const vector<MenuItem>& menuItems, PaymentStrategy* paymentStrategy,
                        double totalCost, const string& orderType) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            DeliveryOrder* deliveryOrder = new DeliveryOrder();
            deliveryOrder->setDeliveryAddress(user->getAddress());
            order = deliveryOrder;
        }
        else {
            auto pickupOrder = new PickUpOrder();
            pickupOrder->setPickupAddress(restaurent->getLocation());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurent(restaurent);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduleTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif