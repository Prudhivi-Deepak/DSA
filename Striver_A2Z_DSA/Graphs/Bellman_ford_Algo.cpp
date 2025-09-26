#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
            //Iterate over V-1 times and update the distance array
            // initialize distance array to 1e9 not reachable
            // start with src dist 0
    
            vector<int> distance(V, 1e9);
            distance[S] = 0;
            for(int i=0; i<V; i++){
    
                for(auto k : edges){
                    int u = k[0];
                    int v = k[1];
                    int w = k[2];
    
                    if(distance[u]!=1e9 && distance[u]+w < distance[v]){
                        if(i==V-1) return {-1};
                        distance[v] = distance[u]+w;
                    }
                }
            }
    
            return distance;
        }
    };
    