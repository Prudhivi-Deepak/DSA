#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    public: 
        vector<int> parent, size;
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
        int solve(int n, vector<vector<int>> &Edge){
            // may be count no of componenets and count -1 is th eanswers?
            // also we need to take out th eextra edges then only its possible
            // so if there is dynamic edges we use disjopint sets
            // find extra edges using disJoinSets - if you found the edge (u, v ) point ting to same parent alreadys its an extra edge
            // n = 4, Edge =[ [0, 1], [ 0, 2], [1, 2]]
    
            DisJointSet djs(n);
            int extraEdge = 0;
    
            // Iterate through all edges and insert to the DisJoinSet and before insert check the parents of u and v equal or not?
            for(auto edge : Edge){
                int u = edge[0], v = edge[1];
                if(djs.findParent(u)==djs.findParent(v)) extraEdge++;
                else{
                    djs.unionBySize(u, v);
                }
            }
    
            // find the no.of components by counting no of parents[u]=u
            int totalComp = 0;
            for(int i=0; i<n; i++){
                if(djs.findParent(i)==i) totalComp++;
            }
    
            if(extraEdge >= totalComp-1) return totalComp-1;
            else return -1;
    
    
        }
    };
    