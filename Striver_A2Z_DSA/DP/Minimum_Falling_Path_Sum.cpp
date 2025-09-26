#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(i>=m || j>=n || i<0 || j<0) return 1e9;

        if(i==0) return matrix[i][j];

        if(dp[i][j]!=1e9) return dp[i][j];

        int top_left = f(i-1, j-1, m, n, matrix, dp) ;
        int top_value = f(i-1, j, m, n, matrix, dp);
        int top_right = f(i-1, j+1, m, n, matrix, dp);

        return dp[i][j] = min(min(top_left, top_value ), top_right)+matrix[i][j];
       
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));

        int min_path = 1e9;

        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
            // min_path = min(min_path, dp[0][j]);
        }

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int top_left = (j>0 ? dp[i-1][j-1] : 1e9);
                int top_right = (j+1<n ? dp[i-1][j+1] : 1e9);
                dp[i][j] = min(top_left, min(dp[i-1][j], top_right))+matrix[i][j];
                if(i==m-1){
                    min_path = min(min_path, dp[i][j]);
                }
            }
        }

        if(min_path == 1e9)
            for(int j=0; j<n; j++){
                min_path = min(min_path, dp[0][j]);
            }

        return min_path;
    }

    int minFallingPathSumMemo(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        int min_path = 1e9;

        for(int j=0; j<n; j++){
            min_path = min(min_path, f(m-1, j, m, n, matrix, dp));
        }

        return min_path;

    }
};