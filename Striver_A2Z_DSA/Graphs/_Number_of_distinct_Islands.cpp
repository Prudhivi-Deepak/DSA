#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void BFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, set<vector<pair<int,int>>> &pathSets){

        vector<pair<int,int>> path;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        while(!q.empty()){
            auto [c_i, c_j] = q.front(); q.pop();
            path.push_back({c_i-i,c_j-j});

            //up 
            if(c_i-1>=0 && visited[c_i-1][c_j]==0 && grid[c_i-1][c_j]==1){
                visited[c_i-1][c_j] = 1;
                q.push({c_i-1, c_j});
            }
            //down
            if(c_i+1<grid.size() && visited[c_i+1][c_j]==0 && grid[c_i+1][c_j]==1){
                visited[c_i+1][c_j] = 1;
                q.push({c_i+1, c_j});
            }
            //left
            if(c_j-1>=0 && visited[c_i][c_j-1]==0 && grid[c_i][c_j-1]==1){
                visited[c_i][c_j-1] = 1;
                q.push({c_i, c_j-1});
            }
            //right
            if(c_j+1 < grid[c_i].size() && visited[c_i][c_j+1]==0 && grid[c_i][c_j+1]==1){
                visited[c_i][c_j+1] = 1;
                q.push({c_i, c_j+1});
            }
        }
        pathSets.insert(path);
    }

    int countDistinctIslands(vector<vector<int>> &grid){
        
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>> pathSets;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0) {
                    BFS(i, j, grid, visited, pathSets);
                }
            }
        }
        return pathSets.size();
    }
};
