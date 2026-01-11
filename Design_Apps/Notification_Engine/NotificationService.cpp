#include <iostream>
#include <vector>
#include <string>

#include "Observers/NotificationObservable.h"

using namespace std;

class NotificationService {
private: 
    NotificationObservable* Observable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService(){
        Observable = new NotificationObservable();
    }

public: 
    static NotificationService* getInstance() {
        if(instance == nullptr) {
            instance = new NotificationService();
        }
        return instance;
    }

    NotificationObservable* getObservable(){
        return Observable;
    }

    // creates a new notification and notify all the users
    void sendNotification(INotification* notification){
        notifications.push_back(notification);
        Observable->setNotification(notification);
    }

    ~NotificationService(){
        delete Observable;
    }
};

NotificationService* NotificationService::instance = nullptr;