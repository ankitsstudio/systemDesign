#include <iostream>
#include "IObserver.h"
#include "NotificationObservable.h"

using namespace std;

class Logger : public IObserver {
private:
    NotificationObservable* notificationObservable;

public:
    Logger(NotificationObservable* observable) {
        this->notificationObservable = observable;
    }

    void update() {
        cout << "Logging new Notification: \n" << notificationObservable->getNotificationContent();
    }
};