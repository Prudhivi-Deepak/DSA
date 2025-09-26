#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool canQueenPlaced(int i, int j, vector<string> &grid){
    
            int n = grid.size();
            // check row of grid //check col side of grid
            int k=0;
            while(k<n){
                if(grid[i][k] == 'Q') return false;
                if(grid[k][j] == 'Q') return false;
                k++;
            }
    
            //check curr to left top and curr to bottom right
            int d1=i, d2=j;
            while(d1>=0 && d2>=0){
                if(grid[d1--][d2--]=='Q') return false;
            }
    
            d1=i, d2=j;
            while(d1<n && d2<n){
                if(grid[d1++][d2++]=='Q') return false;
            }
    
            d1=i, d2=j;
            while(d1<n && d2>=0){
                if(grid[d1++][d2--]=='Q') return false;
            }
    
            d1=i, d2=j;
            while(d1>=0 && d2<n){
                if(grid[d1--][d2++]=='Q') return false;
            }
            // cout << "true i : j : " << i << " : " << j << endl;
            return true;
        }
    
        void fillNQueens(int i, int n, vector<string> &grid, vector<vector<string>> &possible_grids){
    
            if(i == n){
                possible_grids.push_back(grid);return;
            }
    
            //try all possible j values
            for(int k=0; k<n; k++){
                if(canQueenPlaced(i, k, grid)){
                    grid[i][k] = 'Q';
                    fillNQueens(i+1, n, grid, possible_grids);
                    grid[i][k] = '.';
                }
            }        
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> possible_grids;
            vector<string> grid(n, string (n, '.'));
            fillNQueens(0, n, grid, possible_grids);
            if(possible_grids.size()==1 && possible_grids[0].size()==1){
                possible_grids[0][0] = "Q";
            }
            return possible_grids;
        }
    };