// #include<bits/stdc++.h>

// using namespace std;

class Solution
{
public:
    vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int,int>> &islandPair, int pi, int pj){

        visited[i][j] = 1;
        islandPair.push_back({pi-i, pj-j});

        int n = grid.size(), m = grid[0].size();

        for(auto d: dir){
            int n_i = i+d.first, n_j = j+d.second;

            if(n_i>=0 && n_j>=0 && n_i<n && n_j<m &&
                grid[n_i][n_j]==1 && visited[n_i][n_j]==0){
                    dfs(n_i, n_j, grid, visited, islandPair, pi, pj);
                }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid){

        // unordered_
        set<vector<pair<int,int>>> islandSet;
        // vector<pair<int,int>> &islandPair;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    vector<pair<int,int>> islandPair;
                    dfs(i, j, grid, visited, islandPair, i, j);
                    islandSet.insert(islandPair);
                }
            }
        }
        return islandSet.size();        
    }
};
