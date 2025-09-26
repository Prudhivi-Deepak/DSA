#include <bits/stdc++.h>
using namespace std;

class Router {
    // queue<vector<int>> q;
    // unordered_set<string> packetSet;

    deque<vector<int>> q;
    set<vector<int>> packetSet;
    unordered_map<int, deque<int>> destinationPacketsMap;
    int capacity;
public:

    // 5 : [90,95,105,110]
    // 4 : 
    Router(int memoryLimit) {
        this->capacity = memoryLimit;
        q.clear();
        packetSet.clear();
        destinationPacketsMap.clear();
    }

    int lowerBound(int start, deque<int> &timestamp){
        int l=0, r = timestamp.size();

        while(l<r){
            int mid = l+ (r-l)/2;

            if(timestamp[mid]<start) l = mid+1;
            else r = mid;
        }
        return l;
    }

    int upperBound(int end, deque<int> &timestamp){
        int l=0, r = timestamp.size();
        while(l<r){
            int mid = l+(r-l)/2;

            if(timestamp[mid]<=end) l = mid+1;
            else r = mid;
        }
        return l;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source,destination,timestamp};
        if(packetSet.find(packet)==packetSet.end()){
            if(q.size()==capacity){
                auto frontPacket = q.front(); q.pop_front();
                packetSet.erase(frontPacket);
                destinationPacketsMap[frontPacket[1]].pop_front();
            }

            q.push_back(packet);
            packetSet.insert(packet);
            destinationPacketsMap[destination].push_back(timestamp);
            return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto frontPacket = q.front(); q.pop_front();
        packetSet.erase(frontPacket);
        destinationPacketsMap[frontPacket[1]].pop_front();
        return frontPacket;
    }

    int getCount(int destination, int startTime, int endTime) {

        if(destinationPacketsMap.find(destination) == destinationPacketsMap.end() || 
            destinationPacketsMap[destination].empty()) return NULL;

        int lb = lowerBound(startTime, destinationPacketsMap[destination]);
        int ub = upperBound(endTime, destinationPacketsMap[destination]);

        return ub-lb;
        // int count = 0;
        // for(auto it = packetSet.begin(); it!=packetSet.end(); it++){
        //     vector<int> t = *it;
        //     if(t[1]==destination && (t[2]>=startTime) && (t[2]<=endTime)){
        //         count++;
        //     }
        // }
        // return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */