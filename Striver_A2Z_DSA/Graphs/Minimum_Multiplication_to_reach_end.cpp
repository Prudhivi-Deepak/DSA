#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // [621,259,307,405,287,302,366,80,157,409]
    // 864
    // 26176
    
    // [392]
    // 879
    // 879
        int minimumMultiplications(vector<int> &arr, int start, int end) {
    
            if(start==end) return 0;
    
            int mod = 1e5;
            queue<pair<int,int>> q;
            q.push({0, start});
    
            // unordered_map<int,int> visited;
            vector<int> visited(1e5, 0);
            visited[start]=1;
    
            int min_steps = 1e9;
    
            while(!q.empty()){
                auto [steps, currNode] = q.front();q.pop();
    
                for(int k : arr){
                    int next_node = ((long long)k*currNode)%mod;
                    if(next_node == end) {
                        return steps+1;
                    }
                    if(visited[next_node]==0){
                        visited[next_node] = 1;
                        q.push({steps+1, next_node});
                    }
                }
            }
            
            return -1;
        }
    };
    