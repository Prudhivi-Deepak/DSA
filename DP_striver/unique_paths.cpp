
// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // int  f(int i, int j, vector<vector<int>>& dp){
        //     if(i<0 || j<0) return 0;
        //     if(i==0 && j==0) return 1;
        //     if(dp[i][j]!=-1) return dp[i][j];
        //     else{
        //         int left = f(i, j-1, dp);
        //         int up = f(i-1, j, dp);
        //         return dp[i][j] = (left + up);
        //     }
        // }
        int uniquePaths(int m, int n) {
            // vector<vector<int>> dp(m, vector<int>(n, -1));
            // int ans = f(m-1, n-1, dp);
            // vector<int> dp(n, -1); // i-1
            // for(int i=0; i<m; i++){
            //     vector<int> temp(n, -1); // i
            //     for(int j=0; j<n; j++){
            //         if(i==0 && j==0) temp[j] = 1;
            //         else{
            //             int left=0,up=0;
            //             if(j>0) left = temp[j-1];
            //             if(i>0) up = dp[j];
            //             temp[j] = (left + up);
            //         }
            //     }
            //     dp = temp;
            // }
            // return dp[n-1];
    
            long long ans=1;
            int r = min(m-1, n-1);
    
            for(int i=1; i<=r; i++){
                ans = ans * (m+n-i-1)/i;
            }
            return ans;
        }
    };