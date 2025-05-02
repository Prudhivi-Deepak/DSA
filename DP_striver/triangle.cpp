#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/

class Solution {
    public:
        int f(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp){
            if(i==m-1) return dp[i][j] = triangle[i][j];
            else if(dp[i][j] != INT_MAX ) return dp[i][j];
            else{
                int down = INT_MAX, dia = INT_MAX;
                down = f(i+1, j, m, triangle, dp);
                dia = f(i+1, j+1, m, triangle, dp);
                return dp[i][j] = triangle[i][j] + min(down, dia);
            }
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            int n = triangle[m-1].size();
    
            // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    
            // vector<int> dp(n, INT_MAX);
            for(int i=m-2; i>=0; i--){
                // vector<int> temp(n, INT_MAX);
                for(int j=0; j<=i; j++){
                    // if(i==m-1) continue;
                    // else{
                        // int down = INT_MAX, dia = INT_MAX;
                        // down = triangle[i+1][j];
                        // (i+1, j, m, triangle, dp);
                        // dia = triangle[i+1][j+1];
                        // f(i+1, j+1, m, triangle, dp);
                        triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
                    // }
                }
                // dp = temp;
            }
    
            return triangle[0][0];
    
    
            //  vector<int> dp(n, INT_MAX);
            // for(int i=m-1; i>=0; i--){
            //     vector<int> temp(n, INT_MAX);
            //     for(int j=0; j<=i; j++){
            //         if(i==m-1) temp[j] = triangle[i][j];
            //         else{
            //             int down = INT_MAX, dia = INT_MAX;
            //             down = dp[j];
            //             // (i+1, j, m, triangle, dp);
            //             dia = dp[j+1];
            //             // f(i+1, j+1, m, triangle, dp);
            //             temp[j] = triangle[i][j] + min(down, dia);
            //         }
            //     }
            //     dp = temp;
            // }
    
            // return dp[0];
    
            // return f(0, 0, m, triangle, dp);
        }
    };