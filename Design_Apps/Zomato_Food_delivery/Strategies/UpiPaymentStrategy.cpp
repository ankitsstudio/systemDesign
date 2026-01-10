#ifndef UPIPAYMENTSTRATEGY_H
#define UPIPAYMENTSTRATEGY_H

#include "PaymentStrategy.cpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
private:
    string mobile;
public:
    UpiPaymentStrategy(const string& mob) {
        mobile = mob;
    }

    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using UPI (" << mobile << ")" << endl;
    }
};

#endif