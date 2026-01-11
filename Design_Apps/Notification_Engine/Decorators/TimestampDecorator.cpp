#include <iostream>
#include "INotificationDecorator.h"

using namespace std;

class TimestampDecorator : public INotificationDecorator {
public:
    TimestampDecorator(INotification* n) : INotificationDecorator(n) {}

    string getContent() const override {
        return "[2026-01-11 15:11:20]" + notification->getContent();
    }
};