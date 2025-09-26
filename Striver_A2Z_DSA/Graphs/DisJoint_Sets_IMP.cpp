#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05

class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }
    
        bool find(int u, int v){
            return findParent(u) == findParent(v);
            // if(parent[u] =  u){
            //     return u;
            // }
            // return parent[u] = find(parent[u], v);
        }
    
        int findParent(int u) {
            if(parent[u] ==  u){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
    
        void unionByRank(int u, int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
    
            if(ulp_u == ulp_v) return;
    
            if(rank[ulp_u] < rank[ulp_v]){
                // u is attached to v
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                // v is attach ed to u
                parent[ulp_v] = ulp_u;
            }
            else{
                // v is attached to u
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
    
            if(ulp_u == ulp_v) return;
    
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_v];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    