#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void BFS(vector<vector<int>> grid, queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &visited, vector<vector<int>> &dist){
    
            while(!q.empty()){
                int size = q.size();
    
                for(int k=0; k<size; k++){
                    pair<pair<int,int>, int> currnode = q.front(); q.pop();
    
                    int c_i = currnode.first.first;
                    int c_j = currnode.first.second;
    
                    dist[c_i][c_j] = currnode.second;
                    //up 
                    if(c_i-1>=0 && visited[c_i-1][c_j]==0){
                        visited[c_i-1][c_j] = 1;
                        q.push({{c_i-1, c_j},currnode.second+1});
                    }
                    //down
                    if(c_i+1<grid.size() && visited[c_i+1][c_j]==0){
                        visited[c_i+1][c_j] = 1;
                        q.push({{c_i+1, c_j}, currnode.second+1});
                    }
                    //left
                    if(c_j-1>=0 && visited[c_i][c_j-1]==0){
                        visited[c_i][c_j-1] = 1;
                        q.push({{c_i, c_j-1},currnode.second+1});
                    }
                    //right
                    if(c_j+1 < grid[c_i].size() && visited[c_i][c_j+1]==0){
                        visited[c_i][c_j+1] = 1;
                        q.push({{c_i, c_j+1},currnode.second+1});
                    }
                }
            }
        }
    
        vector<vector<int>> nearest(vector<vector<int>> grid){
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> visited(n, vector<int>(m, 0));
            vector<vector<int>> dist(n,vector<int>(m, 0));
            
            queue<pair<pair<int, int>, int>> q;
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    if(grid[i][j]==1){
                        visited[i][j] = 1;
                        q.push({{i,j}, 0});
                    }
                }
            }
            BFS(grid, q, visited, dist);
    
            return dist;
        }
    };