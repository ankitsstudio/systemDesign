#include<iostream> 
using namespace std;

class Burger {
public: 
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The basic burger with bun, veggies and luttece is preparing...."<<endl;
    }
};

class StandardBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The standard burger with bun, veggies, luttece and paneer is preparing...."<<endl;
    }
};

class PremiumBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The Premium burger with premium bun, veggies, premium luttece and paneer is preparing...."<<endl;
    }
};

class BasicWheatBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The basic wheat burger with bun, veggies and luttece is preparing...."<<endl;
    }
};

class StandardWheatBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The standard wheat burger with bun, veggies, luttece and paneer is preparing...."<<endl;
    }
};

class PremiumWheatBurger : public Burger {
public: 
    void prepare() override {
        cout<<"The Premium wheat burger with premium bun, veggies, premium luttece and paneer is preparing...."<<endl;
    }
};

class BurgerFactory {
public: 
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurgerFactory : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if(type == "basic") return new BasicBurger();
        else if(type == "standard") return new StandardBurger();
        else if(type == "premium") return new PremiumBurger();
        else {
            cout<<"Invalid burger type"<<endl;
            return nullptr;
        }
    }
};

class KingBurgerFactory : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if(type == "basic") return new BasicWheatBurger();
        else if(type == "standard") return new StandardWheatBurger();
        else if(type == "premium") return new PremiumWheatBurger();
        else {
            cout<<"Invalid burger type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "premium";
    BurgerFactory* myBurgerFactor = new KingBurgerFactory();
    Burger* burger = myBurgerFactor->createBurger(type);
    burger->prepare();
    return 0;
}