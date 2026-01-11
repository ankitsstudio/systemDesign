#include <iostream>
#include "INotificationDecorator.h"

using namespace std;

INotificationDecorator::INotificationDecorator(INotification* n) : notification(n) {}

INotificationDecorator::~INotificationDecorator() {
    delete notification;
}