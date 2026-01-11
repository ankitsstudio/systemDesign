#include<iostream>
#include<string>
#include "NotificationStrategy.h"

using namespace std;

class PopUpStrategy : public NotificationStrategy {
public: 
    void sendNotification(string content) override {
        cout<<"Sending Popup Notification: \n"<< content;
    }
};