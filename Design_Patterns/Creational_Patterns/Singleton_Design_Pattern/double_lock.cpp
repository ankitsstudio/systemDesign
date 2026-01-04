#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;
    Singleton(){}

public: 
    static Singleton* getInstance() {
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx); // lock on every call
            if(instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout<<"Singleton class design pattern"<<endl;
    cout<<(s1==s2)<<endl;
}