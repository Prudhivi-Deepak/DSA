
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
        int largestIsland(vector<vector<int>>& grid) {
            // Iterate over all cells and unionBySize using DisJointSet
            // chek all 4 directions
            int n = grid.size(), max_size = 0;
            vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}}, visited(n, vector<int>(n, 0));
            DisJointSet djs(n*n);
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j]==1){
                       //now check directions for each cell and if it valid union it
                       for(int d=0; d<4; d++){
                            int adj_row = i+dir[d][0], adj_col = j+dir[d][1];
                            if(adj_row >=0 && adj_col>=0 && adj_row<n && adj_col<n && grid[adj_row][adj_col]==1){
                                int u = n*i+j, v = n*adj_row+adj_col;
                                djs.unionBySize(u, v);
                            }
                       }
                    }
                }
            }
    
            //now we have all the compoenents and their ulp and sizes of all components
            // Now iterate through all cells and make 0 to 1 (mock) and get the Ultimate parents of all 4 directions in a set and get eh size
            bool hasZero = false;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    set<int> unique_ulp;
                    if(grid[i][j]==0){
                        hasZero = true;
                        for(int d=0; d<4; d++){
                            int adj_row = i+dir[d][0], adj_col = j+dir[d][1];
                            if(adj_row >=0 && adj_col>=0 && adj_row<n && adj_col<n && grid[adj_row][adj_col]==1){
                                int v = n*adj_row+adj_col;
                                unique_ulp.insert(djs.findParent(v));                            
                            }
                       }
                    }
                    int sum = 1;
                    for(int ulp : unique_ulp){
                        sum+=djs.size[ulp];
                    }
                    max_size = max(max_size, sum);
                }
            }
    
            if(!hasZero) return n*n;
    
            return max_size;
        }
    };