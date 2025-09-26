#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we can go to next row (i+1) either same col (j) or next col (j+1)
    int minimumPathSum(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i==triangle.size()-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int left = triangle[i][j] + minimumPathSum(i+1, j, triangle, dp);
        int right = triangle[i][j] + minimumPathSum(i+1, j+1, triangle, dp);

        return dp[i][j] = min(left, right);
    }

    // i goes from 0 to n-1]
    // j goes from 0 to j+1]
    //  base case - i=n-1 ---> dp[n-1][j] = triangle[n-1][j];
    // i=0 --> 1 [0]
    // i=1 --> 2 [0 1]
    // i=2 --> 3 [0 1 2]


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n+1, vector<int>(n, 0));
        vector<int> prev(n, 0), curr(n, 0);

        for(int j=0; j<triangle[n-1].size(); j++){
            // dp[n-1][j] = triangle[n-1][j];
            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                // int left  = triangle[i][j] + dp[i+1][j];
                // int right = triangle[i][j] + dp[i+1][j+1];

                int left  = triangle[i][j] + prev[j];
                int right = triangle[i][j] + prev[j+1];

                // dp[i][j] = min(left, right);
                curr[j] = min(left, right);
            }
            prev = curr;
        }

        return prev[0];
        // return minimumPathSum(0, 0, triangle, dp);
    }
};