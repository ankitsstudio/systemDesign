#include<iostream>
#include<string>

using namespace std;

class Character {
public:
    virtual ~Character () {};
    virtual void move() = 0;
    virtual void attack() = 0;
};

class Mario : public Character {
public:
    void move() override {
        cout<<"Mario Walks forward"<<endl;
    }

    void attack() override {
        cout<<"Mario attacks enemies"<<endl;
    }
};

class CharacterDecorator : public Character{
protected: 
    Character* wrappedCharater;

public: 
    CharacterDecorator(Character* c){
        this->wrappedCharater = c;
    }

    void move() override {}
    void attack() override {}
};

class FireFlower : public CharacterDecorator {
public: 
    FireFlower(Character* c) : CharacterDecorator(c) {}

    void attack() override {
        cout<<"[Power: Fireballs]" <<"\n"<<"Mario attacks enemies with fire abilities"<<endl;
    }
};

class SuperMashroom : public CharacterDecorator {
public: 
    SuperMashroom(Character* c) : CharacterDecorator(c) {}

    void move() override {
        cout<<"Power: StarMashroom" <<"\n"<<"Super Mario moves faster."<<endl;
    }
};

class StarMan : public CharacterDecorator {
public: 
    StarMan(Character* c) : CharacterDecorator(c) {}

    void move() override {
        cout<<"[Power: StarMan]" <<"\n"<<"[ Invicibile Sparkles]"<<endl;
    }
};

int main(){
    Character* mario = new Mario();
    cout << "Basic Character: " << endl;
    mario->attack();
    mario->move();

    // Decorate Mario with a FirePower power-up.
    mario = new FireFlower(mario);
    cout << "After Fire Power : "<< endl;
    mario->attack();

    // Decorate Mario further with a GunPowerUp.
    mario = new SuperMashroom(mario);
    cout << "After Super Mashroom: " << endl;
    mario->move();
}