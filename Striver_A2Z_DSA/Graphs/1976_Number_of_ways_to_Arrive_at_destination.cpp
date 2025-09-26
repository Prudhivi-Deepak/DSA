#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            //use diskstras algo wiht ways array, but if you encounter same 
            // dist for a node instead of pushing into the queue increment the count
            // by no .of ways the currnode reached this node
            int mod = 1e9+7;
            vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>{});
    
            for(int e=0; e<roads.size(); e++){
                adj[roads[e][0]].push_back({roads[e][1], roads[e][2]});
                adj[roads[e][1]].push_back({roads[e][0], roads[e][2]});
            }
    
    
            // queue<pair<int,int>> q; //dist, node
            priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> q; 
            vector<long long> dist(n, LLONG_MAX), ways(n, 0);
            dist[0]=0;
            q.push({0,0});
            ways[0]=1; // no. of ways to reach 0 is only 1;
    
            while(!q.empty()){
                auto [d, currNode] = q.top(); q.pop();
                //now calculate adj nodes distance and compare with dist[thet node]
                if(d > dist[currNode]) continue;
    
                for(auto k : adj[currNode]){
                    int node = k.first;
                    int w = k.second;
                    long long cal_time = (long long)d+w;
                    
                    if(cal_time < dist[node]){
                        dist[node] = cal_time;
                        ways[node] = ways[currNode];
                        q.push({cal_time, node});
                    }
                    else if(cal_time == dist[node]){
                        ways[node] = (ways[currNode]+ways[node])%mod;
                    }
                }
            }
            return ways[n-1];
        }
    };