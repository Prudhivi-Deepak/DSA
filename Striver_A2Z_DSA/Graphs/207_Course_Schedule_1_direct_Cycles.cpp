#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool DFS(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path){
           //to check cycle exixts or not
           visited[i] = 1; path[i]=1;
           for(int k : adj[i]){
                if(visited[k]==0){
                    if(DFS(k, adj, visited, path)) return true;//cycle there
                }
                else if(path[k]==1) return true;//cycle there
           }
           path[i]=0;
           return false;//no cycle
        }
    
        //find cycle exixts or not in directed graph
        bool BFS(int N, vector<vector<int>> adj){
            vector<int> indegree(N, 0);
            for(int i=0; i<N; i++){
                for(int k: adj[i]){
                    indegree[k]++;
                }
            }
    
            queue<int> q;
            vector<int> Topo;
            //push 0 indegree nodes
            for(int i=0; i<N; i++){
                if(indegree[i]==0) q.push(i);
            }
    
            while(!q.empty()){
                int currnode = q.front(); q.pop();
                Topo.push_back(currnode);
    
                for(int k: adj[currnode]){
                    indegree[k]--;
                    if(indegree[k]==0) q.push(k);
                }
    
            }
            return Topo.size()<N;//==N - no cycles - false, cycles - true
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int N = numCourses;
    
            vector<vector<int>> adj(N,vector<int>{});
    
            for(auto it : prerequisites) {
                adj[it[1]].push_back(it[0]);
            }
            
            vector<int> visited(N, 0), path(N,0);
            for(int i=0; i<N; i++){
                if(visited[i]==0)
                   if(DFS(i, adj, visited, path)) return false;
                //    if(BFS(N, adj)) return false;
            }
            return true;
        }
    };