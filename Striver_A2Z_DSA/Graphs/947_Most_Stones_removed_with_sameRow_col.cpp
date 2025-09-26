
#include<bits/stdc++.h>
using namespace std;


class DisJointSet{
    public:
        vector<int> parent, size;
    
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) parent[i]=i;
        }
    
        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=findParent(parent[u]);
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
    
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            // row and col of the grid used for creating DisJointSet and nodes;
            int maxRow = 0, maxCol = 0; // direct index
            for(int s=0; s<stones.size(); s++){
                maxRow = max(maxRow, stones[s][0]);
                maxCol = max(maxCol, stones[s][1]);
            }
    
            DisJointSet djs(maxRow+maxCol+1);
            // now iterate over stones again and assume each row anc column as a nodes
            // row = nodes(0 to maxRow-1) number, col = row+1+col (MaxRow+1+col)
            set<int> nodes_with_stones;
            for(auto s : stones){
                int rowNode = s[0];
                int colNode = maxRow+1+s[1];
                djs.unionBySize(rowNode, colNode);
                nodes_with_stones.insert(rowNode);
                nodes_with_stones.insert(colNode);
            }
    
            // Iterate over all nodes and find unique parents/comp
            set<int> unique_comp;
            for(auto i: nodes_with_stones){
                unique_comp.insert(djs.findParent(i));
            }
            return stones.size()-unique_comp.size();
        }
    };