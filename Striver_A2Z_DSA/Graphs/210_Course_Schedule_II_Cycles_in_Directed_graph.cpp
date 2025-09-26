#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool DFS(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, vector<int> &unique_path){
            visited[i]=1; path[i]=1;
            for(int k : adj[i]){
                if(visited[k]==0){
                    // visited[k]=1;path[i]=1;
                    if(DFS(k, adj, visited, path, unique_path)) return true;
                    // path[k]=0;
                }
                else if(path[k]==1) {
                    return true;
                }
            }
            path[i]=0;
            unique_path.push_back(i);
            return false;
        }
    
        // bool BFS(int N, vector<int> adj[]){
        vector<int> BFS(int N, vector<vector<int>>& adj){
            vector<int> indegree(N, 0);
            for(int i=0; i<adj.size(); i++){
                for(int k : adj[i]){
                    indegree[k]++;
                }
            }
    
            vector<int> Topo;
            queue<int> q;
            for(int i=0; i<N; i++){
                if(indegree[i]==0) q.push(i);
            }
    
            while(!q.empty()){
                int currNode = q.front();q.pop();
                Topo.push_back(currNode);
    
                for(int k: adj[currNode]){
                    indegree[k]--;
                    if(indegree[k]==0) q.push(k);
                }
            }
    
            return Topo.size()==N ? Topo : vector<int>{};
        }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
            int N = numCourses;
    
            vector<vector<int>> adj(numCourses, vector<int>{});
    
            for(vector<int> k : prerequisites){
    
                adj[k[1]].push_back(k[0]);
            }
    
            // return BFS(numCourses, adj);
    
            vector<int> visited(N, 0), path(N, 0), unique_path;
            for(int i=0; i<N; i++){
                if(visited[i]==0){
                    // visited[i]=1;path[i]=1;
                    if(DFS(i, adj, visited, path, unique_path)) {
                        // break;
                        return vector<int>{};
                    }
                }
                // else if(path[i]==1) return true;
            }
    
            reverse(unique_path.begin(), unique_path.end());
            return unique_path.size()==N ? unique_path : vector<int>{};
            
        }
    };