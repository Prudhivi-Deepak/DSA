#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool BFS(int i, vector<int> adj[], vector<int> &visited){
            queue<int> q;
            q.push(i);
            visited[0] = 0;
            while(!q.empty()){
                int currnode = q.front(); q.pop();
    
                for(int k : adj[currnode]){
                    if(visited[k]==-1){
                        visited[k] = !visited[currnode];
                        q.push(k);
                    }
                    else if(visited[k]==visited[currnode]){
                        return false;
                    }
                }
            }
            return true;
    
        }
    
        bool DFS(int currnode, vector<int> adj[], vector<int> &visited){
            for(int k : adj[currnode]){
                if(visited[k]==-1){
                    visited[k] = !visited[currnode];
                    if(!DFS(k, adj, visited)) return false;
                    // q.push(k);
                }
                else if(visited[k]==visited[currnode]){
                    return false;
                }
            }
            return true;
        }
    
        bool isBipartite(int V, vector<int> adj[])  {
            vector<int> visited(V, -1);
            for(int i=0; i<V; i++){
              if(visited[i]==-1){
                visited[i] = 0;
                // if(!BFS(i, adj, visited)) 
                if(!DFS(i, adj, visited)) return false;
              }
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int V = graph.size();
            vector<int> adj[V];
            for(int i=0; i<V; i++){
                for(int j=0; j<graph[i].size(); j++){
                    adj[i].push_back(graph[i][j]);
                }
            }
            return isBipartite(V, adj);
        }
    };