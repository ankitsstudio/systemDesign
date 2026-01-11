#ifndef NOTIFICATION_STRATEGY_H
#define NOTIFICATION_STRATEGY_H

#include <string>
using std::string;

class NotificationStrategy {
public:
    virtual void sendNotification(string content) = 0;
    virtual ~NotificationStrategy() {}
};

#endif
