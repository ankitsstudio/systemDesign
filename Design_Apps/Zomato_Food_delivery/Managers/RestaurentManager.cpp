#ifndef RESTAURENTMANAGER_H
#define RESTAURENTMANAGER_H

#include<iostream>
#include<vector>
#include<algorithm>

#include "../Models/Restaurent.cpp"

using namespace std;

class RestaurentManager {
private:
    vector<Restaurent*> restaurents;
    static RestaurentManager* instance;

    RestaurentManager(){}; // private constructor

public:
    static RestaurentManager* getInstance(){
        if(!instance){
            instance = new RestaurentManager();
        }
        return instance;
    }

    void addRestaurent(Restaurent* r) {
        restaurents.push_back(r);
    }

    vector<Restaurent*> searchByLocation(string loc){
        vector<Restaurent*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);

        for(auto resto: restaurents){
            string location = resto->getLocation();
            transform(location.begin(), location.end(), location.begin(), ::tolower);

            if(location == loc) result.push_back(resto);
        }

        return result;
    }
};

RestaurentManager* RestaurentManager::instance = nullptr;

#endif
