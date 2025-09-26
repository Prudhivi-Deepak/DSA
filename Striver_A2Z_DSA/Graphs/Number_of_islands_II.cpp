
#include<bits/stdc++.h>
using namespace std;


class DisJointSet{
    public:
        vector<int> parent, size;
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++)parent[i]=i;
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
            // take initial count as 0 and iterate over every A(edge)
            // Now for each edge(u) one time increment the count and check all 4 direction (v) 
            // if u and v are having same parent nothing changes
            // if they had different parents then connect them(unionBySize(u, v)) and decrement the count
            // for each edge add the count to a vector;
            DisJointSet djs(n*m);
    
            int count = 0;
            vector<int> Islands;
            vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}}, visited(n, vector<int>(m, 0));
            for(int i=0; i<A.size(); i++){
                int row = A[i][0], col = A[i][1], currNode = m*(row)+col;
                if(visited[row][col]){
                    Islands.push_back(count);
                    continue;
                }
                count++;
                visited[row][col] = 1;
                // for every direction
                for(int j=0; j<4; j++){
                    int adj_row = row+dir[j][0], adj_col = col+dir[j][1];
                    if(adj_row >=0 && adj_col>=0 && adj_row<n && adj_col<m && visited[adj_row][adj_col]==1){
                        int node = m*adj_row+adj_col;
                        // check if currNode and node belongs to same parent or not
                        if(djs.findParent(currNode)!=djs.findParent(node)){
                            djs.unionBySize(currNode, node);
                            count--;
                        }
                    }
                }
                Islands.push_back(count);
            }
            return Islands;
        }
    };