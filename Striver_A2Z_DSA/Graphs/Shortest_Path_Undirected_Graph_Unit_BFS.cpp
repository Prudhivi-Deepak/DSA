#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      void BFS(vector<vector<int>>& adj, vector<int> &dist){
          queue<int> q;//node, dist
  
          q.push(0);//fist node
          dist[0]=0;
          while(!q.empty()){
              int node = q.front(); q.pop();
              for(int k: adj[node]){
                  if(dist[node]+1 < dist[k]){
                      dist[k] = dist[node]+1;
                      q.push(k);
                  }
              }
          }
      }
      vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
  
          vector<vector<int>> adj(N, vector<int>{});
          for(int e=0; e<edges.size(); e++){
              adj[edges[e][0]].push_back(edges[e][1]);
              adj[edges[e][1]].push_back(edges[e][0]);
          }
          vector<int> dist(N, 1e9);
          BFS(adj, dist);
          for(int i=0; i<N; i++){
              if(dist[i]==1e9) dist[i]=-1;
          }
          return dist;
      }
  };
  