#include <bits/stdc++.h>
using namespace std;

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
    
        //Revision
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size(), n = triangle[m-1].size();
            int min_path = INT_MAX;
            // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
            vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
            // dp[0][0] = triangle[0][0];
            curr[0] = prev[0] = triangle[0][0];
    
            for(int i=1; i<m; i++){
                for(int j=n-1; j>=0; j--){
                    int up_left = (j>0 ? prev[j-1] : INT_MAX);
                    int up = (j<i) ? prev[j] : INT_MAX;
                    int mini = min(up_left, up);
                    if(mini != INT_MAX)
                        curr[j] = mini+triangle[i][j];
                    if(i==m-1){
                        min_path = min(min_path, curr[j]);
                    }
                    // int up_left = (j>0 ? dp[i-1][j-1] : INT_MAX);
                    // int up = (j<i) ? dp[i-1][j] : INT_MAX;
                    // int mini = min(up_left, up);
                    // if(mini != INT_MAX)
                    //     dp[i][j] = mini+triangle[i][j];
                    // if(i==m-1){
                    //     min_path = min(min_path, dp[i][j]);
                    // }
                }
                prev = curr;
            }
    
            if(min_path==INT_MAX){
                return triangle[0][0];
            }
    
            return min_path;
        }
        int minimumTotalfirstTry(vector<vector<int>>& triangle) {
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