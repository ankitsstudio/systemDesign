#include <iostream>
#include "INotification.h"

using namespace std;

class SimpleNotification: public INotification {
private:
    string text;
public:
    SimpleNotification(const string& text){
        this->text = text;
    }
    string getContent() const override {
        return text;
    }
};