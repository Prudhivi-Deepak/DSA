#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int f(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
            if(i<0 || j1 <0 || j2 < 0|| i>=m || j1>=n || j2>=n ) return 0;
            if(j1 == j2) return dp[i][j1][j2] = grid[i][j1];
            if(dp[i][j1][j2] !=INT_MIN) return dp[i][j1][j2];
            else{
                int max_cherry = INT_MIN;
                for(int f1=-1; f1<2; f1++){
                    for(int f2=-1; f2<2; f2++){
                        max_cherry = max(max_cherry, f(i+1, j1+f1, j2+f2, m, n, grid, dp));
                    }
                }
                return dp[i][j1][j2] =  grid[i][j1] + grid[i][j2] + max_cherry;
            }
        }
    
        //revision
        int cherryPickup(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
    
            // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
            vector<vector<int>> prev(n, vector<int>(n, 0)), curr(n, vector<int>(n, 0));
    
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    if(j1==j2){
                        // dp[m-1][j1][j2] = grid[m-1][j1];
                        prev[j1][j2] = grid[m-1][j1];
                    }
                    else{
                        // dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                        prev[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                    }
                }
            }
    
            for(int i=m-2; i>=0; i--){
                for(int j1=0; j1<n; j1++){
                    for(int j2=n-1; j2>=0; j2--){
                        int max_ch = INT_MIN;
    
                        for(int d1=-1; d1<2; d1++){
                            for(int d2=-1; d2<2; d2++){
    
                                if(i+1<m && j1+d1 >=0 && j1+d1 < n && j2+d2 >=0 && j2+d2 < n)
                                    max_ch = max(max_ch, prev[j1+d1][j2+d2]);
                                    // max_ch = max(max_ch, dp[i+1][j1+d1][j2+d2]);
                            }
                        }
    
                        if(j1==j2){
                            curr[j1][j2] = max_ch + grid[i][j1];
                        }
                        else{
                            curr[j1][j2] = max_ch + grid[i][j1] + grid[i][j2];
                        }
    
                    }
                }
                prev = curr;
            }
            return prev[0][n-1];
        }
    
        int cherryPickupfirstTry(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
            vector<vector<int>> dp(n, vector<int>(n, 0));
            vector<vector<int>> temp(n, vector<int>(n, 0));
    
    
            // for(int j1=0; j1<n; j1++){
            //     for(int j2=0; j2<n; j2++){
            //         if(j1==j2){
            //             temp[j1][j2] =  grid[m-1][j1];
            //         }
            //         else{
            //             temp[j1][j2] =  grid[m-1][j1] + grid[m-1][j2];
            //         }
            //     }
            // }
            // dp = temp;
                        
    
    
            for(int i=m-1; i>=0; i--){
                for(int j1=0; j1<n; j1++){
                    for(int j2=0; j2<n; j2++){
                        if(i==m-1){
                            if(j1==j2){
                                temp[j1][j2] =  grid[i][j1];
                            }
                            else{
                                temp[j1][j2] =  grid[i][j1] + grid[i][j2];
                            }
                            continue;
                        }
                        int max_cherry = 0;
                        // for(int f1=-1; f1<2; f1++){
                            // for(int f2=-1; f2<2; f2++){
                        // -1, -1,0,1
                        //  0, -1,0,1
                        //  1, -1,0,1
                        // if(j1+f1 <0 || j2+f2 < 0|| j1+f1>=n || j2+f2>=n ) continue;
                        // else{
                        if(j1>0 && j2>0) max_cherry = max(max_cherry, dp[j1-1][j2-1]);
                        if(j1>0) max_cherry = max(max_cherry, dp[j1-1][j2]);
                        if(j1>0 && j2<n-1) max_cherry = max(max_cherry, dp[j1-1][j2+1]);
    
                        if(j2>0) max_cherry = max(max_cherry, dp[j1][j2-1]);
                        max_cherry = max(max_cherry, dp[j1][j2]);
                        if(j2<n-1) max_cherry = max(max_cherry, dp[j1][j2+1]);
    
                        if(j1<n-1 && j2>0) max_cherry = max(max_cherry, dp[j1+1][j2-1]);
                        if(j1<n-1) max_cherry = max(max_cherry, dp[j1+1][j2]);
                        if(j1<n-1 && j2<n-1) max_cherry = max(max_cherry, dp[j1+1][j2+1]);
    
                        // max_cherry = max(max_cherry, dp[j1+f1][j2+f2]);
                        // }
                                // (i+1, j1+f1, j2+f2, m, n, grid, dp));
                            // }
                        // }
                        if(j1==j2){
                            temp[j1][j2] =  grid[i][j2] + max_cherry;
                        }
                        else{
                            temp[j1][j2] =  grid[i][j1] + grid[i][j2] + max_cherry;
                        }
                    }
                }
                dp = temp;
            }
    
            return dp[0][n-1];
            // return f(0, 0, n-1, m, n, grid, dp);
        }
    };