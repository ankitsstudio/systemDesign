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

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The basic garlic bread preparing...."<<endl;
    }
};

class StandardGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The standard garlic bread is preparing...."<<endl;
    }
};

class PremiumGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The Premium garlic bread is preparing...."<<endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The basic wheat garlic bread is preparing...."<<endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The standard wheat garlic bread is preparing...."<<endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout<<"The Premium wheat garlic bread is preparing...."<<endl;
    }
};

class MealFactory {
public: 
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "basic") return new BasicGarlicBread();
        else if(type == "standard") return new StandardGarlicBread();
        else if(type == "premium") return new PremiumGarlicBread();
        else {
            cout<<"Invalid garlic bread type"<<endl;
            return nullptr;
        }
    }
};

class KingFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "basic") return new BasicGarlicBread();
        else if(type == "standard") return new StandardGarlicBread();
        else if(type == "premium") return new PremiumGarlicBread();
        else {
            cout<<"Invalid garlic bread type"<<endl;
            return nullptr;
        }
    }
};


int main(){
    string type = "standard";
    MealFactory* myMealFactor = new KingFactory();
    Burger* burger = myMealFactor->createBurger(type);
    GarlicBread* garlicBread = myMealFactor->createGarlicBread(type);
    burger->prepare();
    garlicBread->prepare();
    return 0;
}