#include <iostream>

using namespace std;

// Strategy Interface for Talable Robot
class TalkableRobot {
public: 
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// Concrete Strategy to talk
class NormalTalk: public TalkableRobot {
public: 
    void talk() override {
        cout<<"The robot can talk"<<endl;
    }
};

class NoTalk: public TalkableRobot {
public: 
    void talk() override {
        cout<<"The robot cannot talk..."<<endl;
    }
};

// Strategy Interface for walkable robot
class WalkbaleRobot {
public:
    virtual void walk () = 0;
    virtual ~WalkbaleRobot() {} 
};

// Concrete Strategy to walk 
class NormalWalk : public WalkbaleRobot {
    void walk() override {
        cout<<"The robot can walk.."<<endl;
    }
};

class NoWalk : public WalkbaleRobot {
    void walk() override {
        cout<<"The robot cannot walk.."<<endl;
    }
};

// Strategy Interface for flyable robot
class FlybaleRobot {
public:
    virtual void fly () = 0;
    virtual ~FlybaleRobot() {} 
};

// Concrete Strategy to fly 
class NormalFly : public FlybaleRobot {
    void fly() override {
        cout<<"The robot can fly.."<<endl;
    }
};

class NoFly : public FlybaleRobot {
    void fly() override {
        cout<<"The robot cannot fly.."<<endl;
    }
};

// Context 
class Robot {
protected: 
    TalkableRobot* talkableRobot;
    WalkbaleRobot* walkbaleRobot;
    FlybaleRobot* flybaleRobot;
    
public:
    Robot(WalkbaleRobot* w, TalkableRobot* t, FlybaleRobot* f){
        this->flybaleRobot = f;
        this->talkableRobot = t;
        this->walkbaleRobot = w;
    }

    void walk () {
        walkbaleRobot->walk();
    }
    void talk () {
        talkableRobot->talk();
    }
    void fly () {
        flybaleRobot->fly();
    }
    virtual void projection() = 0;
};

class CompanionRobot: public Robot {
public:
    CompanionRobot(WalkbaleRobot* w, TalkableRobot* t, FlybaleRobot* f) : Robot(w,t,f) {}

    void projection() override {
        cout<<"Displaying friendly companion robot"<<endl;
    }
};

class WorkerRobot: public Robot {
public:
    WorkerRobot(WalkbaleRobot* w, TalkableRobot* t, FlybaleRobot* f) : Robot(w,t,f) {}

    void projection() override {
        cout<<"Displaying friendly worker robot"<<endl;
    }
};

int main() {
    Robot* robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"------------------------"<<endl;

    Robot* robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
}
