#include <iostream>
#include <vector>

#include "Restaurent.cpp"
#include "User.cpp"
#include "MenuItem.cpp"

using namespace std;

class Order {
private: 
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurent* restaurent;
    vector<MenuItem> items;
    double orderValue;
    string scheduled;

public:
    Order(){
        user = nullptr;
        restaurent = nullptr;
        orderValue = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }

    virtual ~Order(){

    }

    virtual string getType() const = 0;

    //getters and setters
    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u){
        user =u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurent(Restaurent* r){
        restaurent =r;
    }

    Restaurent* getRestaurent() const {
        return restaurent;
    }

    void setItems(const vector<MenuItem>& its) {
        items = its;
        orderValue = 0;
        for (auto &i : items) {
            orderValue += i.getPrice();
        }
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return orderValue;
    }

    void setTotal(int orderValue) {
        this->orderValue = orderValue;
    }
};

int Order::nextOrderId = 0;