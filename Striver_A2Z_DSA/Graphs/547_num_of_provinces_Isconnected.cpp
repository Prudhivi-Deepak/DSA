#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void BFSTraversal(int i, vector<vector<int>> adj, vector<int> &visited){
            queue<int> q;
            q.push(i);
            visited[i] = 1;
    
            while(!q.empty()){
                int currNode = q.front(); q.pop();
                for(int k = 0; k<adj[currNode].size(); k++){
                    if(adj[currNode][k]==1 && visited[k]==0) {
                        visited[k] = 1;
                        q.push(k);
                    }
                }
            }
        }
    
        void dfs(int i, vector<vector<int>> adj, vector<int> &visited){
            visited[i] = 1;
            for(int k = 0; k<adj[i].size(); k++){
                if(adj[i][k]==1 && visited[k]==0) dfs(k, adj, visited);
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            int count = 0;
            vector<int> visited(isConnected.size(), 0);
            for(int i=0; i<isConnected.size(); i++){
                if(visited[i]==0) {
                    count++;
                    dfs(i, isConnected, visited);
                }
            }
            return count;
        }
    };