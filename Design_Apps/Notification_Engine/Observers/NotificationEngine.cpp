#include <iostream>
#include <vector>
#include "IObserver.h"
#include "NotificationObservable.h"
#include "../Strategies/NotificationStrategy.h"

using namespace std;

class NotificationEngine : public IObserver {
private:
    NotificationObservable* notificationObservable;
    vector<NotificationStrategy*> notificationStrategies;

public:
    NotificationEngine(NotificationObservable* observable) {
        this->notificationObservable = observable;
    }

    void addNotificationStrategy(NotificationStrategy* ns) {
        this->notificationStrategies.push_back(ns);
    }

    void update() {
        string notificationContent = notificationObservable->getNotificationContent();
        for (const auto strategy: notificationStrategies) {
            strategy->sendNotification(notificationContent);
        }
    }
};