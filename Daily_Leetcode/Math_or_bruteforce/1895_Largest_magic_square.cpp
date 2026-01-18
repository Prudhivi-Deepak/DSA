#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int,int>> checkRowColSum(vector<vector<int>>& grid, int i, int j, int m, int n){
        int rowSum = grid[i][j], colSum = grid[i][j];
        int ind = 1;
        vector<pair<int,int>> valid; // {sideLen, sum}

        while(i+ind < m && j+ind < n){
            rowSum += grid[i+ind][j];
            colSum += grid[i][j+ind];

            if(rowSum == colSum){
                valid.push_back({ind, rowSum});
            }
            ind++;
        }
        return valid;
    }

    bool checkDiag(int currSideLen, int rowSum, vector<vector<int>>& grid, int i, int j){
        int diagSum = 0;
        for(int k = 0; k <= currSideLen; k++){
            diagSum += grid[i+k][j+k];
        }
        return diagSum == rowSum;
    }

    bool checkWholeSquare(int currSideLen, int rowSum, vector<vector<int>>& grid, int i, int j){
        // check second diagonal
        int diagSum = 0;
        for(int k = 0; k <= currSideLen; k++){
            diagSum += grid[i+k][j+currSideLen-k];
        }
        if(diagSum != rowSum) return false;

        // check all rows
        for(int r = i; r <= i + currSideLen; r++){
            int sum = 0;
            for(int c = j; c <= j + currSideLen; c++){
                sum += grid[r][c];
            }
            if(sum != rowSum) return false;
        }

        // check all columns
        for(int c = j; c <= j + currSideLen; c++){
            int sum = 0;
            for(int r = i; r <= i + currSideLen; r++){
                sum += grid[r][c];
            }
            if(sum != rowSum) return false;
        }

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxSideLen = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                auto candidates = checkRowColSum(grid, i, j, m, n);

                // try larger squares first
                for(int k = candidates.size() - 1; k >= 0; k--){
                    int currSideLen = candidates[k].first;
                    int rowSum = candidates[k].second;

                    if(currSideLen <= maxSideLen) continue;

                    if(checkDiag(currSideLen, rowSum, grid, i, j) &&
                       checkWholeSquare(currSideLen, rowSum, grid, i, j)){
                        maxSideLen = currSideLen;
                        break; // no need to check smaller ones
                    }
                }
            }
        }
        return maxSideLen + 1;
    }
};