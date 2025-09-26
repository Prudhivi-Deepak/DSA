#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool DFS(int i, int parentnode, vector<int> adj[], vector<int> &visited){
            visited[i] = 1;
            for(int n : adj[i]){
                if(visited[n]==0){
                    visited[n] = 1;
                    // q.push({n,currnode});
                    if(DFS(n, i, adj, visited)) return true;
                }
                else if(n!=parentnode){
                    return true;
                }
            }
            return false;
        }
    
        bool BFS(int i, vector<int> adj[], vector<int> &visited){
            queue<pair<int,int>> q;
    
            q.push({i, -1}); visited[i] = 1;
            while(!q.empty()){
                auto [currnode, parentnode] = q.front(); q.pop();
    
                //iterate over adjacency list and mark visited except parent
                // if visited and its not parent then return false;
                for(int n : adj[currnode]){
                    if(visited[n]==0){
                        visited[n] = 1;
                        q.push({n,currnode});
                    }
                    else if(n!=parentnode){
                        return true;
                    }
                }
            }
            return false;        
        }
    
        bool isCycle(int V, vector<int> adj[]) {
            vector<int> visited(V,0);
    
            for(int i=0; i<V; i++){
                if(visited[i]==0) 
                    // if(BFS(i, adj, visited)) 
                    if(DFS(i, -1, adj, visited)) 
                        return true;
            }
            return false;       
        }
    };