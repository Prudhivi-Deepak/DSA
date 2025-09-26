#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            if(grid[0][0]==1) return -1;
            vector<pair<int,int>> adj = {{-1,0}, {0,1}, {1,0}, {0,-1},  {-1,-1}, {1,1}, {-1,1}, {1,-1}};
            queue<pair<int, pair<int,int>>> q;
            q.push({0, {0,0}});
            vector<vector<int>> grid_visited(grid.size()+1, vector<int>(grid[0].size()+1, 0));
            grid_visited[0][0] = 1;
    
            while(!q.empty()){
                    auto [dist, pr] = q.front(); q.pop();
                    int row = pr.first, col = pr.second;
                    if(row == grid.size()-1 && col == grid.size()-1) return dist+1;
    
                    for(auto p : adj){
                        int nextRow = row+p.first, nextCol = col+p.second;
    
                        if(nextRow >=0 && nextRow < grid.size() && nextCol >=0 && nextCol<grid[row].size() && grid[nextRow][nextCol] == 0 && grid_visited[nextRow][nextCol] == 0){
                            grid_visited[nextRow][nextCol] = 1;
                            q.push({dist+1, {nextRow, nextCol}});
                        }
                    }
            }
            return -1;
        }
    };