
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int BFS(vector<vector<int>> &grid, queue<pair<int, int>> &q){
            // queue<pair<int, int>> q;
            // q.push({i,j});
            // grid[i][j] = 3;
            int count = 0;
    
            while(!q.empty()){
                count++;
                int size = q.size();
                for(int k=0; k<size; k++){
                    auto[c_i, c_j] = q.front(); q.pop();
                    //up 
                    if(c_i-1>=0 && grid[c_i-1][c_j]==1){
                        q.push({c_i-1, c_j});
                        grid[c_i-1][c_j] = 3;
                    }
                    //down
                    if(c_i+1<grid.size() && grid[c_i+1][c_j]==1){
                        q.push({c_i+1, c_j});
                        grid[c_i+1][c_j] = 3;
                    }
                    //left
                    if(c_j-1>=0 && grid[c_i][c_j-1]==1){
                        q.push({c_i, c_j-1});
                        grid[c_i][c_j-1] = 3;
                    }
                    //right
                    if(c_j+1<grid[c_i].size() && grid[c_i][c_j+1]==1){
                        q.push({c_i, c_j+1});
                        grid[c_i][c_j+1] = 3;
                    }
                }
            }
            return count;
        }
        int orangesRotting(vector<vector<int>>& grid) {
             int count = 0;
            queue<pair<int,int>> q;
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(grid[i][j]==2){
                        q.push({i,j});
                        grid[i][j]=3;
                        // count += BFS(i, j, grid);
                    }
                }
           }
    
           count = BFS(grid, q);
    
           for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(grid[i][j]==1){
                        return -1;
                    }
                }
           }
    
           return count==0 ? count : count-1;
        }
    };