#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int f(int day, int pt, vector<vector<int>>& matrix, vector<vector<int>> &dp){
            // if(day < 0) {
            //     return 0;
            // }
            int max_p = INT_MIN;
    
            if(day == 0){
                for(int t=0; t<3; t++){
                    if(t!=pt){
                        max_p = max(max_p, matrix[day][t] );
                    }
                }
                return max_p;
            }
    
            if(dp[day][pt+1] != -1) return dp[day][pt+1];
    
            for(int t=0; t<3; t++){
                if(t!=pt){
                    max_p = max(max_p, matrix[day][t] + f(day-1, t, matrix, dp));
                }
            }
            return dp[day][pt+1] = max_p;
        }
        int ninjaTraining(vector<vector<int>>& matrix) {
            int n = matrix.size(), max_p = INT_MIN;
            vector<vector<int>> dp(n+2, vector<int>(4,-1));
    
            for(int day = 0; day<n; day++){
                for(int pt =0; pt<3; pt++){
                    max_p = INT_MIN;
                    for(int t=0; t<3; t++){
                        if(t!=pt){
                            max_p = max(max_p, matrix[day][t] + (day>0 ? dp[day-1][t] : 0));
                        }
                    }
                    dp[day][pt] = max_p;
                }
            }
    
            // return f(n-1, -1, matrix, dp);
    
            return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
        }
    };