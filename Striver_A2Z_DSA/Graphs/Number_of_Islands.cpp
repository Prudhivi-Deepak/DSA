#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void dfs(int i, int j, vector<vector<char>> &grid){
            grid[i][j] = '2';
            for(int x1=-1; x1<2; x1++){
                for(int x2=-1; x2<2; x2++){
                    if(i+x1>=0 && j+x2>=0 && i+x1 < grid.size() && j+x2 < grid[i].size() && grid[i+x1][j+x2]=='1'){
                        // cout << i << " : " << j << endl;
                        dfs(i+x1, j+x2, grid);
                    }
                }
            }
            
        }
        int numIslands(vector<vector<char>> &grid){
            int count=0;
    
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(grid[i][j]=='1'){
                        // cout << i << " - : " << j << endl;
                        count++;
                        dfs(i, j, grid);
                    }
                }
            }
    
            return count;
        }
    };
    