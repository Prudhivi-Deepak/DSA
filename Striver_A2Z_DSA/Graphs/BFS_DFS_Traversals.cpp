#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void dfs(int i, vector<int> adj[], vector<int> &nodes, vector<int> &visited){
        nodes.push_back(i); visited[i] = 1;
        for(int k:adj[i]){
          if(visited[k]==0) dfs(k, adj, nodes, visited);
        }
      }
      vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0), nodes;
        // for(int i=0; i<V; i++){
          // if(visited[i] == 0) 
        dfs(0, adj, nodes, visited);
        // }
        return nodes;
  
  
  
        // vector<int> nodes;
        // stack<int> st;
        // st.push(0);
        // visited[0] = 1;
  
        // while(!st.empty()){
        //   int currNode = st.top(); st.pop();
        //   nodes.push_back(currNode);
  
        //   vector<int> temp_adj = adj[currNode];        
        //   // for(int k: temp_adj){
        //    for (int k = temp_adj.size() - 1; k >= 0; --k) {
        //     if(visited[temp_adj[k]]==0) {
        //       visited[temp_adj[k]] = 1;
        //       st.push(temp_adj[k]);
        //     }
        //   }
          
        // }
        // return nodes;
      }
      
      vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> nodes;
        queue<int> q;
        q.push(0);
        visited[0] =1;
  
        while(!q.empty()){
          int currNode = q.front(); q.pop();
          nodes.push_back(currNode);
          for(int k: adj[currNode]){
            if(visited[k]==0) {
              visited[k] =1;
              q.push(k);
            }
          }
        }
        return nodes;
      }
  };
  