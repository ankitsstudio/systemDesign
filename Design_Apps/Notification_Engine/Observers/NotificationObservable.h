#ifndef NOTIFICATION_OBSERVABLE_H
#define NOTIFICATION_OBSERVABLE_H

#include "IObservable.h"
#include "IObserver.h"
#include "../Decorators/INotification.h"
#include <vector>
using std::vector;

class NotificationObservable : public IObservable {
private:
    vector<IObserver*> observers;
    INotification* currentNotification;

public:
    NotificationObservable();
    void addObserver(IObserver* o) override;
    void removeObserver(IObserver* o) override;
    void notify() override;

    INotification* getNotification();
    void setNotification(INotification* n);
    string getNotificationContent();
};

#endif
