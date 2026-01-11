#ifndef INOTIFICATION_DECORATOR_H
#define INOTIFICATION_DECORATOR_H

#include "INotification.h"

class INotificationDecorator : public INotification {
protected:
    INotification* notification;

public:
    INotificationDecorator(INotification* n);
    virtual ~INotificationDecorator();
};

#endif
