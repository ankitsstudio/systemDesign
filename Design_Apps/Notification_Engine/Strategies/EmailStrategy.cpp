#include <iostream>
#include <string>
#include "NotificationStrategy.h"

using namespace std;

class EmailStrategy : public NotificationStrategy {
private: 
    string emailId;

public: 
    EmailStrategy(string emailId){
        this->emailId = emailId;
    }

    void sendNotification(string content) override {
        cout<<"Sending Email Notification to: "<< emailId << "\n"<< content;
    }
};