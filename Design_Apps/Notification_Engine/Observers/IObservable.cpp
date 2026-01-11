#include<iostream>

using namespace std;

class IObservable {
public:
    virtual void addObserver(IObserver* o) = 0;
    virtual void removeObserver(IObserver* o) = 0;
    virtual void notify() = 0;
    virtual ~IObservable() {}
};