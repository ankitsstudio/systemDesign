#ifndef INOTIFICATION_H
#define INOTIFICATION_H

#include <string>
using std::string;

class INotification {
public:
    virtual string getContent() const = 0;
    virtual ~INotification() {}
};

#endif
