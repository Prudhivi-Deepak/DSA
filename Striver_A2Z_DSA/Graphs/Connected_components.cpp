#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void BFSTraversal(int i, vector<vector<int>> &edges, unordered_map<int,vector<int>> &adj, vector<int> &visited){
          
          queue<int> q;
          q.push(i);
  
          while(!q.empty()){
              int currNode = q.front(); q.pop();
              visited[currNode] = 1;
              // if(adj.find(currNode)!=adj.end()){
              for(int j: adj[currNode]){
                  if(visited[j]==0){
                      q.push(j);
                  }
              }
              // }
          }
  
      }
      
      int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) {
          unordered_map<int, vector<int>> adj;
          vector<int> visited(V,0);
          int connected_comp = 0;
  
          for(int i=0; i<edges.size(); i++){
              if(adj.find(edges[i][0])==adj.end()) 
                  adj[edges[i][0]] = {edges[i][1]};
              else
                  adj[edges[i][0]].push_back(edges[i][1]);
  
              if(adj.find(edges[i][1])==adj.end()) 
                  adj[edges[i][1]] = {edges[i][0]};
              else
                  adj[edges[i][1]].push_back(edges[i][0]);
          }
  
          for(int i=0; i<V; i++){
              if(visited[i]==0){
                  connected_comp++;
                  BFSTraversal(i, edges, adj, visited);
              }
          }
  
          return connected_comp;
  
      }
  };