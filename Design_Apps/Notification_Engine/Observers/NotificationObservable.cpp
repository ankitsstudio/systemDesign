#include <iostream>
#include <vector>
#include <algorithm>
#include "IObservable.h"
#include "IObserver.h"
#include "../Decorators/INotification.h"

using namespace std;

NotificationObservable::NotificationObservable() : currentNotification(nullptr) {
}

void NotificationObservable::addObserver(IObserver* o) {
    observers.push_back(o);
    cout << "Observer has been added to the Observers list" << endl;
}

void NotificationObservable::removeObserver(IObserver* o) {
    auto it = find(observers.begin(), observers.end(), o);
    if (it != observers.end()) {
        observers.erase(it);
    }
    cout << "Observer has been removed to the Observers list" << endl;
}

void NotificationObservable::notify() {
    for (auto& o : observers) {
        o->update();
    }
}

INotification* NotificationObservable::getNotification() {
    return currentNotification;
}

void NotificationObservable::setNotification(INotification* n) {
    if (currentNotification != nullptr) {
        delete currentNotification;
    }
    currentNotification = n;
    notify();
}

string NotificationObservable::getNotificationContent() {
    return currentNotification->getContent();
}