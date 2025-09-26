#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool DFS(int i, vector<int> adj[], vector<int> &visited, vector<int> &path, vector<int> &check){
    
            visited[i]=1;
            path[i]=1;
    
            for(int k: adj[i]){
                if(visited[k]==0){
                    if(DFS(k, adj, visited, path, check)) return true; //cycle exist
                }
                else if(path[k]==1){
                    // check[i]=0;
                    return true;//cycle exist
                }
            }
            path[i]=0;
            check[i] = 1;//no cycle for this node
            return false;
    
        }
    
        vector<int> BFS(int V, vector<vector<int>> &adj1){
    
            //reverse the edges;
            // adj 0 -> 12 3
            //  1->0
            //  2->0
            //  3->0
            // vector<int> adj[V];
            vector<vector<int>> adj(V);
            for(int i=0; i<V;i++){
                for(int k: adj1[i]){
                    adj[k].push_back(i);
                }
            }
    
            vector<int> indegree(V, 0), Topo;
    
            for(int i=0; i<V; i++){
                for(int k: adj[i]){
                    indegree[k]++;
                }
            }
    
            queue<int> q;
            for(int i=0; i<V; i++){
                if(indegree[i]==0) q.push(i);
            }
    
            while(!q.empty()){
                int currnode = q.front();q.pop();
               Topo.push_back(currnode);
    
                for(int k: adj[currnode]){
                    indegree[k]--;
                    if(indegree[k]==0) q.push(k);
                }
            }
    
            sort(Topo.begin(), Topo.end());
            return Topo;       
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            return BFS(graph.size(), graph);
    
            // vector<int> visited(V, 0), check(V, 0), path(V, 0);
            // for(int i=0; i<V; i++){
            //     if(visited[i]==0){
            //         DFS(i, adj, visited, path, check);
            //     }
            // }
    
            // vector<int> safenodes;
    
            // for(int i=0; i<V; i++){
            //     if(check[i]) safenodes.push_back(i);
            // }
    
            // return safenodes;
        }
    };