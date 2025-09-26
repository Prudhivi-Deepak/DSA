#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(int i, int j, vector<vector<int>> &image){
            image[i][j] = 0;
    
            vector<pair<int, int>> directions = {{-1,0}, {0,1}, {0,-1},{1,0}};
            for(auto d:directions){
                if(i+d.first >=0 && j+d.second >=0 && i+d.first < image.size() && j+d.second < image[i].size() &&
                    image[i+d.first][j+d.second]==1){
                    dfs(i+d.first, j+d.second, image);
                }
            }
        }
        int numEnclaves(vector<vector<int>>& grid) {
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(i==0 || j==0 || i==grid.size()-1 || j==grid[i].size()-1){
                        if(grid[i][j]==1) dfs(i, j, grid);
                    }
                }
            }
            int count = 0;
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(grid[i][j]==1) count++;
                }
            }
            return count;
        }
    };