#include<iostream>
#include<string>
#include "NotificationStrategy.h"

using namespace std;

class SMSStrategy : public NotificationStrategy {
private: 
    string mobileNumber;

public: 
    SMSStrategy(string number){
        this->mobileNumber = number;
    }

    void sendNotification(string content) override {
        cout<<"Sending SMS Notification to: "<< mobileNumber << "\n"<< content;
    }
};