#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
            vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>{});
    
            for(int e=0; e<flights.size(); e++){
                adj[flights[e][0]].push_back({flights[e][1], flights[e][2]});
            }
    
            //find shortest dist, 
                // for that we need shortDist int array with inf 
                // queue to store <stops< <dist, node>>
                // to track the path we need parents vector - not needed realsized after the problem solved
                // to track if a node is visited or not we need visited array - used as a dist array
    
            // set<pair<int,int>> st; //dist,node
            queue<pair<int, pair<int,int>>> q;
            q.push({0, {0,src}});
            
            vector<int> visited(n+1, 1e9), parents(n+1,0);
            for(int i=0; i<n; i++) parents[i]=i;
    
            while(!q.empty()){
                auto [stops, currNode_pair] = q.front(); q.pop();
                int dist = currNode_pair.first;
                int currNode = currNode_pair.second;
    
                if(currNode == dst || stops > K){
                    continue;
                }
    
                //iterate over all adj nodes
                for(auto k : adj[currNode]){
                    int node = k.first;
                    int w = k.second;
                    int cal_price = dist+w;
    
                    if(cal_price < visited[node] && stops<=K){
                        // if(visited[node]!=1e9) 
                        // q.erase({visited[node], node});
                        visited[node] = cal_price;
                        parents[node] = currNode;
                        q.push({stops+1,{cal_price, node}});
                    }
                }
            }
    
            // cout << parents[dst] << endl;
            // cout << visited[dst] << endl;
    
            if(visited[dst]==1e9) return -1;
    
            return visited[dst];
        }
    };