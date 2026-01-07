#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {};
};

class IChannel {
public: 
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscriber() = 0;
    virtual ~IChannel() {};

};
 
class Channel: public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string& name){
        this->name = name;
    }

    // add a subscriber (avoid the duplicates)
    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }

    // remove a subscriber 
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
        }
    }

    void notifySubscriber() override {
        for(auto& sub: subscribers){
            sub->update();
        }
    }

    void uploadVideo(const string& title){
        latestVideo = title;
        cout<<"\n["<<name<<" uploaded \""<<latestVideo<<"\"\n"<<endl;
        notifySubscriber();
    }

    string getVideoData(){
        return "\nCheckout our new video: "+ latestVideo+ "\n";
    }

};

class Subscriber : public ISubscriber {
private: 
    string name;
    Channel* channel;

public: 
    Subscriber(string n, Channel* c){
        this->name = n;
        this->channel = c;
    }

    void update() override {
        cout<<"Hay "<<name<<", "<<channel->getVideoData();
    }
};

int main() {
    Channel* channel = new Channel("Coder Army");

    Subscriber* sub1 = new Subscriber("Aman", channel);
    Subscriber* sub2 = new Subscriber("Mohit", channel);

    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("Observer Design Pattern: system design concept");

    channel->unsubscribe(sub1);

    channel->uploadVideo("Decorator Desing Pattern: System Desing Concept");

    return 0;
}