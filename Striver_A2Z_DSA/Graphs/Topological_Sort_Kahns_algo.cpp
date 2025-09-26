#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void DFS(int i, vector<int> adj[], vector<int> &visited, stack<int> &st){
    
            for(int k: adj[i]){
                if(visited[k]==0){
                    visited[k]=1;
                    DFS(k, adj, visited, st);
                }
            }
    
            st.push(i);
        }
    
        void BFS(int V, vector<int> adj[], vector<int> &indegree, vector<int> &Topo){
            queue<int> q;
    
            //find indegree with 0
            for(int i=0; i<V; i++){
                if(indegree[i]==0) q.push(i);
            }
    
            while(!q.empty()){
                int currnode = q.front(); q.pop();
                Topo.push_back(currnode);
                for(int k : adj[currnode]){
                    indegree[k]--;
                    if(indegree[k]==0) q.push(k);
                }
            }
        }
    
    
        vector<int> topoSort(int V, vector<int> adj[]){
    
            vector<int> indegree(V,0);
    
            for(int i=0; i<V; i++){
                for(int k : adj[i]){
                    indegree[k]++;
                }
            }
    
            vector<int> Topo;
            BFS(V, adj, indegree, Topo);
            // for(int i: Topo){
            //     cout << i << " ";
            // }
    
            return Topo;
    
            // vector<int> visited(V, 0);
            // stack<int> st;
            // for(int i=0; i<V; i++){
            //     if(visited[i]==0){
            //         visited[i]=1;
            //         DFS(i, adj, visited, st);
            //     }
            // }
            // vector<int> Topo;
            // while(!st.empty()){
            //     Topo.push_back(st.top()); st.pop();
            // }
            // return Topo;
        }
    };
    