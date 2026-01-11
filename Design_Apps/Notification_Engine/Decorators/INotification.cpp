#include<iostream>

using namespace std;

class INotification {
public: 
    virtual string getContent() const = 0;
    virtual ~INotification() {};
};