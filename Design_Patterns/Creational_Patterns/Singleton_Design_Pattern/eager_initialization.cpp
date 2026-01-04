#include <iostream>
using namespace std;

class EagerSingleton {
private:
    static EagerSingleton* instance;

    EagerSingleton() {}

public:
    static EagerSingleton* getInstance() {
        return instance;
    }
};

EagerSingleton* EagerSingleton::instance = new EagerSingleton();

int main() {
    auto s = EagerSingleton::getInstance();
    cout << "Eager instance created at program start" << endl;
    return 0;
}
