#include<string>
using namespace std;

class NotificationStrategy {
public: 
    virtual void sendNotification(string content) = 0;
};