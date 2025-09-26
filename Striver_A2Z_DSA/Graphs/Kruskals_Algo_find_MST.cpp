#include<bits/stdc++.h>
using namespace std;
// 
class DisJointSet{
    public:
        vector<int> size, parent;
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }
    
        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u] = findParent(parent[u]);
        }
    
        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
    
            if(ulp_u == ulp_v) return;
    
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    
    };
    
    class Solution{
        public:
        int spanningTree(int V, vector<vector<int>> adj[]) {
            // ((u1, v1, w1), (u1, v2, w2));
    
            // convert in edges of (wt, u, v)
    
            vector<pair<int, pair<int,int>>> edges;
    
            for(int i=0; i<V; i++){
                for(auto k : adj[i]){
                    int u = i;
                    int v = k[0];
                    int wt = k[1];
    
                    edges.push_back({wt, {u, v}});
                }
            }
    
            sort(edges.begin(), edges.end());
    
            DisJointSet djs(V);
            int sum = 0;
    
            for(int i=0; i<edges.size(); i++){
                int wt = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
                if(djs.findParent(u)!=djs.findParent(v)){ // not in same componenet then add it to the componenet
                    djs.unionBySize(u,v);
                    sum += wt;
                }
            }
            return sum;
        }
        int spanningTreePrims(int V, vector<vector<int>> adj[]) {
           
           priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    
           q.push({0,0}); // wt, node, parent(optional not asked in qns)
           vector<int> visited(V+1, 0);
           int sum = 0;
    
           while(!q.empty()){
                auto currNode = q.top(); q.pop();
                if(visited[currNode.second]==1) continue;
    
                //priority queue will return the smallest edge wt 
                // add it to the sum and mark as visited
                sum += currNode.first;
                visited[currNode.second] = 1;
                // now traverse all the adjacent nodes and add htem to PQ to get the smallest edge in the next round
                for(auto k : adj[currNode.second]){
                    if(visited[k[0]]==0){
                        q.push({k[1], k[0]});
                    }
                }
           }
           return sum;
        }
    };
    